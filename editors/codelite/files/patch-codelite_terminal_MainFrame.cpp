--- codelite_terminal/MainFrame.cpp.orig	2014-01-22 16:15:29.000000000 +0100
+++ codelite_terminal/MainFrame.cpp	2014-01-22 16:17:57.000000000 +0100
@@ -8,7 +8,12 @@
 #include <wx/filedlg.h>
 
 #ifndef __WXMSW__
-#if defined(__WXGTK__)
+#if defined(__FreeBSD__)
+#   include <sys/types.h>
+#   include <sys/ioctl.h>
+#   include <termios.h>
+#   include <libutil.h>
+#elif defined(__WXGTK__)
 #   include <pty.h>
 #else
 #   include <util.h>
