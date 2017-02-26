--- libguile/gen-scmconfig.c.orig	2014-03-16 22:43:13 UTC
+++ libguile/gen-scmconfig.c
@@ -138,6 +138,7 @@
 
 #include <libguile/gen-scmconfig.h>
 
+#define _ANSI_SOURCE
 #include <stdio.h>
 #include <string.h>
 
