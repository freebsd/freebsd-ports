--- bin/qwavcut.cc.orig	Fri Feb 23 21:29:12 2001
+++ bin/qwavcut.cc	Fri Feb 13 19:17:38 2004
@@ -2,6 +2,8 @@
 # include "qwav.hh"
 # include "qexception.hh"
 
+#include <iostream>
+
 #ifdef NLS
   # include <locale.h>
   # include <libintl.h>
@@ -11,9 +13,8 @@
 #endif
 
 void usage () {
-
-  cerr.form(_(" %s: extract and/or delete parts of a wav file\n"),APPNAME);
-  cerr.form(_(" syntax: %s [option]... file\n"),APPNAME);
+  cerr << ' ' << APPNAME << _(": extract and/or delete parts of a wav file\n");
+  cerr << _(" syntax: ") << APPNAME << _(" [option]... file\n");
   cerr << _(" options:\n");
   cerr << _("   -B, --set-begin <cut point>: set the first sample from the beginning of the file\n");
   cerr << _("   -b, --set-begin-from-eof <cut point>: set the first sample from the end of the file\n");
@@ -102,13 +103,14 @@
           verbose=true;
         break;
         case 'V':
-          cerr.form(_("%s - version %s - build %s\n"),APPNAME,VERSION,__DATE__);
+          cerr << APPNAME << " - " << _("version") << ' ' << VERSION
+	       << _("build") << ' ' << __DATE__ << '\n';
           return 0;
         break;
         case '?':
         default: 
-          cerr.form(_("%s: option '%s' is not recognized or bad used\n"),
-                    APPNAME,argv[optind-1]);
+          cerr << APPNAME << ": " << _("option") << " '" << argv[optind-1]
+	       << "' " << _("is not recognized or bad used") << '\n';
           usage();
           return 1;
       }
