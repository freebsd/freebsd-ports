--- bin/qwavfade.cc.orig	Fri Feb 23 21:29:12 2001
+++ bin/qwavfade.cc	Fri Feb 13 19:17:38 2004
@@ -4,6 +4,8 @@
 # include "qexception.hh"
 # include "qmisc.hh"
 
+#include <iostream>
+
 #ifdef NLS
   # include <locale.h>
   # include <libintl.h>
@@ -14,8 +16,8 @@
 
 void usage () {
 
-  cerr.form(_(" %s: fade in/out wav files\n"),APPNAME);
-  cerr.form(_(" syntax: %s [option]... file...\n"),APPNAME);
+  cerr << " " << APPNAME << _(": fade in/out wav files\n");
+  cerr << " " << _("syntax: ") << APPNAME << _("[option]... file...\n");
   cerr << _("   -d, --duration <duration>[j|s|m|b|k|M]: set the fade duration\n");
   cerr << _("   -h, --help: show this help and exit\n");
   cerr << _("   -i, --in: just fade in\n");
@@ -95,13 +97,14 @@
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
@@ -118,7 +121,7 @@
   while (argv[optind]) {
   
     if (verbose)
-      cerr.form(_("fading '%s'...\n"),argv[optind]);
+      cerr << _("fading '") << argv[optind] << "'...\n";
 
     qwav *wav = new qwav(argv[optind],wavmode);
     u_int32_t nsamples = wav->getSample(duration);	// dins del rang?
@@ -142,7 +145,7 @@
         wav->cut(h);
         
         if (verbose)
-          cerr.form(_("created testfile '%s'\n"),name.c_str());
+	  cerr << _("created testfile '") << name << "'\n";
 
         delete wav;
         wav = new qwav(name,qwav::READWRITE);
@@ -157,7 +160,8 @@
       }
 
       if (verbose)
-        cerr.form(_("faded in %d samples in '%s'\n"),nsamples,wav->getName().c_str());
+        cerr << _("faded in ") << nsamples << _(" samples in '") << wav->getName()
+	     << "'\n";
     }
   
     delete wav;
@@ -176,7 +180,7 @@
         wav->cut(h);
   
         if (verbose)
-          cerr.form(_("created testfile '%s'\n"),name.c_str());
+	  cerr << _("created testfile ") << name << "'\n";
 
         delete wav;
         wav = new qwav(name,qwav::READWRITE);
@@ -191,7 +195,8 @@
       }
 
       if (verbose)
-        cerr.form(_("faded out %d samples in '%s'\n"),nsamples,wav->getName().c_str());
+        cerr << _("faded out ") << nsamples << _(" samples in '")
+	     << wav->getName() << "'\n";
     }
 
     optind++;
