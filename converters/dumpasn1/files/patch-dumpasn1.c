--- dumpasn1.c.orig	2010-09-30 11:17:16.000000000 +0200
+++ dumpasn1.c	2010-09-30 11:18:35.000000000 +0200
@@ -46,6 +46,7 @@
 
 #include <ctype.h>
 #include <limits.h>
+#include <stdarg.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -309,11 +310,13 @@
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
 
