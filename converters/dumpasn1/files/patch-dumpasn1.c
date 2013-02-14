--- dumpasn1.c.orig	2013-02-14 12:03:56.000000000 +0100
+++ dumpasn1.c	2013-02-14 12:13:31.000000000 +0100
@@ -60,6 +60,8 @@
 
 /* Useful defines */
 
+typedef unsigned char	BYTE;
+
 #ifndef TRUE
   #define FALSE	0
   #define TRUE	( !FALSE )
@@ -356,11 +358,13 @@
    beginning with a '$' uses the appropriate environment variable.  In
    addition under Unix we also walk down $PATH looking for it */
 
+#ifndef CONFIG_NAME
 #ifdef __TANDEM_NSK__
   #define CONFIG_NAME		"asn1cfg"
 #else
   #define CONFIG_NAME		"dumpasn1.cfg"
 #endif /* __TANDEM_NSK__ */
+#endif
 
 #if defined( __TANDEM_NSK__ )
 
