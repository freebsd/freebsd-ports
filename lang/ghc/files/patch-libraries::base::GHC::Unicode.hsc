--- libraries/base/GHC/Unicode.hsc.orig	Mon Oct 20 12:12:20 2003
+++ libraries/base/GHC/Unicode.hsc	Mon Jan 12 23:32:22 2004
@@ -112,7 +112,7 @@
 -- -----------------------------------------------------------------------------
 -- Win32 implementation
 
-#if (defined(HAVE_WCTYPE_H) && HAVE_ISWSPACE) || mingw32_TARGET_OS
+#if (defined(HAVE_WCTYPE_H) && HAVE_ISWSPACE && defined(HTYPE_WINT_T)) || mingw32_TARGET_OS
 
 -- Use the wide-char classification functions if available.  Glibc
 -- seems to implement these properly, even for chars > 0xffff, as long
