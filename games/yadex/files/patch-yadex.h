--- src/yadex.h.orig	Sat Jan  1 14:23:40 2005
+++ src/yadex.h	Sat Jan  1 14:23:50 2005
@@ -95,13 +95,13 @@
 #define F_I16_D "hd"
 #define F_I16_H "hX"
 
-typedef unsigned long  u32;
-#define F_U32_D "lu"
-#define F_U32_H "lX"
+typedef unsigned int  u32;
+#define F_U32_D "u"
+#define F_U32_H "X"
 
-typedef signed   long  i32;
-#define F_I32_D "ld"
-#define F_I32_H "lX"
+typedef signed   int  i32;
+#define F_I32_D "d"
+#define F_I32_H "X"
 
 
 /*
