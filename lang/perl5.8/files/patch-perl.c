$FreeBSD$

--- perl.c.orig	Sun Jun  2 12:29:01 2002
+++ perl.c	Sun Jun  2 12:30:14 2002
@@ -3407,6 +3407,26 @@
 #endif /* VMS */
     }
 
+#ifdef SITEARCH_EXP
+    /* sitearch is always relative to sitelib on Windows for
+     * DLL-based path intuition to work correctly */
+#  if !defined(WIN32)
+    incpush(SITEARCH_EXP, FALSE, FALSE);
+#  endif
+#endif
+
+#ifdef SITELIB_EXP
+#  if defined(WIN32)
+    incpush(SITELIB_EXP, TRUE, FALSE);	/* this picks up sitearch as well */
+#  else
+    incpush(SITELIB_EXP, FALSE, FALSE);
+#  endif
+#endif
+
+#ifdef SITELIB_STEM /* Search for version-specific dirs below here */
+    incpush(SITELIB_STEM, FALSE, TRUE);
+#endif
+
 /* Use the ~-expanded versions of APPLLIB (undocumented),
     ARCHLIB PRIVLIB SITEARCH SITELIB VENDORARCH and VENDORLIB
 */
@@ -3445,26 +3465,6 @@
     incpush(PRIVLIB_EXP, TRUE, FALSE);
 #else
     incpush(PRIVLIB_EXP, FALSE, FALSE);
-#endif
-
-#ifdef SITEARCH_EXP
-    /* sitearch is always relative to sitelib on Windows for
-     * DLL-based path intuition to work correctly */
-#  if !defined(WIN32)
-    incpush(SITEARCH_EXP, FALSE, FALSE);
-#  endif
-#endif
-
-#ifdef SITELIB_EXP
-#  if defined(WIN32)
-    incpush(SITELIB_EXP, TRUE, FALSE);	/* this picks up sitearch as well */
-#  else
-    incpush(SITELIB_EXP, FALSE, FALSE);
-#  endif
-#endif
-
-#ifdef SITELIB_STEM /* Search for version-specific dirs below here */
-    incpush(SITELIB_STEM, FALSE, TRUE);
 #endif
 
 #ifdef PERL_VENDORARCH_EXP
