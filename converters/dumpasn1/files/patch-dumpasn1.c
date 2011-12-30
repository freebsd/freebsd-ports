--- dumpasn1.c.orig	2010-09-30 11:17:16.000000000 +0200
+++ dumpasn1.c	2010-09-30 11:18:35.000000000 +0200
@@ -309,11 +309,13 @@
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
 
