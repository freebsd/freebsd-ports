--- bin/qwavjoin.cc.orig	Fri Feb 23 21:29:12 2001
+++ bin/qwavjoin.cc	Fri Feb 13 19:17:38 2004
@@ -2,6 +2,8 @@
 # include "qwav.hh"
 # include "qexception.hh"
 
+#include <iostream>
+
 #ifdef NLS
   # include <locale.h>
   # include <libintl.h>
@@ -12,9 +14,8 @@
 
 
 void usage () {
-
-  cerr.form(_(" %s: join wav files\n"),APPNAME);
-  cerr.form(_(" syntax: %s [option]... file1 file2...\n"),APPNAME);
+  cerr << ' ' << APPNAME << _(": join wav files\n");
+  cerr << _(" syntax: ") << APPNAME << _(" [option]... file1 file2...\n");
   cerr << _("   -h, --help: show this help and exit\n");
   cerr << _("   -o, --output <file>: send output to <file>. otherwise, append to <file1>\n");
   cerr << _("   -v, --verbose: verbose\n");
@@ -64,13 +65,14 @@
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
@@ -91,7 +93,7 @@
     if (outfile!="") {
       wav = new qwav(*argv);
       if (verbose)
-        cerr.form(_("copying '%s' to '%s'..."),*argv,outfile.c_str());
+        cerr << _("copying '") << *argv << _("' to '") << outfile << "'...";
       wav->dup(outfile);
       if (verbose)
         cerr << "ok." << endl;
@@ -106,8 +108,8 @@
       qwav ww(*argv);
 
       if (verbose)
-        cerr.form(_("appending '%s' to '%s'..."),
-                  ww.getName().c_str(),wav->getName().c_str());
+        cerr << _("appending '") << ww.getName() << _("' to '")
+	     << wav->getName() << "'...";
       wav->append(ww);
       if (verbose)
         cerr << "ok." << endl;
