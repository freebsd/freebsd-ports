--- sope-appserver/NGObjWeb/WOSession.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WOSession.m
@@ -33,10 +33,6 @@
 #include "common.h"
 #include <string.h>
 
-#if !defined(sel_get_name) && ((defined(__GNU_LIBOBJC__) && (__GNU_LIBOBJC__ >= 20100911)) || defined(APPLE_RUNTIME) || defined(__GNUSTEP_RUNTIME__))
-#  define sel_get_name sel_getName
-#endif
-
 #if APPLE_FOUNDATION_LIBRARY || NeXT_Foundation_LIBRARY
 @interface NSObject(Miss)
 - (id)notImplemented:(SEL)cmd;
