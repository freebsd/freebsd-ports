--- leif/newpy/xaux/aux_so.c	Mon Sep  1 17:42:44 2003
+++ leif/newpy/xaux/aux_so.c	Wed Feb 16 20:42:14 2005
@@ -56,7 +56,7 @@
 
 #define HASH_SIZE 137
 #define ME			"aux_so"
-#define	AUX_EXT			"/usr/lib/im/locale/zh_CN/newpy/aux_win"
+#define	AUX_EXT			(IMDIR "/locale/zh_CN/newpy/aux_win")
 
 typedef struct _aux_icid {
         aux_t *                 aux;
