--- maplay.cc.orig	Thu Jun 23 22:14:36 1994
+++ maplay.cc	Thu Nov 21 16:40:21 2002
@@ -39,8 +39,8 @@
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
-#include <iostream.h>
-#include <iomanip.h>
+#include <iostream>
+#include <iomanip>
 #include "all.h"
 #include "crc.h"
 #include "header.h"
@@ -51,17 +51,16 @@
 #include "subband_layer_2.h"
 #include "synthesis_filter.h"
 
-
 // data extracted from commandline arguments:
 static char *filename;
-static bool verbose_mode = False, filter_check = False;
-static bool stdout_mode = False;
+static boolean verbose_mode = False, filter_check = False;
+static boolean stdout_mode = False;
 static enum e_channels which_channels = both;
-static bool use_speaker = False, use_headphone = False, use_line_out = False;
+static boolean use_speaker = False, use_headphone = False, use_line_out = False;
 #ifdef ULAW
-static bool force_amd = False;
+static boolean force_amd = False;
 #endif
-static bool use_own_scalefactor = False;
+static boolean use_own_scalefactor = False;
 static real scalefactor;
 
 // data extracted from header of first frame:
@@ -93,12 +92,12 @@
 main (int argc, char *argv[])
 {
   int i;
-  bool read_ready = False, write_ready = False;
+  boolean read_ready = False, write_ready = False;
 
   if (argc < 2 || !strncmp (argv[1], "-h", 2))
   {
 usage:
-    cerr << "\nusage: " << argv[0]
+    std::cerr << "\nusage: " << argv[0]
 	 << " [-v] [-s] [-l] [-r] "
 #ifdef SPARC
 	    "[-us] [-uh] "
@@ -146,6 +145,9 @@
 #ifdef Solaris
 	    "SPARC Solaris 2.x"
 #else
+#ifdef __FreeBSD__
+	    "FreeBSD"
+#else
 #ifdef LINUX
 	    "Linux"
 #else
@@ -159,6 +161,7 @@
 #endif
 #endif
 #endif
+#endif
 	    " version)\n"
 	    "@(#) Copyright (C) 1993, 1994 Tobias Bading (bading@cs.tu-berlin.de)\n"
 	    "@(#) Berlin University of Technology\n"
@@ -216,7 +219,7 @@
 	case 'f':
 	  if (++i == argc)
 	  {
-	    cerr << "please specify a new scalefactor after the -f option!\n";
+	    std::cerr << "please specify a new scalefactor after the -f option!\n";
 	    exit (1);
 	  }
 	  use_own_scalefactor = True;
@@ -243,7 +246,7 @@
   header = new Header;
   if (!header->read_header (stream, &crc))
   {
-    cerr << "no header found!\n";
+    std::cerr << "no header found!\n";
     Exit (1);
   }
 
@@ -328,7 +331,7 @@
 //  }
 //#else
   {
-    cerr << "Sorry, I don't know your audio device.\n"
+    std::cerr << "Sorry, I don't know your audio device.\n"
 	    "Please use the stdout mode.\n";
     Exit (0);
   }
@@ -345,22 +348,22 @@
       ++name;
     else
       name = filename;
-    cerr << name << " is a layer " << header->layer_string () << ' '
+    std::cerr << name << " is a layer " << header->layer_string () << ' '
 	 << header->mode_string () << " MPEG audio stream with";
     if (!header->checksums ())
-      cerr << "out";
-    cerr << " checksums.\nThe sample frequency is "
+      std::cerr << "out";
+    std::cerr << " checksums.\nThe sample frequency is "
 	 << header->sample_frequency_string () << " at a bitrate of "
 	 << header->bitrate_string () << ".\n"
 	    "This stream is ";
     if (header->original ())
-      cerr << "an original";
+      std::cerr << "an original";
     else
-      cerr << "a copy";
-    cerr << " and is ";
+      std::cerr << "a copy";
+    std::cerr << " and is ";
     if (!header->copyright ())
-      cerr << "not ";
-    cerr << "copyright protected.\n";
+      std::cerr << "not ";
+    std::cerr << "copyright protected.\n";
   }
 
   do
@@ -371,20 +374,20 @@
     {
       // layer switching is allowed
       if (verbose_mode)
-	cerr << "switching to layer " << header->layer_string () << ".\n";
+	std::cerr << "switching to layer " << header->layer_string () << ".\n";
       layer = header->layer ();
     }
     if ((mode == single_channel && header->mode () != single_channel) ||
 	(mode != single_channel && header->mode () == single_channel))
     {
       // switching from single channel to stereo or vice versa is not allowed
-      cerr << "illegal switch from single channel to stereo or vice versa!\n";
+      std::cerr << "illegal switch from single channel to stereo or vice versa!\n";
       Exit (1);
     }
     if (header->sample_frequency () != sample_frequency)
     {
       // switching the sample frequency is not allowed
-      cerr << "sorry, can't switch the sample frequency in the middle of the stream!\n";
+      std::cerr << "sorry, can't switch the sample frequency in the middle of the stream!\n";
       Exit (1);
     }
 
@@ -423,7 +426,7 @@
     }
     else
     {
-      cerr << "sorry, layer 3 not implemented!\n";
+      std::cerr << "sorry, layer 3 not implemented!\n";
       Exit (0);
     }
 
