--- dumpasn1.c.orig	2022-01-19 14:05:40 UTC
+++ dumpasn1.c
@@ -382,11 +382,13 @@ static OIDINFO *oidList = NULL;
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
 
