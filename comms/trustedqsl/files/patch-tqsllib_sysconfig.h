--- tqsllib/sysconfig.h.orig	Wed Jul 21 11:51:59 2004
+++ tqsllib/sysconfig.h	Wed Jul 21 11:54:05 2004
@@ -14,7 +14,7 @@
 /* #undef TM_IN_SYS_TIME */
 
 /* Defined if this is LOTW server code */
-#define LOTW_SERVER 1
+#undef LOTW_SERVER
 
 /* Define if you have the mkdir function.  */
 #define HAVE_MKDIR 1
@@ -29,7 +29,7 @@
 #define HAVE_UNISTD_H 1
 
 /* Define if you have the <getopt.h> header file.  */
-/* #undef HAVE_GETOPT_H */
+#define HAVE_GETOPT_H 
 
 /* Define if you have the crypto library (-lcrypto).  */
 #define HAVE_LIBCRYPTO 1
@@ -38,8 +38,8 @@
 #define HAVE_LIBDL 1
 
 /* Define if you have the pcrl library (-lpcrl).  */
-#define HAVE_LIBPCRL 1
+#undef HAVE_LIBPCRL
 
 /* Define if you have the sqlca library (-lsqlca).  */
-#define HAVE_LIBSQLCA 1
+#undef HAVE_LIBSQLCA 
 
