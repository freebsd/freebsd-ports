--- perl.c.orig	Fri Apr 22 16:14:27 2005
+++ perl.c	Thu Dec 22 12:47:28 2005
@@ -4397,6 +4397,27 @@ S_init_perllib(pTHX)
     incpush(APPLLIB_EXP, TRUE, TRUE, TRUE);
 #endif
 
+#ifdef SITEARCH_EXP
+    /* sitearch is always relative to sitelib on Windows for
+     * DLL-based path intuition to work correctly */
+#  if !defined(WIN32)
+    incpush(SITEARCH_EXP, FALSE, FALSE, TRUE);
+#  endif
+#endif
+
+#ifdef SITELIB_EXP
+#  if defined(WIN32)
+    /* this picks up sitearch as well */
+    incpush(SITELIB_EXP, TRUE, FALSE, TRUE);
+#  else
+    incpush(SITELIB_EXP, FALSE, FALSE, TRUE);
+#  endif
+#endif
+
+#ifdef SITELIB_STEM /* Search for version-specific dirs below here */
+    incpush(SITELIB_STEM, FALSE, TRUE, TRUE);
+#endif
+
 #ifdef ARCHLIB_EXP
     incpush(ARCHLIB_EXP, FALSE, FALSE, TRUE);
 #endif
@@ -4428,27 +4449,6 @@ S_init_perllib(pTHX)
     incpush(PRIVLIB_EXP, TRUE, FALSE, TRUE);
 #else
     incpush(PRIVLIB_EXP, FALSE, FALSE, TRUE);
-#endif
-
-#ifdef SITEARCH_EXP
-    /* sitearch is always relative to sitelib on Windows for
-     * DLL-based path intuition to work correctly */
-#  if !defined(WIN32)
-    incpush(SITEARCH_EXP, FALSE, FALSE, TRUE);
-#  endif
-#endif
-
-#ifdef SITELIB_EXP
-#  if defined(WIN32)
-    /* this picks up sitearch as well */
-    incpush(SITELIB_EXP, TRUE, FALSE, TRUE);
-#  else
-    incpush(SITELIB_EXP, FALSE, FALSE, TRUE);
-#  endif
-#endif
-
-#ifdef SITELIB_STEM /* Search for version-specific dirs below here */
-    incpush(SITELIB_STEM, FALSE, TRUE, TRUE);
 #endif
 
 #ifdef PERL_VENDORARCH_EXP
