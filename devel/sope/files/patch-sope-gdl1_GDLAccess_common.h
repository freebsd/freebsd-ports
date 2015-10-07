--- sope-gdl1/GDLAccess/common.h.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/GDLAccess/common.h
@@ -55,7 +55,7 @@
 #  endif
 #endif
 
-#if __GNU_LIBOBJC__ >= 20100911
+#if (defined(__GNU_LIBOBJC__) && (__GNU_LIBOBJC__ >= 20100911)) || defined(__GNUSTEP_RUNTIME__)
 #  define sel_eq(__A__,__B__) sel_isEqual(__A__,__B__)
 #  ifndef SEL_EQ
 #    define SEL_EQ(__A__,__B__) sel_isEqual(__A__,__B__)
