--- chooser_plus.cxx.orig	Mon Nov 18 11:14:10 2002
+++ chooser_plus.cxx	Mon Nov 18 11:17:52 2002
@@ -442,7 +442,7 @@
 					   strcmp(pat,f->browser.pattern))) {
     // if pattern is different, remove name but leave old directory:
     const char* p = f->input.value();
-    const char* q = fl_filename_name(p);
+    const char* q = filename_name(p);
     f->input.value(p, q-p);
   }
   f->browser.pattern = pat;
@@ -500,7 +500,7 @@
 					   strcmp(pat,f->browser.pattern))) {
     // if pattern is different, remove name but leave old directory:
     const char* p = f->input.value();
-    const char* q = fl_filename_name(p);
+    const char* q = filename_name(p);
     f->input.value(p, q-p);
   }
   f->browser.pattern = pat;
