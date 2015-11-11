--- sope-core/EOControl/EOValidation.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/EOControl/EOValidation.m
@@ -153,7 +153,7 @@
 #if NeXT_RUNTIME
     sel = sel_getUid(buf);
 #else
-    sel = sel_get_any_uid(buf);
+    sel = sel_registerName(buf);
 #endif
     if (sel) {
       if ([self respondsToSelector:sel]) {
