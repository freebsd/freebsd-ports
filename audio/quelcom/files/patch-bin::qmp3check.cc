--- bin/qmp3check.cc.orig	Fri Feb 23 21:29:12 2001
+++ bin/qmp3check.cc	Fri Feb 13 19:17:38 2004
@@ -15,9 +15,9 @@
 #endif
 
 void usage () {
-
-  cerr.form(_(" %s: check and clean mp3 streams\n"),APPNAME);
-  cerr.form(_(" syntax: %s [option]... file...\n"),APPNAME);
+  cerr << APPNAME << ": " << _("check and clean mp3 streams") << '\n';
+  cerr << ' ' << _("syntax") << APPNAME
+       << ' ' << _("[option]... file...") << '\n';
   cerr << _("   -D, --delete: delete invalid frames and garbage. use with care\n");
   cerr << _("   -h, --help: show this help and exit\n");
   cerr << _("   -q, --quiet: no output messages\n");
@@ -76,11 +76,12 @@
         verbose=true; quiet=false;
       break;
       case 'V':
-        cerr.form(_("%s - version %s - build %s\n"),APPNAME,VERSION,__DATE__);
+        cerr << APPNAME << " - " << _("version") << ' ' << VERSION
+	     << _("build") << ' ' << __DATE__ << '\n';
         return 0;
       default: 
-        cerr.form(_("%s: option '%s' is not recognized or bad used\n"),
-                  APPNAME,argv[optind-1]);
+        cerr << APPNAME << ": " << _("option") << " '" << argv[optind-1]
+	     << "' " << _("is not recognized or bad used") << '\n';
         usage();
         return 1;
     }
@@ -144,8 +145,8 @@
       skipped = frame->getMap()-file.getMap();
       if (skipped) {
         if (!quiet)
-          cerr.form(_("%s: skipped %d bytes of garbage at the beginning\n"),
-                    *argv,skipped);
+	  cerr << *argv << ": " << _("skipped") << ' ' << skipped << ' '
+	       << _("bytes of garbage at the beginning") << '\n';
         total_skipped += skipped;
         stream_length -= skipped;
       }
@@ -156,8 +157,9 @@
       }
       else 
         if (!quiet)
