--- sope-appserver/NGObjWeb/common.h.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/common.h
@@ -51,13 +51,17 @@
 #include <NGExtensions/NGLogging.h>
 #include <NGStreams/NGStreams.h>
 
-#if NeXT_RUNTIME || APPLE_RUNTIME || (__GNU_LIBOBJC__ >= 20100911)
+#if (defined(__GNU_LIBOBJC__) && (__GNU_LIBOBJC__ >= 20100911)) || defined(APPLE_RUNTIME) || defined(__GNUSTEP_RUNTIME__)
 #  ifndef sel_get_name
 #    define sel_get_name(__XXX__)    sel_getName(__XXX__)
 #    define sel_get_any_uid(__XXX__) sel_getUid(__XXX__)
 #  endif
 #endif
 
+#if (defined(__GNU_LIBOBJC__) && (__GNU_LIBOBJC__ >= 20100911)) || defined(APPLE_RUNTIME) || defined(__GNUSTEP_RUNTIME__)
+#    define sel_get_uid(__XXX__)   sel_getUid(__XXX__);
+#endif
+
 #define IS_DEPRECATED \
   [self warnWithFormat:@"used deprecated method: %s:%i.", \
           __PRETTY_FUNCTION__, __LINE__];
