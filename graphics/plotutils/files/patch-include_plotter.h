
$FreeBSD$

--- include/plotter.h.orig	Wed Jun 28 06:21:36 2000
+++ include/plotter.h	Thu Aug  7 11:48:12 2003
@@ -58,8 +58,8 @@
 /* Include iostream, stdio support if this is libplotter rather than
    libplot. */
 #ifndef NOT_LIBPLOTTER
-#include <iostream.h>
-#include <stdio.h>
+#include <iostream>
+#include <cstdio>
 #endif
 
 /* THE GLOBAL VARIABLES IN GNU LIBPLOTTER */
@@ -680,9 +680,9 @@
   FILE *outfp;			/* stdio-style output stream if any */
   FILE *errfp;			/* stdio-style error stream if any */
 #ifndef NOT_LIBPLOTTER
-  istream *instream;		/* C++-style input stream if any */
-  ostream *outstream;		/* C++-style output stream if any */
-  ostream *errstream;		/* C++-style error stream if any */
+  std::istream *instream;	/* C++-style input stream if any */
+  std::ostream *outstream;	/* C++-style output stream if any */
+  std::ostream *errstream;	/* C++-style error stream if any */
 #endif /* not NOT_LIBPLOTTER */
 
   /* device driver parameters (i.e., instance copies of class variables) */
@@ -898,14 +898,15 @@
   /* PLOTTER CTORS (old-style, not thread-safe) */
   Plotter (FILE *infile, FILE *outfile, FILE *errfile);
   Plotter (FILE *outfile);
-  Plotter (istream& in, ostream& out, ostream& err);
-  Plotter (ostream& out);
+  Plotter (std::istream& in, std::ostream& out, std::ostream& err);
+  Plotter (std::ostream& out);
   Plotter ();
   /* PLOTTER CTORS (new-style, thread-safe) */
   Plotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   Plotter (FILE *outfile, PlotterParams &params);
-  Plotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  Plotter (ostream& out, PlotterParams &params);
+  Plotter (std::istream& in, std::ostream& out, std::ostream& err, 
+	   PlotterParams &params);
+  Plotter (std::ostream& out, PlotterParams &params);
   Plotter (PlotterParams &params);
   /* PLOTTER DTOR */
   virtual ~Plotter ();
@@ -1487,14 +1488,14 @@
   /* ctors (old-style, not thread-safe) */
   MetaPlotter (FILE *infile, FILE *outfile, FILE *errfile);
   MetaPlotter (FILE *outfile);
-  MetaPlotter (istream& in, ostream& out, ostream& err);
-  MetaPlotter (ostream& out);
+  MetaPlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  MetaPlotter (std::ostream& out);
   MetaPlotter ();
   /* ctors (new-style, thread-safe) */
   MetaPlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   MetaPlotter (FILE *outfile, PlotterParams &params);
-  MetaPlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  MetaPlotter (ostream& out, PlotterParams &params);
+  MetaPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  MetaPlotter (std::ostream& out, PlotterParams &params);
   MetaPlotter (PlotterParams &params);
   /* dtor */
   virtual ~MetaPlotter ();
@@ -1566,14 +1567,14 @@
   /* ctors (old-style, not thread-safe) */
   BitmapPlotter (FILE *infile, FILE *outfile, FILE *errfile);
   BitmapPlotter (FILE *outfile);
-  BitmapPlotter (istream& in, ostream& out, ostream& err);
-  BitmapPlotter (ostream& out);
+  BitmapPlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  BitmapPlotter (std::ostream& out);
   BitmapPlotter ();
   /* ctors (new-style, thread-safe) */
   BitmapPlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   BitmapPlotter (FILE *outfile, PlotterParams &params);
-  BitmapPlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  BitmapPlotter (ostream& out, PlotterParams &params);
+  BitmapPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  BitmapPlotter (std::ostream& out, PlotterParams &params);
   BitmapPlotter (PlotterParams &params);
   /* dtor */
   virtual ~BitmapPlotter ();
