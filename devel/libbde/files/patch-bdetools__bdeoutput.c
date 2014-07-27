--- ./bdetools/bdeoutput.c.orig	2014-01-12 17:21:23.000000000 +0000
+++ ./bdetools/bdeoutput.c	2014-07-27 11:10:47.000000000 +0000
@@ -23,6 +23,8 @@
 #include <memory.h>
 #include <types.h>
 
+#include <stdio.h>
+
 #if defined( HAVE_LOCAL_LIBUNA )
 #include <libuna_definitions.h>
 #elif defined( HAVE_LIBUNA_H )
