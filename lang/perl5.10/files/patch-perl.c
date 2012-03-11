--- perl.c
+++ perl.c
 #else /* IAMSUID */
@@ -4882,6 +4882,28 @@
     incpush(APPLLIB_EXP, TRUE, TRUE, TRUE, TRUE);
 #endif
 
+#ifdef SITEARCH_EXP
+    /* sitearch is always relative to sitelib on Windows for
+     * DLL-based path intuition to work correctly */
+#  if !defined(WIN32)
+    incpush(SITEARCH_EXP, FALSE, FALSE, TRUE, TRUE);
+#  endif
+#endif
+
+#ifdef SITELIB_EXP
+#  if defined(WIN32)
+    /* this picks up sitearch as well */
+    incpush(SITELIB_EXP, TRUE, FALSE, TRUE, TRUE);
+#  else
+    incpush(SITELIB_EXP, FALSE, FALSE, TRUE, TRUE);
+#  endif
+#endif
+
+#if defined(SITELIB_STEM) && defined(PERL_INC_VERSION_LIST)
+    /* Search for version-specific dirs below here */
+    incpush(SITELIB_STEM, FALSE, TRUE, TRUE, TRUE);
+#endif
+
 #ifdef ARCHLIB_EXP
     incpush(ARCHLIB_EXP, FALSE, FALSE, TRUE, TRUE);
 #endif
@@ -4915,28 +4937,6 @@
     incpush(PRIVLIB_EXP, FALSE, FALSE, TRUE, TRUE);
 #endif
 
-#ifdef SITEARCH_EXP
-    /* sitearch is always relative to sitelib on Windows for
-     * DLL-based path intuition to work correctly */
-#  if !defined(WIN32)
-    incpush(SITEARCH_EXP, FALSE, FALSE, TRUE, TRUE);
-#  endif
-#endif
-
-#ifdef SITELIB_EXP
-#  if defined(WIN32)
-    /* this picks up sitearch as well */
-    incpush(SITELIB_EXP, TRUE, FALSE, TRUE, TRUE);
-#  else
-    incpush(SITELIB_EXP, FALSE, FALSE, TRUE, TRUE);
-#  endif
-#endif
-
-#if defined(SITELIB_STEM) && defined(PERL_INC_VERSION_LIST)
-    /* Search for version-specific dirs below here */
-    incpush(SITELIB_STEM, FALSE, TRUE, TRUE, TRUE);
-#endif
-
 #ifdef PERL_VENDORARCH_EXP
     /* vendorarch is always relative to vendorlib on Windows for
      * DLL-based path intuition to work correctly */
