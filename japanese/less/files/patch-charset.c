--- charset.c.orig	2013-01-20 04:32:52.491037000 +0900
+++ charset.c	2013-01-20 05:05:01.106026675 +0900
@@ -872,6 +872,18 @@
 		return;
 	}
 
+#if HAVE_LOCALE
+	/*
+	 * Use setlocale.
+	 */
+	ilocale();
+#else
+#if MSDOS_COMPILER
+	/*
+	 * Default to "dos".
+	 */
+	(void) icharset("dos");
+#else
 #if HAVE_STRSTR
 	/*
 	 * Check whether LC_ALL, LC_CTYPE or LANG look like UTF-8 is used.
@@ -888,19 +900,6 @@
 				return;
 	}
 #endif
-
-#if HAVE_LOCALE
-	/*
-	 * Use setlocale.
-	 */
-	ilocale();
-#else
-#if MSDOS_COMPILER
-	/*
-	 * Default to "dos".
-	 */
-	(void) icharset("dos");
-#else
 	/*
 	 * All variables are not defined either, default to DEFCHARSET.
 	 * DEFCHARSET is defined in defines.h.
