--- vim.h.orig	2007-05-12 11:53:29.000000000 +0200
+++ vim.h	2008-08-04 22:52:27.000000000 +0200
@@ -355,16 +355,19 @@
  * On Win64 longs are 32 bit and pointers 64 bit.
  * For printf() and scanf() we need to take care of long_u specifically. */
 #ifdef _WIN64
-typedef unsigned __int64 long_u;
-typedef		 __int64 long_i;
-# define SCANF_HEX_LONG_U  "%Ix"
-# define PRINTF_HEX_LONG_U "0x%Ix"
-#else
-typedef unsigned long	long_u;
-typedef		 long	long_i;
-# define SCANF_HEX_LONG_U  "%lx"
-# define PRINTF_HEX_LONG_U "0x%lx"
+typedef unsigned __int64        long_u;
+typedef		 __int64        long_i;
+# define SCANF_HEX_LONG_U       "%Ix"
+# define SCANF_DECIMAL_LONG_U   "%Iu"
+# define PRINTF_HEX_LONG_U      "0x%Ix"
+#else
+typedef unsigned long	        long_u;
+typedef		 long	        long_i;
+# define SCANF_HEX_LONG_U       "%lx"
+# define SCANF_DECIMAL_LONG_U   "%lu"
+# define PRINTF_HEX_LONG_U      "0x%lx"
 #endif
+#define PRINTF_DECIMAL_LONG_U SCANF_DECIMAL_LONG_U
 
 /*
  * The characters and attributes cached for the screen.
