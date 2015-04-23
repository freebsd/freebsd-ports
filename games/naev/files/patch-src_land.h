# Origin: https://github.com/naev/naev/commit/9fd2a7dcb3690bc1befe7f9a05d02e204dcfe8a1
# Subject: Avoid regenerating the land tabs over top of themselves

--- src/land.h.orig	2015-03-05 22:11:11 UTC
+++ src/land.h
@@ -46,6 +46,12 @@ extern int landed;
 extern Planet* land_planet;
 
 
+/* Tracking for which tabs have been generated. */
+#define land_tabGenerate(w)       (land_generated |= (1 << w)) /**< Mark tab generated. */
+#define land_tabGenerated(w)     (land_generated & (1 << w)) /**< Check if tab has been generated. */
+extern unsigned int land_generated;
+
+
 /*
  * Main interface.
  */
