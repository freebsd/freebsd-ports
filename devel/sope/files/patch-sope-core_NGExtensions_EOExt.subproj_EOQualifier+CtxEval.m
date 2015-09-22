--- sope-core/NGExtensions/EOExt.subproj/EOQualifier+CtxEval.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/NGExtensions/EOExt.subproj/EOQualifier+CtxEval.m
@@ -29,7 +29,7 @@
 #  import <objc/objc.h>
 #  import <extensions/objc-runtime.h>
 #elif GNUSTEP_BASE_LIBRARY
-#if __GNU_LIBOBJC__ >= 20100911
+#if (defined(__GNU_LIBOBJC__) && (__GNU_LIBOBJC__ >= 20100911)) || defined(__GNUSTEP_RUNTIME__)
 #  define sel_get_name sel_getName
 #  import <objc/runtime.h>
 #else
