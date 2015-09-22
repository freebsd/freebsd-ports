--- sope-appserver/NGObjWeb/NSObject+WO.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/NSObject+WO.m
@@ -259,7 +259,7 @@ IMP WOGetKVCGetMethod(id object, NSStrin
   if (object == nil) return NULL;
   if (_key   == nil) return NULL;
 
-#if GNU_RUNTIME && !(defined(__GNU_LIBOBJC__) && (__GNU_LIBOBJC__ >= 20100911))
+#if GNU_RUNTIME && !(defined(__GNU_LIBOBJC__) && (__GNU_LIBOBJC__ >= 20100911)) && !defined(__GNUSTEP_RUNTIME__)
   {
     unsigned keyLen;
     char     *buf;
@@ -317,7 +317,9 @@ id WOGetKVCValueUsingMethod(id object, N
       return nil;
     free(buf); buf = NULL;
   }
-#if GNUSTEP_BASE_LIBRARY
+// This appears to be a work around for an old version of GNUstep-base not
+// correctly handling the case where there is no method.
+#if GNUSTEP_BASE_LIBRARY && !defined(__GNUSTEP_RUNTIME__)
   if (!__objc_responds_to(object, getSel))
     return nil;
 #endif
