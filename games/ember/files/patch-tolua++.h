--- src/components/lua/tolua++.h.orig	2011-01-19 15:51:08.000000000 +0100
+++ src/components/lua/tolua++.h	2011-01-19 15:51:58.000000000 +0100
@@ -31,4 +31,12 @@
 
 #include <tolua++.h>
 
+#ifndef Mtolua_new
+#define Mtolua_new(EXP) new EXP
+#endif
+
+#ifndef Mtolua_delete
+#define Mtolua_delete(EXP) delete EXP
+#endif
+
 #endif /* EMBER_TOLUA_H_ */