-          cerr.form(_("%s: first frame incomplete: %d of %d bytes\n"),
-                    *argv,stream_length,frame->getLength());
+	  cerr << *argv << ": " << _("first frame incomplete") << ": "
+	       << stream_length << _(" of ") << frame->getLength()
+	       <<  ' ' << _("bytes") << '\n';
              
       while (stream_length) {
 
@@ -166,10 +168,11 @@
         }
         catch (qexception e) {
           if (!quiet)
-            cerr.form(_("%s: %d bytes of garbage at the end"),
-                      *argv,stream_length);
+	    cerr << *argv << ": " << stream_length
+	         << _(" bytes of garbage at the end");
           if (verbose)
-            cerr.form(" (%d..%d)",file.getSize()-stream_length,file.getSize()); 
+	    cerr << " (" << file.getSize()-stream_length
+	         << ',' << file.getSize() << ')';
           if (!quiet)
             cerr << endl;
           total_skipped += stream_length;
@@ -179,11 +182,11 @@
 
         if (skipped) {
           if (!quiet)
-            cerr.form(_("%s: skipped %d bytes"),*argv,skipped);
+	    cerr << *argv << _(": skipped") << skipped << _(" bytes");
           if (verbose)
-            cerr.form(" (%d..%d)",
-                      clean_block_end-file.getMap()+1,
-                      frame->getMap()-file.getMap()-1); 
+	    cerr << " (" << clean_block_end-file.getMap()+1
+	         << ".." << frame->getMap()-file.getMap()-1 << ')'; 
+
           if (!quiet)
             cerr << endl;
 
@@ -191,15 +194,14 @@
               (clean_offset!=file.getMap()-1)) {
 	    if (del) {
               if (!quiet)
-                cerr.form(_("%s: moving %d bytes"),
-                          *argv,
-                          clean_block_end-clean_block_begin+1);
+	        cerr << *argv << _(": moving ")
+		     << clean_block_end-clean_block_begin+1
+		     << _(" bytes");
               if (verbose)
-                cerr.form(" (%d..%d) <-- (%d..%d)",
-                           clean_offset-file.getMap()+1,
-                           clean_offset-file.getMap()+1+clean_block_end-clean_block_begin,
-                           clean_block_begin-file.getMap(),
-                           clean_block_end-file.getMap());
+	        cerr << " (" << clean_offset-file.getMap()+1
+		     << ".." << clean_offset-file.getMap()+1+clean_block_end-clean_block_begin
+		     << ") <-- (" << clean_block_begin-file.getMap()
+		     << ".." << clean_block_end-file.getMap() << ")";
               if (!quiet)
                 cerr << endl;
   
@@ -223,8 +225,9 @@
         }
         else {
           if (!quiet)
-            cerr.form(_("%s: last frame (%d+1) truncated: %d of %d bytes\n"),
-                      *argv,frames,stream_length,frame->getLength());
+	    cerr << *argv << _(": last frame (") << frames << _(") truncated: ")
+	         << stream_length << _(" of ") << frame->getLength()
+		 << _(" bytes\n");
           total_skipped += stream_length;
           stream_length = 0;
           break;
@@ -237,14 +240,13 @@
 
 	if (del) {
           if (!quiet)
-            cerr.form(_("%s: moving %d bytes"),
-                       *argv,clean_block_end-clean_block_begin+1);
-          if (verbose)                       
-            cerr.form(" (%d..%d) <-- (%d..%d)",
-                       clean_offset-file.getMap()+1,
-                       clean_offset-file.getMap()+1+clean_block_end-clean_block_begin,
-                       clean_block_begin-file.getMap(),
-                       clean_block_end-file.getMap());
+	    cerr << *argv << _(": moving ")
+	         << clean_block_end-clean_block_begin+1 << _(" bytes");
+          if (verbose)                    
+	    cerr << " (" << clean_offset-file.getMap()+1
+	         << ".." << clean_offset-file.getMap()+1+clean_block_end-clean_block_begin
+		 << ") <-- (" << clean_block_begin-file.getMap()
+		 << ".." << clean_block_end-file.getMap() << ')';
 	  if (!quiet)
             cerr << endl;
 
@@ -261,7 +263,7 @@
         if (del) {
           if (delTag) {
             if (!quiet)
-              cerr.form(_("%s: skipping tag"),*argv);
+	      cerr << *argv << _(": skipping tag");
             if (verbose)
               cerr << " (" << qtag::LENGTH << " bytes)";
             if (!quiet)
@@ -274,13 +276,13 @@
                          (u_int32_t)(tag->getMap()-file.getMap()+qtag::LENGTH-1),
                          (u_int32_t)(clean_offset+1-file.getMap()));
               if (!quiet)
-                cerr.form(_("%s: moving tag (%d bytes)"),*argv,qtag::LENGTH);
+	        cerr << *argv << _(": moving tag (") << qtag::LENGTH << ")";
               if (verbose)
-                cerr.form(" (%d..%d) <-- (%d..%d)",
-                          clean_offset-file.getMap()+1,
-                          clean_offset-file.getMap()+1+qtag::LENGTH-1,
-                          tag->getMap()-file.getMap(),
-                          tag->getMap()-file.getMap()+qtag::LENGTH-1);
+
+	    cerr << " (" << clean_offset-file.getMap()+1
+	         << ".." << clean_offset-file.getMap()+1+qtag::LENGTH-1
+		 << ") <-- (" << tag->getMap()-file.getMap()
+		 << ".." << tag->getMap()-file.getMap()+qtag::LENGTH-1 << ')';
               if (!quiet)
                 cerr << endl;
             }
@@ -293,12 +295,12 @@
 
       if (total_skipped) {
         if (!quiet)
-          cerr.form(_("%s: %d of %d discardable bytes\n"),
-                    *argv,total_skipped,file.getSize());
+	  cerr << *argv << ": " << total_skipped << _(" of ") << file.getSize()
+	       << _(" discardable bytes\n");
         if (del) {
           if (!quiet)
-            cerr.form(_("%s: truncating to %d bytes\n"),
-                      *argv,file.getSize()-total_skipped);
+	    cerr << *argv << _(": truncating to ") << file.getSize()-total_skipped
+	         << _(" bytes\n");
 	  file.truncate(file.getSize()-total_skipped);
         }
       }
@@ -309,8 +311,8 @@
           cerr << mp3 << endl;	// quedaria millor la versió 'verbose...'
         }
         else
-          cerr.form(_("%s: %d frames, %d bytes\n"),
-                    *argv,frames,clean_offset-file.getMap()+1);
+	  cerr << *argv << ": " << frames << _(" frames, ")
+	       << clean_offset-file.getMap()+1 << _(" bytes\n");
       }
 
       if (hasTag)
@@ -327,5 +329,5 @@
   } while (*++argv);
 
   if (error_files && verbose)
-    cerr.form(_("%d error files found\n"),error_files);
+    cerr << error_files << _(" error files found\n");
 }