@@ -1613,14 +1614,14 @@
   /* ctors (old-style, not thread-safe) */
   TekPlotter (FILE *infile, FILE *outfile, FILE *errfile);
   TekPlotter (FILE *outfile);
-  TekPlotter (istream& in, ostream& out, ostream& err);
-  TekPlotter (ostream& out);
+  TekPlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  TekPlotter (std::ostream& out);
   TekPlotter ();
   /* ctors (new-style, thread-safe) */
   TekPlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   TekPlotter (FILE *outfile, PlotterParams &params);
-  TekPlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  TekPlotter (ostream& out, PlotterParams &params);
+  TekPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  TekPlotter (std::ostream& out, PlotterParams &params);
   TekPlotter (PlotterParams &params);
   /* dtor */
   virtual ~TekPlotter ();
@@ -1665,14 +1666,14 @@
   /* ctors (old-style, not thread-safe) */
   ReGISPlotter (FILE *infile, FILE *outfile, FILE *errfile);
   ReGISPlotter (FILE *outfile);
-  ReGISPlotter (istream& in, ostream& out, ostream& err);
-  ReGISPlotter (ostream& out);
+  ReGISPlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  ReGISPlotter (std::ostream& out);
   ReGISPlotter ();
   /* ctors (new-style, thread-safe) */
   ReGISPlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   ReGISPlotter (FILE *outfile, PlotterParams &params);
-  ReGISPlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  ReGISPlotter (ostream& out, PlotterParams &params);
+  ReGISPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  ReGISPlotter (std::ostream& out, PlotterParams &params);
   ReGISPlotter (PlotterParams &params);
   /* dtor */
   virtual ~ReGISPlotter ();
@@ -1716,14 +1717,14 @@
   /* ctors (old-style, not thread-safe) */
   HPGLPlotter (FILE *infile, FILE *outfile, FILE *errfile);
   HPGLPlotter (FILE *outfile);
-  HPGLPlotter (istream& in, ostream& out, ostream& err);
-  HPGLPlotter (ostream& out);
+  HPGLPlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  HPGLPlotter (std::ostream& out);
   HPGLPlotter ();
   /* ctors (new-style, thread-safe) */
   HPGLPlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   HPGLPlotter (FILE *outfile, PlotterParams &params);
-  HPGLPlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  HPGLPlotter (ostream& out, PlotterParams &params);
+  HPGLPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  HPGLPlotter (std::ostream& out, PlotterParams &params);
   HPGLPlotter (PlotterParams &params);
   /* dtor */
   virtual ~HPGLPlotter ();
@@ -1812,14 +1813,14 @@
   /* ctors (old-style, not thread-safe) */
   PCLPlotter (FILE *infile, FILE *outfile, FILE *errfile);
   PCLPlotter (FILE *outfile);
-  PCLPlotter (istream& in, ostream& out, ostream& err);
-  PCLPlotter (ostream& out);
+  PCLPlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  PCLPlotter (std::ostream& out);
   PCLPlotter ();
   /* ctors (new-style, thread-safe) */
   PCLPlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   PCLPlotter (FILE *outfile, PlotterParams &params);
-  PCLPlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  PCLPlotter (ostream& out, PlotterParams &params);
+  PCLPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  PCLPlotter (std::ostream& out, PlotterParams &params);
   PCLPlotter (PlotterParams &params);
   /* dtor */
   virtual ~PCLPlotter ();
@@ -1843,14 +1844,14 @@
   /* ctors (old-style, not thread-safe) */
   FigPlotter (FILE *infile, FILE *outfile, FILE *errfile);
   FigPlotter (FILE *outfile);
-  FigPlotter (istream& in, ostream& out, ostream& err);
-  FigPlotter (ostream& out);
+  FigPlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  FigPlotter (std::ostream& out);
   FigPlotter ();
   /* ctors (new-style, thread-safe) */
   FigPlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   FigPlotter (FILE *outfile, PlotterParams &params);
