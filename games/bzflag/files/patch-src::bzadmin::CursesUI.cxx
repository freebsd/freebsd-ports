--- src/bzadmin/CursesUI.cxx.orig	Tue Dec  9 16:31:33 2003
+++ src/bzadmin/CursesUI.cxx	Thu Dec 11 01:44:31 2003
@@ -232,7 +232,11 @@
 
 
 void CursesUI::handleResize(int lines, int cols) {
+#ifdef __FreeBSD__
+  resizeterm(lines, cols);
+#else
   resize_term(lines, cols);
+#endif
   mvwin(targetWin, lines - 2, 0);
   wresize(targetWin, 1, cols);
   mvwin(cmdWin, lines - 1, 0);
