--- sope-mime/NGImap4/imCommon.h.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGImap4/imCommon.h
@@ -37,13 +37,13 @@
 #include <NGMime/NGMime.h>
 #include <NGMail/NGMail.h>
 
-#if NeXT_RUNTIME || APPLE_RUNTIME
+#if NeXT_RUNTIME
 #  ifndef sel_eq
 #    define sel_eq(__A__,__B__) (__A__==__B__)
 #  endif
 #endif
 
-#if __GNU_LIBOBJC__ >= 20100911
+#if (defined(__GNU_LIBOBJC__) && (__GNU_LIBOBJC__ >= 20100911)) || defined(APPLE_RUNTIME) || defined(__GNUSTEP_RUNTIME__)
 #  ifndef sel_eq
 #    define sel_eq(__A__,__B__) sel_isEqual(__A__,__B__)
 #  endif
