--- src/keyconfig.cpp.orig	Thu May 23 14:28:24 2002
+++ src/keyconfig.cpp	Tue Dec 16 10:46:21 2003
@@ -46,16 +46,16 @@
 	char *proc;
 	};
 
-#define elk(x,y,z) ((struct keydef) {y,#z})
-#define sym(x) (struct keydef) {x,x}
+#define elk(x,y,z) {y,#z}
+#define sym(x) {x,x}
 #define	LINE {NULL,NULL}
-#define two(name,proc) ((struct keydef) {name,#proc})
+#define two(name,proc) {name,#proc}
 #define elm(x,z) LINE
 //#define elm(x,z)
 //#define	LINE 
 #include "varmacro.h"
 #ifdef OLDGCCVARMACRO
-#define menumake(file,name,els...)		,##els VARMACRO
+#define menumake(file,name,els...)		,els VARMACRO
 #else
 #define menumake(file,name,...)		,__VA_ARGS__
 #endif
