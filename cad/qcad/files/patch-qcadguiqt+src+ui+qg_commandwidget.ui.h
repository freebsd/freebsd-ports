--- qcadguiqt/src/ui/qg_commandwidget.ui.h.orig	Mon Feb  9 18:16:26 2004
+++ qcadguiqt/src/ui/qg_commandwidget.ui.h	Mon Feb  9 18:17:27 2004
@@ -130,5 +130,5 @@
     std::string s = errBuf.str();
     if (s.length()!=0) {
-        appendHistory(QString("%1").arg(s));
+        appendHistory(QString("%1").arg(s.c_str()));
     }
     //std::cout << "processStderr: OK\n";
