--- src/include/dlgFunction.h.orig	Mon Jun 28 00:49:55 2004
+++ src/include/dlgFunction.h	Mon Jun 28 00:50:16 2004
@@ -33,6 +33,7 @@
     pgFunction *function;
 
     void OnChange(wxNotifyEvent &ev);
+    void OnChangeStyled(wxStyledTextEvent &ev);
     void OnSelChangeLanguage(wxNotifyEvent &ev);
     void OnSelChangeArg(wxNotifyEvent &ev);
     void OnSelChangeType(wxNotifyEvent &ev);
