--- bin/qmp3info.cc.orig	Fri Feb 23 21:29:12 2001
+++ bin/qmp3info.cc	Fri Feb 13 19:17:38 2004
@@ -11,9 +11,8 @@
 #endif
 
 void usage () {
-
-  cerr.form(_(" %s: show info from mp3 files\n"),APPNAME);
-  cerr.form(_(" syntax: %s [option]... file...\n"),APPNAME);
+  cerr << ' ' << APPNAME << _(": show info from mp3 files\n");
+  cerr << _(" syntax: ") << APPNAME << _(" [option]... file...\n");
   cerr << _("   -c, --check: check the entire stream (slower but accurate)\n");
   cerr << _("   -h, --help: show this help and exit\n");
   cerr << _("   -s, --summary-only: show only the summary\n");
@@ -69,13 +68,14 @@
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
@@ -136,15 +136,22 @@
     optind++;
   }
 
-  cout.form (_("%u file%c"),files,files>1?'s':0);
+  cout << files << _(" file") << (files>1?"s":"");
   if (errors)
-    cout.form (" (%u error%c)",errors,errors>1?'s':0);
-  if (verbose)
-    cout.form (" => %d:%02d.%03d  %u frames  %u bytes\n",
-               total_msduration/60000,(total_msduration/1000)%60,
-               total_msduration%1000,total_frames,total_bytes);
-  else
-    cout.form (" => %d:%02d\n",
-               total_msduration/60000,(total_msduration/1000)%60);
-
+    cout << errors << _(" error") << (errors>1?"s":"");
+  if (verbose) {
+    cout << " => " << total_msduration/60000 << ":";
+    cout.width(2);
+    cout.fill('0');
+    cout << (total_msduration/1000)%60 << '.';
+    cout.width(3);
+    cout.fill('0');
+    cout << total_msduration%1000 << "  " << total_frames << "  "
+         << total_bytes << " bytes\n";
+  } else {
+    cout << " => " << total_msduration/60000 << ':';
+    cout.width(2);
+    cout.fill('0');
+    cout << (total_msduration/1000)%60 << '\n';
+  }
 }
