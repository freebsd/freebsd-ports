--- leif/newpy/xaux/aux_so.c.orig	Mon May 16 23:20:32 2005
+++ leif/newpy/xaux/aux_so.c	Mon May 16 23:21:59 2005
@@ -56,7 +56,7 @@
 
 #define HASH_SIZE 137
 #define ME			"aux_so"
-#define	AUX_EXT			"/usr/lib/im/locale/zh_CN/newpy/aux_win"
+#define	AUX_EXT			"%%LOCALBASE%%" "/lib/iiim/le/newpy/aux_win"
 
 typedef struct _aux_icid {
         aux_t *                 aux;
