--- src/cmscgats.c.orig	Sat Jun 26 12:31:08 2004
+++ src/cmscgats.c	Sat Jun 26 12:33:13 2004
@@ -89,7 +89,7 @@
 // ------------------------------------------------------------- Implementation
 
 
-#define ALIGNLONG(x) (((x)+3) & ~(3))         // Aligns to DWORD boundary
+#define ALIGNLONG(x) (((x)+sizeof(long)-1) & ~(sizeof(long)-1))         // Aligns to DWORD boundary
 
 // #define STRICT_CGATS  1
 
