--- src/filter/pfswb.cpp.orig	2016-02-12 17:10:27 UTC
+++ src/filter/pfswb.cpp
@@ -0,0 +1,297 @@
+/**
+ * @file pfswb.cpp
+ * @brief Adjust white balance in RGB color space
+ *
+ * This file is a part of PFSTOOLS package.
+ * ---------------------------------------------------------------------- 
+ * Copyright (C) 2008 Iouri V. Ivliev
+ * 
+ *  This program is free software; you can redistribute it and/or modify
+ *  it under the terms of the GNU General Public License as published by
+ *  the Free Software Foundation; either version 2 of the License, or
+ *  (at your option) any later version.
+ *
+ *  This program is distributed in the hope that it will be useful,
+ *  but WITHOUT ANY WARRANTY; without even the implied warranty of
+ *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ *  GNU General Public License for more details.
+ *
+ *  You should have received a copy of the GNU General Public License
+ *  along with this program; if not, write to the Free Software
+ *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
+ * ---------------------------------------------------------------------- 
+ * 
+ * @author Iouri V. Ivliev <ii@any.com.ru>
+ *
+ * $Id: $
+ */
+
+#include <config.h>
+
+#include <exception>
+#include <iostream>
+#include <sys/limits.h>
+#include <stdlib.h>
+#include <getopt.h>
+
+#include <pfs.h>
+
+#define PROG_NAME "pfswb"
+
+class QuietException 
+{
+};
+
+static void printHelp()
+{
+  std::cerr << PROG_NAME " (" PACKAGE_STRING ") :\n" 
+    "\t[--red <val>] [--green <val>] [--blue <val>]\n"
+    "\t[--auto] [--x <val>] [--y <val>] [--width <val>] [--height <val>]\n"
+    "\t[--keep-lum]\n"
+    "\t[--verbose] [--help]\n"
+    "See man page for more information.\n";
+}
+
+// verbose mode
+static bool verbose = false;
+
+// auto WB
+static bool autowb = false;
+// default gray box bounds
+static int x = 0;
+static int y = 0;
+static int width = INT_MAX/2;
+static int height = INT_MAX/2;
+
+// keep original luminance
+static bool keep = false;
+
+// default WB multipliers
+static float red = 1.f;
+static float green = 1.f;
+static float blue = 1.f;
+
+static void multipliers(
+    const pfs::Array2D &R, const pfs::Array2D &G, const pfs::Array2D &B, 
+    float &r, float &g, float &b)
+{
+  r = red;
+  g = green;
+  b = blue;
+  if (!autowb) return;
+  // auto WB gray box
+  int w = R.getCols();
+  int h = R.getRows();
+  if (x>=w || y>=h)
+    throw pfs::Exception("gray box is out of frame bounds");
+  int x1 = width+x;
+  if (x1>w) x1 = w;
+  int y1 = height+y;
+  if (y1>h) y1 = h;
+  VERBOSE_STR 
+    << "auto WB gray box: " 
+    << (x1-x) << "x" << (y1-y) << "+" << x << "+" << y << std::endl;
+  // auto WB multipliers
+  double ar = 0.;
+  double ag = 0.;
+  double ab = 0.;
+  for (int y0=y; y0<y1; ++y0)
+  {
+    for (int x0=x; x0<x1; ++x0)
+    {
+      ar += R(x0,y0);
+      ag += G(x0,y0);
+      ab += B(x0,y0);
+    }
+  }
+  int n = (x1-x)*(y1-y);
+  ar /= n;
+  ag /= n;
+  ab /= n;
+  VERBOSE_STR << "average red value: " << ar << std::endl;
+  VERBOSE_STR << "average green value: " << ag << std::endl;
+  VERBOSE_STR << "average blue value: " << ab << std::endl;
+  float a = (float)((ar+ag+ab)/3.);
+  r *= a/ar;
+  g *= a/ag;
+  b *= a/ab;
+}
+
+static void pfswb()
+{
+  pfs::DOMIO pfsio;
+  VERBOSE_STR << "auto WB: " << (autowb ? "yes" : "no" ) << std::endl;
+  VERBOSE_STR << "base red multiplier value: " << red << std::endl;
+  VERBOSE_STR << "base green multiplier value: " << green << std::endl;
+  VERBOSE_STR << "base blue multiplier value: " << blue << std::endl;
+  VERBOSE_STR << "keep original luminance: " << (keep ? "yes" : "no" ) << std::endl;
+  while (true) 
+  {
+    // Read frame
+    pfs::Frame *frame = pfsio.readFrame( stdin );
+    if (!frame)
+    {
+      break; // No more frames
+    }
+    // Get channels
+    pfs::Channel *X, *Y, *Z;
+    frame->getXYZChannels(X, Y, Z);
+    if (!(Y && X && Z))
+    {
+      throw pfs::Exception( "Missing X, Y, Z channels in the PFS stream" );
+    }
+    int w = Y->getCols();
+    int h = Y->getRows();
+    int s = w*h;
+    float min = 1e20, max = -1e20;
+    for (int i=s; i--; )
+    {
+      float const &l = (*Y)(i);
+      if (min > l) min = l;
+      if (max < l) max = l;
+    }
+    VERBOSE_STR << "luminance range of original frame: " << min << ":" << max << std::endl;
+    // Convert from XYZ to RGB
+    pfs::transformColorSpace(pfs::CS_XYZ, X, Y, Z, pfs::CS_RGB, X, Y, Z);
+    // WB adjustment
+    float r, g, b;
+    multipliers(*X,*Y,*Z,r,g,b);
+    VERBOSE_STR << "red multiplier value: " << r << std::endl;
+    VERBOSE_STR << "green multiplier value: " << g << std::endl;
+    VERBOSE_STR << "blue multiplier value: " << b << std::endl;
+    for (int i=s; i--; )
+    {
+      (*X)(i) *= r;
+      (*Y)(i) *= g;
+      (*Z)(i) *= b;
+    }
+    // Convert back to XYZ
+    pfs::transformColorSpace(pfs::CS_RGB, X, Y, Z, pfs::CS_XYZ, X, Y, Z);
+    float amin = 1e20, amax = -1e20;
+    for (int i=s; i--; )
+    {
+      float const &l = (*Y)(i);
+      if (amin > l) amin = l;
+      if (amax < l) amax = l;
+    }
+    VERBOSE_STR << "luminance range of adjusted frame: " << amin << ":" << amax << std::endl;
+    if (keep)
+    {
+      float k = (max-min)/(amax-amin);
+      float nmin = 1e20, nmax = -1e20;
+      for (int i=s; i--; )
+      {
+        float const &l = ((*Y)(i)-amin)*k+min;
+        if (nmin > l) nmin = l;
+        if (nmax < l) nmax = l;
+        (*Y)(i) = l;
+      }
+      VERBOSE_STR << "restored luminance range: " << nmin << ":" << nmax << std::endl;
+    }
+    // Write frame
+    pfsio.writeFrame(frame, stdout);
+    pfsio.freeFrame(frame);        
+  }
+}
+
+int main(int argc, char *const argv[])
+{
+  static const struct option cmdLineOptions[] = {
+    { "help", no_argument, NULL, 'h' },
+    { "verbose", no_argument, NULL, 'v' },
+    { "auto", no_argument, NULL, 'A' },
+    { "x", required_argument, NULL, 'X' },
+    { "y", required_argument, NULL, 'Y' },
+    { "width", required_argument, NULL, 'W' },
+    { "height", required_argument, NULL, 'H' },
+    { "keep-lum", no_argument, NULL, 'k' },
+    { "red", required_argument, NULL, 'r' },
+    { "green", required_argument, NULL, 'g' },
+    { "blue", required_argument, NULL, 'b' },
+    { NULL, 0, NULL, 0 }
+  };
+
+  try
+  {
+    int optionIndex = 0;
+    while (true)
+    {
+      int c = getopt_long(argc, argv, "hvAX:Y:W:H:kr:g:b:", cmdLineOptions, &optionIndex);
+      if (c == -1)
+      {
+        break;
+      }
+      switch (c)
+      {
+      case 'h':
+        printHelp();
+        throw QuietException();
+      case 'v':
+        verbose = true;
+        break;
+      case 'A':
+        autowb = true;
+        break;
+      case 'X':
+        x = (int)strtol(optarg, NULL, 10);
+        if (x<=0)
+          throw pfs::Exception("gray box x value out of range, should be >0");
+      break;
+      case 'Y':
+        y = (int)strtol(optarg, NULL, 10);
+        if (y<=0)
+          throw pfs::Exception("gray box y value out of range, should be >0");
+        break;
+      case 'W':
+        width = (int)strtol(optarg, NULL, 10);
+        if (width<=0)
+          throw pfs::Exception("gray box width value out of range, should be >0");
+        break;
+      case 'H':
+      height = (int)strtol(optarg, NULL, 10);
+        if (height<=0)
+          throw pfs::Exception("gray box height value out of range, should be >0");
+        break;
+      case 'k':
+        keep = true;
+        break;
+      case 'r':
+        red = strtof(optarg, NULL);
+        if (red<=0.0f)
+        throw pfs::Exception("red multiplier value out of range, should be >0");
+        break;
+      case 'g':
+        green = strtof(optarg, NULL);
+        if (green<=0.0f)
+          throw pfs::Exception("green multiplier value out of range, should be >0");
+        break;
+      case 'b':
+        blue = strtof(optarg, NULL);
+        if (blue<=0.0f)
+        throw pfs::Exception("blue multiplier value out of range, should be >0");
+        break;
+      case '?':
+        throw QuietException();
+      case ':':
+        throw QuietException();
+      }
+    }
+
+    pfswb();
+  }
+  catch (std::exception ex)
+  {
+    std::cerr << PROG_NAME" std error: " << ex.what() << std::endl;
+    return EXIT_FAILURE;
+  }        
+  catch (pfs::Exception ex)
+  {
+    std::cerr << PROG_NAME" error: " << ex.getMessage() << std::endl;
+    return EXIT_FAILURE;
+  }        
+  catch (QuietException ex)
+  {
+    return EXIT_FAILURE;
+  }        
+  return EXIT_SUCCESS;
+}
