--- perl.c.orig	Sun Mar 28 02:49:17 1999
+++ perl.c	Wed Oct  1 22:29:46 2003
@@ -2701,6 +2768,18 @@
 /* Use the ~-expanded versions of APPLLIB (undocumented),
     ARCHLIB PRIVLIB SITEARCH and SITELIB 
 */
+#ifdef SITEARCH_EXP
+    incpush(SITEARCH_EXP, FALSE);
+#endif
+#ifdef SITELIB_EXP
+#if defined(WIN32) 
+    incpush(SITELIB_EXP, TRUE);
+#else
+    incpush(SITELIB_EXP, FALSE);
+#endif
+#endif
+    if (!PL_tainting)
+	incpush(".", FALSE);
 #ifdef APPLLIB_EXP
     incpush(APPLLIB_EXP, TRUE);
 #endif
@@ -2716,19 +2795,6 @@
 #else
     incpush(PRIVLIB_EXP, FALSE);
 #endif
-
-#ifdef SITEARCH_EXP
-    incpush(SITEARCH_EXP, FALSE);
-#endif
-#ifdef SITELIB_EXP
-#if defined(WIN32) 
-    incpush(SITELIB_EXP, TRUE);
-#else
-    incpush(SITELIB_EXP, FALSE);
-#endif
-#endif
-    if (!PL_tainting)
-	incpush(".", FALSE);
 }
 
 #if defined(DOSISH)
