--- sope-core/EOControl/common.h.orig	2015-09-16 18:26:49 UTC
+++ sope-core/EOControl/common.h
@@ -40,10 +40,11 @@
 #  endif
 #endif
 
-#if __GNU_LIBOBJC__ >= 20100911
+#if (defined(__GNU_LIBOBJC__) && (__GNU_LIBOBJC__ >= 20100911)) || defined(APPLE_RUNTIME) || defined(__GNUSTEP_RUNTIME__)
 #  ifndef sel_eq
 #    define sel_eq(__A__,__B__) sel_isEqual(__A__,__B__)
 #  endif
+#  define sel_get_any_uid(__XXX__) sel_getUid(__XXX__)
 #endif
 
 #ifndef ASSIGN
