--- bin/qwavinfo.cc.orig	Fri Feb 23 21:29:12 2001
+++ bin/qwavinfo.cc	Fri Feb 13 19:17:38 2004
@@ -4,6 +4,9 @@
 # include "qwav.hh"
 # include "qexception.hh"
 
+#include <iostream>
+#include <cstdio>
+
 #ifdef NLS
   # include <locale.h>
   # include <libintl.h>
@@ -14,9 +17,8 @@
 
 
 void usage () {
-
-  cerr.form(_(" %s: show info from wav files\n"),APPNAME);
-  cerr.form(_(" syntax: %s [option]... file...\n"),APPNAME);
+  cerr << ' ' << APPNAME << _(": show info from wav files\n");
+  cerr << _(" syntax: ") << APPNAME << _(" [option]... file...\n");
   cerr << _("   -h, --help: show this help and exit\n");
   cerr << _("   -s, --summary-only: show only the summary\n");
   cerr << _("   -v, --verbose: verbose\n");
@@ -66,13 +68,14 @@
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
@@ -124,14 +127,14 @@
     optind++;
   }
 
-  cout.form (_("%u file%c"),files,files>1?'s':0);
+  printf (_("%u file%c"),files,files>1?'s':0);
   if (errors)
-    cout.form (" (%u error%c)",errors,errors>1?'s':0);
+    printf (" (%u error%c)",errors,errors>1?'s':0);
   if (verbose)
-    cout.form (_(" => %d:%02d.%03d  %u samples  %u bytes\n"),
+    printf (_(" => %d:%02d.%03d  %u samples  %u bytes\n"),
                total_msduration/60000,(total_msduration/1000)%60,
                total_msduration%1000,total_samples,total_bytes);
   else
-    cout.form (" => %d:%02d\n",
+    printf (" => %d:%02d\n",
                total_msduration/60000,(total_msduration/1000)%60);
 }