@@ -463,7 +466,7 @@
     }
     else
       // Sh*t! Wrong crc checksum in frame!
-      cerr << "WARNING: frame contains wrong crc checksum! (throwing frame away)\n";
+      std::cerr << "WARNING: frame contains wrong crc checksum! (throwing frame away)\n";
 
     for (i = 0; i < header->number_of_subbands (); ++i)
       delete subbands[i];
@@ -481,18 +484,18 @@
     // check whether (one of) the filter(s) produced values not in [-1.0, 1.0]:
     if (range_violations)
     {
-      cerr << range_violations << " range violations have occured!\n";
+      std::cerr << range_violations << " range violations have occured!\n";
       if (stdout_mode)
-	cerr << "If you notice these violations,\n";
+	std::cerr << "If you notice these violations,\n";
       else
-	cerr << "If you have noticed these violations,\n";
-      cerr << "please use the -f option with the value ";
+	std::cerr << "If you have noticed these violations,\n";
+      std::cerr << "please use the -f option with the value ";
       if (mode != single_channel && which_channels == both &&
 	  filter2->hardest_violation () > filter1->hardest_violation ())
-	cerr << filter2->recommended_scalefactor ();
+	std::cerr << filter2->recommended_scalefactor ();
       else
-	cerr << filter1->recommended_scalefactor ();
-      cerr << "\nor a greater value up to 32768 and try again.\n";
+	std::cerr << filter1->recommended_scalefactor ();
+      std::cerr << "\nor a greater value up to 32768 and try again.\n";
     }
   }
   if (verbose_mode)
@@ -502,13 +505,13 @@
     uint32 minutes = (uint32)(playtime / 60.0);
     uint32 seconds = (uint32)playtime - minutes * 60;
     uint32 centiseconds = (uint32)((playtime - (real)(minutes * 60) - (real)seconds) * 100.0);
-    cerr << "end of stream, playtime: " << minutes << ':';
-    cerr.width (2);
-    cerr.fill ('0');
-    cerr << seconds << '.';
-    cerr.width (2);
-    cerr.fill ('0');
-    cerr << centiseconds << '\n';
+    std::cerr << "end of stream, playtime: " << minutes << ':';
+    std::cerr.width (2);
+    std::cerr.fill ('0');
+    std::cerr << seconds << '.';
+    std::cerr.width (2);
+    std::cerr.fill ('0');
+    std::cerr << centiseconds << '\n';
   }
 
   return 0;
