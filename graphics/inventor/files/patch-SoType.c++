--- lib/database/src/so/SoType.c++.orig	2011-06-08 14:29:24.000000000 +0200
+++ lib/database/src/so/SoType.c++	2011-06-08 14:29:37.000000000 +0200
@@ -331,7 +331,7 @@
     if (b == NULL)
 	return SoType::badType();
 
-#if (_MIPS_SZPTR == 64 || __ia64)
+#if (_MIPS_SZPTR == 64 || __ia64 || __amd64__)
     SoType result = typeData[(int) ((unsigned long) b)].type;
 #else
     SoType result = typeData[(int)b].type;
