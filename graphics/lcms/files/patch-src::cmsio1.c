--- src/cmsio1.c.orig	Sat Jun 26 12:31:18 2004
+++ src/cmsio1.c	Sat Jun 26 12:33:04 2004
@@ -72,7 +72,7 @@
 // ------------------- implementation -----------------------------------
 
 
-#define ALIGNLONG(x) (((x)+3) & ~(3))         // Aligns to DWORD boundary
+#define ALIGNLONG(x) (((x)+sizeof(long)-1) & ~(sizeof(long)-1))         // Aligns to DWORD boundary
 
 static size_t UsedSpace;            // Using this makes writting of profiles non-reentrant!
 static int    GlobalLanguageCode;   // Language & country descriptors, for ICC 4.0 support
