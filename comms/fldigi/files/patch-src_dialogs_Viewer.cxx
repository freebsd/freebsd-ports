--- src/dialogs/Viewer.cxx.orig	2008-02-17 13:33:02.000000000 -0500
+++ src/dialogs/Viewer.cxx	2008-02-17 13:35:44.000000000 -0500
@@ -87,7 +87,7 @@
 
 #ifdef REGEX
 regex_t* seek_re = 0;
-void re_comp(const char* needle)
+void fl_re_comp(const char* needle)
 {
         if (seek_re)
                 regfree(seek_re);
@@ -292,7 +292,7 @@
 	for (size_t i = 0; i < tofind.length(); i++)
 		tofind[i] = toupper(tofind[i]);
 #else
-	re_comp(inpSeek->value());
+	fl_re_comp(inpSeek->value());
 #endif
 }
 
