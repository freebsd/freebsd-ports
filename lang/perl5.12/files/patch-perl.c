$FreeBSD$

--- perl.c.orig	Mon Oct 27 20:32:18 2003
+++ perl.c	Mon Oct 27 20:33:57 2003
@@ -3945,6 +3945,27 @@ S_init_perllib(pTHX)
 /* Use the ~-expanded versions of APPLLIB (undocumented),
     ARCHLIB PRIVLIB SITEARCH SITELIB VENDORARCH and VENDORLIB
 */
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
 #ifdef APPLLIB_EXP
     incpush(APPLLIB_EXP, TRUE, TRUE, TRUE);
 #endif
@@ -3980,27 +4001,6 @@ S_init_perllib(pTHX)
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
