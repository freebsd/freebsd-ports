--- bin/qmp3join.cc.orig	Fri Feb 23 21:29:12 2001
+++ bin/qmp3join.cc	Fri Feb 13 19:17:38 2004
@@ -11,9 +11,8 @@
 #endif
 
 void usage () {
-
-  cerr.form(_(" %s: join mp3 files\n"),APPNAME);
-  cerr.form(_(" syntax: %s [option]... file1 file2...\n"),APPNAME);
+  cerr << ' ' << APPNAME << _(": join mp3 files\n");
+  cerr << _(" syntax: ") << APPNAME << _(" [option]... file1 file2...\n");
   cerr << _("   -f, --force: force join bypassing bit rate checks\n");
   cerr << _("   -h, --help: show this help and exit\n");
   cerr << _("   -o, --output <file>: send output to <file>. otherwise, append to <file1>\n");
@@ -68,13 +67,14 @@
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
@@ -95,7 +95,7 @@
     if (outfile!="") {
       mp3 = new qmp3(*argv);
       if (verbose)
-        cerr.form(_("copying '%s' to '%s'..."),*argv,outfile.c_str());
+        cerr << _(" copying '") << *argv << _("' to '") << outfile << "'...";
       mp3->dup(outfile);
       if (verbose)
         cerr << "ok." << endl;
@@ -106,7 +106,7 @@
       mp3 = new qmp3(*argv,qmp3::READWRITE);
 
     if (verbose)
-      cerr.form(_("scanning '%s'..."),mp3->getName().c_str());
+      cerr << _("scanning '") << mp3->getName() << "'...";
 
     mp3->scan();
     if (verbose)
@@ -117,14 +117,14 @@
       qmp3 mm(*argv);
  
       if (verbose)
-        cerr.form(_("scanning '%s'..."),mm.getName().c_str());
+        cerr << _("scanning '") << mm.getName() << "'...";
       mm.scan();
       if (verbose)
         cerr << "ok." << endl;
 
       if (verbose)
-        cerr.form(_("appending '%s' to '%s'..."),
-                  mm.getName().c_str(),mp3->getName().c_str());
+        cerr << _("appending '") << mm.getName() << _("' to '")
+	     << mp3->getName() << "'...";
       mp3->append(mm,force);
       if (verbose)
         cerr << "ok." << endl;
