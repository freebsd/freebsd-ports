--- src/ui/dlgFunction.cpp.orig	Mon Jun 28 00:48:47 2004
+++ src/ui/dlgFunction.cpp	Mon Jun 28 00:49:42 2004
@@ -61,7 +61,7 @@
     EVT_CHECKBOX(XRCID("chkSecureDefiner"),         dlgFunction::OnChange)
     EVT_TEXT(XRCID("txtObjectFile"),                dlgFunction::OnChange)
     EVT_TEXT(XRCID("txtLinkSymbol"),                dlgFunction::OnChange)
-    EVT_STC_MODIFIED(CTL_SQLBOX,                    dlgFunction::OnChange)
+    EVT_STC_MODIFIED(CTL_SQLBOX,                    dlgFunction::OnChangeStyled)
 
     EVT_TEXT(XRCID("cbReturntype"),                 dlgFunction::OnChange)
     EVT_TEXT(XRCID("cbDatatype"),                   dlgFunction::OnSelChangeType)
@@ -251,6 +251,11 @@
     }
 }
 
+
+void dlgFunction::OnChangeStyled(wxStyledTextEvent &ev)
+{
+    OnChange(ev);
+}
 
 void dlgFunction::ReplaceSizer(wxWindow *w, bool isC, int border)
 {
