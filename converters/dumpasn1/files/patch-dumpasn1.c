--- dumpasn1.c.orig	Tue Nov 15 12:12:53 2005
+++ dumpasn1.c	Tue Nov 15 12:13:06 2005
@@ -297,11 +297,13 @@
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
 
