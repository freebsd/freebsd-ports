--- bin/qmp3report.cc.orig	Fri Feb 23 21:29:12 2001
+++ bin/qmp3report.cc	Fri Feb 13 19:17:38 2004
@@ -11,6 +11,8 @@
 # include "qreport.hh"
 # include "qmisc.hh"
 
+using namespace std;
+
 #ifdef NLS
   # include <locale.h>
   # include <libintl.h>
@@ -30,8 +32,9 @@
 
 void usage () {
 
-  cerr.form(_(" %s: generate reports from mp3 files and directories\n"),APPNAME);
-  cerr.form(_(" syntax: %s [option]... file...\n"),APPNAME);
+  cerr << ' ' << APPNAME
+       << ": generate reports from mp3 files and directories\n";
+  cerr << " syntax: " << APPNAME << " [option]... file...\n";
   cerr << _(" options:\n");
   cerr << _("   -a, --all-files: report all files, not just *.mp3\n");
   cerr << _("   -A, --show-all: implies -d, -f, -s\n");
@@ -58,7 +61,7 @@
     if (opts.all) {
       qfile f(filename);
       if (opts.verbose)
-        cerr.form (_("reporting file '%s'\n"),filename.c_str());
+      	cerr << _("reporting file") << " '" << filename << "'\n";
       qreport r(f);
       if (opts.showfiles) {
         if (opts.html) {
@@ -89,7 +92,7 @@
       mp3.scan();
     }
     if (opts.verbose)
-      cerr.form (_("reporting mp3 file '%s'\n"),mp3name.c_str());
+      cerr << _("reporting mp3 file") << " '" << mp3name << "'\n";
     qreport r(mp3);
     if (opts.showfiles) {
       if (opts.html) {
@@ -110,13 +113,13 @@
 qreport report_directory (string dirname, struct options &opts) {
 
   if (opts.verbose)
-    cerr.form (_("reporting directory '%s'\n"),dirname.c_str());
+    cerr << _("reporting directory") << " '" << dirname << "'\n";
 
   qreport dirreport(dirname);
 
   if (!opts.recursive) {
     if (opts.verbose)
-      cerr.form(_("%s: '%s' is a directory\n"),APPNAME,dirname.c_str());
+      cerr << APPNAME << ": '" << dirname << ' ' << _("is a directory") << '\n';
     return dirreport;
   }
 
@@ -125,17 +128,18 @@
   ofstream *out;
   if (opts.split) {
     if (getcwd(previous_wd,sizeof(previous_wd))==NULL) {
-      cerr.form(_("cannot get current directory (%s): %s\n"),
-                dirname.c_str(),strerror(errno));
+      cerr << _("cannot get current directory") << " ("
+           << dirname << "): " << strerror(errno) << '\n';
       return dirreport;
     }
     if (chdir(dirname.c_str())) {
-      cerr.form(_("cannot move to dir %s: %s\n"),dirname.c_str(),strerror(errno));
+      cerr << _("cannot move to dir")
+           << dirname << ": " << strerror(errno) << '\n';
       return dirreport;
     }
     if (getcwd(wd,sizeof(wd))==NULL) {
-      cerr.form(_("cannot get current directory (%s): %s\n"),
-                dirname.c_str(),strerror(errno));
+      cerr << _("cannot get current directory")
+           << " (" << dirname << "): " << strerror(errno) << '\n';
       return dirreport;
     }
     char *index = strrchr(wd,'/');
@@ -150,7 +154,7 @@
       outfilename += string(".txt");
     
     if (opts.verbose)
-      cerr.form(_("opening output file '%s'\n"),outfilename.c_str());
+      cerr << _("opening output file") << " '" << outfilename << "'\n";
 
     out = opts.out;
     opts.out = new ofstream(outfilename.c_str());
@@ -162,7 +166,7 @@
   struct dirent **namelist;
 
   if ((n = scandir(dirname.c_str(),&namelist,0,alphasort))<0) {
-    cerr.form(_("%s: cannot scan '%s'\n"),APPNAME,dirname.c_str());
+    cerr << APPNAME << ':' << _("cannot scan") << " '" << dirname << "'\n";
     return dirreport;
   }
 
@@ -181,8 +185,9 @@
       filepathname = dirname + string("/") + string(namelist[i]->d_name);
 
     if (stat(filepathname.c_str(),&filestat)) {
-      cerr.form(_("%s: error reading '%s' status: %s\n"),
-                APPNAME,dirname.c_str(),strerror(errno));
+      cerr << APPNAME << ": " << _("error reading")
+           << " '" << dirname << "' status: "
+      	   << strerror(errno) << '\n';
       continue;
     }
 
@@ -284,13 +289,14 @@
       case 'S': opts.split = true;	break;
       case 'v': opts.verbose = true;	break;
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
@@ -304,12 +310,12 @@
 
   qreport base;
   
-  opts.out = new ofstream(1);
+  opts.out = new ofstream;
 
   if (opts.split)
     opts.out = new ofstream("/dev/null");
   else {
-    opts.out = new ofstream(1);
+    opts.out = new ofstream;
     if (opts.html)
       *opts.out << "<html>\n<head><title>qmp3report</title>\n</head>\n\n<body>\n";
   }
@@ -319,8 +325,9 @@
     struct stat filestat;
 
     if (stat(argv[optind],&filestat)) {
-      cerr.form(_("%s: error reading '%s' status: %s\n"),
-                APPNAME,argv[optind],strerror(errno));
+      cerr << APPNAME << ": " << _("error reading") << " '"
+           << argv[optind] << "' " << _("status") << ": "
+	   << strerror(errno) << '\n';
       continue;
     }
 
@@ -358,7 +365,7 @@
       cout << base << endl;
     }
     else {
-      base.html(new ofstream(1));
+      base.html(new ofstream);
       cout << "<br>" << endl;
     }
   }
