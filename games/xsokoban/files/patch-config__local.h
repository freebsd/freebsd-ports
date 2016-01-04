--- config_local.h.orig	1996-10-29 19:44:31 UTC
+++ config_local.h
@@ -61,7 +61,7 @@
 #define LOCALTIME_PROTO 1
 
 /* Is there a nl_langinfo() call? */
-#define HAVE_NL_LANGINFO 1
+#undef HAVE_NL_LANGINFO
 
 /* Is there a working <sys/param.h> */
 #define HAVE_SYS_PARAM_H 1
