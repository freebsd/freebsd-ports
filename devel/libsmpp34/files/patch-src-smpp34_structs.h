--- src/smpp34_structs.h.orig	2014-07-11 16:04:02.000000000 +0300
+++ src/smpp34_structs.h	2014-07-11 16:02:16.000000000 +0300
@@ -23,6 +23,8 @@
 #ifndef _STB_H_
 #define _STB_H_
 
+#include <sys/types.h>
+
 #define SMALL_BUFF      30
 /* Identify PDUs ident ********************************************************/
 #define MAX_TLV_SIZE         1024
