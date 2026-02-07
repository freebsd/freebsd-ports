--- src/attributes.h.orig	2004-07-27 11:27:56 UTC
+++ src/attributes.h
@@ -67,7 +67,7 @@
 
 #define attribute_inline __inline__
 
-#if GNUC_MINIMUM(2,7) /* doesn't work reliable before, IIRC */
+#if 0
 # define attribute_regparm(x) __attribute__((__regparm__((x))))
 #else
 # define attribute_regparm(x)
