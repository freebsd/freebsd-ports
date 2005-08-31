--- libfakesql.h.orig	Sat Aug 20 16:16:01 2005
+++ libfakesql.h	Sat Aug 20 16:00:18 2005
@@ -47,6 +47,14 @@
 
 ///////////////////////////////////////////////////////////////////////////////
 
+#ifndef FALSE
+#define FALSE 0
+#endif
+
+#ifndef TRUE
+#define TRUE 1
+#endif
+
 #define NAME_LEN		64		/* Field/table name length */
 #define HOSTNAME_LENGTH		60
 #define USERNAME_LENGTH		16