-  FigPlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  FigPlotter (ostream& out, PlotterParams &params);
+  FigPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  FigPlotter (std::ostream& out, PlotterParams &params);
   FigPlotter (PlotterParams &params);
   /* dtor */
   virtual ~FigPlotter ();
@@ -1893,14 +1894,14 @@
   /* ctors (old-style, not thread-safe) */
   CGMPlotter (FILE *infile, FILE *outfile, FILE *errfile);
   CGMPlotter (FILE *outfile);
-  CGMPlotter (istream& in, ostream& out, ostream& err);
-  CGMPlotter (ostream& out);
+  CGMPlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  CGMPlotter (std::ostream& out);
   CGMPlotter ();
   /* ctors (new-style, thread-safe) */
   CGMPlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   CGMPlotter (FILE *outfile, PlotterParams &params);
-  CGMPlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  CGMPlotter (ostream& out, PlotterParams &params);
+  CGMPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  CGMPlotter (std::ostream& out, PlotterParams &params);
   CGMPlotter (PlotterParams &params);
   /* dtor */
   virtual ~CGMPlotter ();
@@ -1978,14 +1979,14 @@
   /* ctors (old-style, not thread-safe) */
   PSPlotter (FILE *infile, FILE *outfile, FILE *errfile);
   PSPlotter (FILE *outfile);
-  PSPlotter (istream& in, ostream& out, ostream& err);
-  PSPlotter (ostream& out);
+  PSPlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  PSPlotter (std::ostream& out);
   PSPlotter ();
   /* ctors (new-style, thread-safe) */
   PSPlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   PSPlotter (FILE *outfile, PlotterParams &params);
-  PSPlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  PSPlotter (ostream& out, PlotterParams &params);
+  PSPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  PSPlotter (std::ostream& out, PlotterParams &params);
   PSPlotter (PlotterParams &params);
   /* dtor */
   virtual ~PSPlotter ();
@@ -2019,14 +2020,14 @@
   /* ctors (old-style, not thread-safe) */
   AIPlotter (FILE *infile, FILE *outfile, FILE *errfile);
   AIPlotter (FILE *outfile);
-  AIPlotter (istream& in, ostream& out, ostream& err);
-  AIPlotter (ostream& out);
+  AIPlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  AIPlotter (std::ostream& out);
   AIPlotter ();
   /* ctors (new-style, thread-safe) */
   AIPlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   AIPlotter (FILE *outfile, PlotterParams &params);
-  AIPlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  AIPlotter (ostream& out, PlotterParams &params);
+  AIPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  AIPlotter (std::ostream& out, PlotterParams &params);
   AIPlotter (PlotterParams &params);
   /* dtor */
   virtual ~AIPlotter ();
@@ -2078,14 +2079,14 @@
   /* ctors (old-style, not thread-safe) */
   SVGPlotter (FILE *infile, FILE *outfile, FILE *errfile);
   SVGPlotter (FILE *outfile);
-  SVGPlotter (istream& in, ostream& out, ostream& err);
-  SVGPlotter (ostream& out);
+  SVGPlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  SVGPlotter (std::ostream& out);
   SVGPlotter ();
   /* ctors (new-style, thread-safe) */
   SVGPlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   SVGPlotter (FILE *outfile, PlotterParams &params);
-  SVGPlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  SVGPlotter (ostream& out, PlotterParams &params);
+  SVGPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  SVGPlotter (std::ostream& out, PlotterParams &params);
   SVGPlotter (PlotterParams &params);
   /* dtor */
   virtual ~SVGPlotter ();
@@ -2122,14 +2123,14 @@
   /* ctors (old-style, not thread-safe) */
   PNMPlotter (FILE *infile, FILE *outfile, FILE *errfile);
   PNMPlotter (FILE *outfile);
-  PNMPlotter (istream& in, ostream& out, ostream& err);
-  PNMPlotter (ostream& out);
+  PNMPlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  PNMPlotter (std::ostream& out);
   PNMPlotter ();
   /* ctors (new-style, thread-safe) */
   PNMPlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   PNMPlotter (FILE *outfile, PlotterParams &params);
