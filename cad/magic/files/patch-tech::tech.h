--- tech/tech.h.orig	Tue Dec  9 16:42:58 2003
+++ tech/tech.h	Tue Dec  9 16:43:01 2003
@@ -23,4 +23,4 @@
 /* ----------------- Exported variables and procedures ---------------- */
 
 extern char *TechDefault;	/* Name of default technology */
-extern void TechError();
+extern void TechError(char *fmt, ...);
