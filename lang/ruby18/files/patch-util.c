--- util.c.orig	Sun Mar  4 17:20:24 2007
+++ util.c	Tue May 22 22:25:13 2007
@@ -683,8 +683,8 @@
  *
  */
 
-#define MDMINEXPT DBL_MIN_EXP
-#define MDMAXEXPT DBL_MAX_EXP
+#define MDMINEXPT DBL_MIN_10_EXP
+#define MDMAXEXPT DBL_MAX_10_EXP
 
 static const
 double powersOf10[] = { 	/* Table giving binary powers of 10.  Entry */