-  PNMPlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  PNMPlotter (ostream& out, PlotterParams &params);
+  PNMPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  PNMPlotter (std::ostream& out, PlotterParams &params);
   PNMPlotter (PlotterParams &params);
   /* dtor */
   virtual ~PNMPlotter ();
@@ -2161,14 +2162,14 @@
   /* ctors (old-style, not thread-safe) */
   PNGPlotter (FILE *infile, FILE *outfile, FILE *errfile);
   PNGPlotter (FILE *outfile);
-  PNGPlotter (istream& in, ostream& out, ostream& err);
-  PNGPlotter (ostream& out);
+  PNGPlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  PNGPlotter (std::ostream& out);
   PNGPlotter ();
   /* ctors (new-style, thread-safe) */
   PNGPlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   PNGPlotter (FILE *outfile, PlotterParams &params);
-  PNGPlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  PNGPlotter (ostream& out, PlotterParams &params);
+  PNGPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  PNGPlotter (std::ostream& out, PlotterParams &params);
   PNGPlotter (PlotterParams &params);
   /* dtor */
   virtual ~PNGPlotter ();
@@ -2196,14 +2197,14 @@
   /* ctors (old-style, not thread-safe) */
   GIFPlotter (FILE *infile, FILE *outfile, FILE *errfile);
   GIFPlotter (FILE *outfile);
-  GIFPlotter (istream& in, ostream& out, ostream& err);
-  GIFPlotter (ostream& out);
+  GIFPlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  GIFPlotter (std::ostream& out);
   GIFPlotter ();
   /* ctors (new-style, thread-safe) */
   GIFPlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   GIFPlotter (FILE *outfile, PlotterParams &params);
-  GIFPlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  GIFPlotter (ostream& out, PlotterParams &params);
+  GIFPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  GIFPlotter (std::ostream& out, PlotterParams &params);
   GIFPlotter (PlotterParams &params);
   /* dtor */
   virtual ~GIFPlotter ();
@@ -2270,14 +2271,14 @@
   /* ctors (old-style, not thread-safe) */
   XDrawablePlotter (FILE *infile, FILE *outfile, FILE *errfile);
   XDrawablePlotter (FILE *outfile);
-  XDrawablePlotter (istream& in, ostream& out, ostream& err);
-  XDrawablePlotter (ostream& out);
+  XDrawablePlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  XDrawablePlotter (std::ostream& out);
   XDrawablePlotter ();
   /* ctors (new-style, thread-safe) */
   XDrawablePlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   XDrawablePlotter (FILE *outfile, PlotterParams &params);
-  XDrawablePlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  XDrawablePlotter (ostream& out, PlotterParams &params);
+  XDrawablePlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  XDrawablePlotter (std::ostream& out, PlotterParams &params);
   XDrawablePlotter (PlotterParams &params);
   /* dtor */
   virtual ~XDrawablePlotter ();
@@ -2345,14 +2346,14 @@
   /* ctors (old-style, not thread-safe) */
   XPlotter (FILE *infile, FILE *outfile, FILE *errfile);
   XPlotter (FILE *outfile);
-  XPlotter (istream& in, ostream& out, ostream& err);
-  XPlotter (ostream& out);
+  XPlotter (std::istream& in, std::ostream& out, std::ostream& err);
+  XPlotter (std::ostream& out);
   XPlotter ();
   /* ctors (new-style, thread-safe) */
   XPlotter (FILE *infile, FILE *outfile, FILE *errfile, PlotterParams &params);
   XPlotter (FILE *outfile, PlotterParams &params);
-  XPlotter (istream& in, ostream& out, ostream& err, PlotterParams &params);
-  XPlotter (ostream& out, PlotterParams &params);
+  XPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &params);
+  XPlotter (std::ostream& out, PlotterParams &params);
   XPlotter (PlotterParams &params);
   /* dtor */
   virtual ~XPlotter ();
