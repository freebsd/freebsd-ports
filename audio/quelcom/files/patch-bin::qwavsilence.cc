--- bin/qwavsilence.cc.orig	Fri Feb 23 21:29:12 2001
+++ bin/qwavsilence.cc	Fri Feb 13 19:17:38 2004
@@ -4,6 +4,9 @@
 # include "qexception.hh"
 # include "qmisc.hh"
 
+#include <iostream>
+#include <cstdio>
+
 #ifdef NLS
   # include <locale.h>
   # include <libintl.h>
@@ -14,9 +17,8 @@
 
 
 void usage () {
-
-  cerr.form(_(" %s: detect and shrink silence sequence in wav files\n"),APPNAME);
-  cerr.form(_(" syntax: %s [option]... file...\n"),APPNAME);
+  cerr << ' ' << APPNAME << _(": detect and shrink silence sequence in wav files\n");
+  cerr << _(" syntax: ") << APPNAME << _(" [option]... file...\n");
   cerr << _("   -d, --duration <duration>[j|s|m|b|k|M]: set the minimum silence duration.\n");
   cerr << _("   -h, --help: show this help and exit\n");
   cerr << _("   -l, --length [[h:]m:]s[.ms]: set the minimum silence duration.\n");
@@ -84,7 +86,7 @@
       case 't':
 	temp = strtod(optarg,0);
         if (temp<0 || temp>100) {
-          cerr.form(_("%s: threshold must be 0..100 (%d)\n"),APPNAME,temp);
+          fprintf(stderr,_("%s: threshold must be 0..100 (%d)\n"),APPNAME,(int)temp);
           return 1;
         }
         threshold = (u_int32_t)temp;
@@ -93,13 +95,14 @@
         verbose=true;
       break;
       case 'V':
-        cerr.form(_("%s - version %s - build %s\n"),APPNAME,VERSION,__DATE__);
+        cerr << APPNAME << " - " << _("version") << ' ' << VERSION
+	     << _("build") << ' ' << __DATE__ << '\n';
         return 0;
       break;      
       case '?':
       default: 
-        cerr.form(_("%s: option '%s' is not recognized or bad used\n"),
-                  APPNAME,argv[optind-1]);
+        cerr << APPNAME << ": " << _("option") << " '" << argv[optind-1]
+	     << "' " << _("is not recognized or bad used") << '\n';
         usage();
         return 1;
     } 
@@ -173,12 +176,12 @@
             mssec_end = (1000LL*silent_samples)/wav.getSampleRate();
 
             if (!verbose)
-              cout.form(_("%s: %d:%02d of silence at %d:%02d\n"),
+              printf(_("%s: %d:%02d of silence at %d:%02d\n"),
                         argv[optind],
                         mssec_end/60000,(mssec_end/1000)%60,
                         mssec_begin/60000,(mssec_begin/1000)%60);
             else
-              cout.form(_("%s: %d:%02d.%03d (%d samples) at %d:%02d:%03d (sample %d)\n"),
+              printf(_("%s: %d:%02d.%03d (%d samples) at %d:%02d:%03d (sample %d)\n"),
                         argv[optind],
                         mssec_end/60000,(mssec_end/1000)%60,mssec_end%1000,
 			silent_samples,
@@ -190,11 +193,11 @@
             if (shrink) {
               u_int32_t shrinkable_samples = silent_samples - duration_samples;
               
-              cerr.form(_("shrink %d samples at %d\n"),
+              fprintf(stderr,_("shrink %d samples at %d\n"),
                         shrinkable_samples,sample_index - shrinkable_samples - 1);
               if (shrinked_samples) {
                 u_int32_t samples_moved = sample_index-shrinkable_samples-(first_shrinkable_sample+shrinked_samples+1);
-                cerr.form(_("move %d..%d (%d samples) to %d..%d\n"),
+                fprintf(stderr,_("move %d..%d (%d samples) to %d..%d\n"),
                           first_shrinkable_sample+shrinked_samples+1,
                           sample_index-shrinkable_samples-1,
                           samples_moved,
@@ -232,7 +235,7 @@
         else {	// sortim del bucle pq s'ha acabat el fitxer...
           if (shrink && shrinked_samples) {
             u_int32_t samples_moved = sample_number-(first_shrinkable_sample+shrinked_samples+1);
-            cerr.form(_("move %d..%d (%d samples) to %d..%d\n"),
+            fprintf(stderr,_("move %d..%d (%d samples) to %d..%d\n"),
                       first_shrinkable_sample+shrinked_samples+1,
                       sample_number,
                       samples_moved,
@@ -247,7 +250,7 @@
 
       if (verbose) {
         u_int32_t mssec = 1000LL*total_silent_samples/wav.getSampleRate();
-        cerr.form(_("%s: total silence reported: %d:%02d.%02d (%d samples)\n"),
+        fprintf(stderr,_("%s: total silence reported: %d:%02d.%02d (%d samples)\n"),
                    argv[optind],mssec/60000,(mssec/1000)%60,(mssec%1000)/10,
                    total_silent_samples);
       }
@@ -267,5 +270,5 @@
   }
 
   if (errors)
-    cout.form ("%u error%c\n",errors,errors>1?'s':0);
+    printf ("%u error%c\n",errors,errors>1?'s':0);
 }
