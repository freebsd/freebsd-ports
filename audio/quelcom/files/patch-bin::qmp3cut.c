--- bin/qmp3cut.cc.orig	Fri Feb 23 21:29:12 2001
+++ bin/qmp3cut.cc	Fri Feb 13 19:17:38 2004
@@ -11,9 +11,8 @@
 #endif
 
 void usage () {
-
-  cerr.form(_(" %s: extract and/or delete parts of a mp3 file\n"),APPNAME);
-  cerr.form(_(" syntax: %s [option]... file\n"),APPNAME);
+  cerr << ' ' << APPNAME << _(": extract and/or delete parts of a mp3 file\n");
+  cerr << _(" syntax: ") << APPNAME << _(" [option]... file\n");
   cerr << _(" options:\n");
   cerr << _("   -B, --set-begin <cut point>: set the first frame from the beginning of the file\n");
   cerr << _("   -b, --set-begin-from-eof <cut point>: set the first frame from the end of the file\n");
@@ -102,13 +101,14 @@
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
@@ -140,7 +140,7 @@
     qmp3 mp3 (infile,mode); 
 
     if (verbose)
-      cerr.form(_("scanning '%s'..."),infile.c_str());
+      cerr << _("scanning '") << infile << "'...";
     mp3.scan();
     if (verbose)
       cerr << "ok." << endl;
