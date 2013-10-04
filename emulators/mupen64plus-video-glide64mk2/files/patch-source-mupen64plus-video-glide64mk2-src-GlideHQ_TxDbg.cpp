--- source/mupen64plus-video-glide64mk2/src/GlideHQ/TxDbg.cpp	2013-10-04 03:11:58.000000000 -0500
+++ source/mupen64plus-video-glide64mk2/src/GlideHQ/TxDbg.cpp	2013-10-04 03:16:46.000000000 -0500
@@ -53,7 +53,7 @@
 void
 TxDbg::output(const int level, const wchar_t *format, ...)
 {
-#ifdef _GLIBCXX_HAVE_BROKEN_VSWPRINTF
+#if defined _GLIBCXX_HAVE_BROKEN_VSWPRINTF || defined (__FreeBSD__)
   wchar_t newformat[4095];
 #else
   std::wstring newformat;
@@ -65,8 +65,12 @@
     return;
 
   va_start(args, format);
-#ifdef _GLIBCXX_HAVE_BROKEN_VSWPRINTF
+#if defined _GLIBCXX_HAVE_BROKEN_VSWPRINTF || defined (__FreeBSD__)
+#if defined(__FreeBSD__)
+  swprintf(newformat, sizeof(newformat)/sizeof(*newformat), L"%d:\t", level);
+#else
   swprintf(newformat, L"%d:\t", level);
+#endif
   wcscat(newformat, format);
   vfwprintf(_dbgfile, newformat, args);
 #else
