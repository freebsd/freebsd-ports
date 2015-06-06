--- libguile/gen-scmconfig.c.orig	2010-12-13 17:25:01 UTC
+++ libguile/gen-scmconfig.c
@@ -123,6 +123,7 @@
 
 #include <libguile/gen-scmconfig.h>
 
+#define _ANSI_SOURCE
 #include <stdio.h>
 #include <string.h>
 
