--- src/ui/dlgView.cpp.orig	Mon Jun 28 00:52:41 2004
+++ src/ui/dlgView.cpp	Mon Jun 28 00:53:38 2004
@@ -36,7 +36,7 @@
 BEGIN_EVENT_TABLE(dlgView, dlgSecurityProperty)
     EVT_TEXT(XRCID("txtName"),                      dlgView::OnChange)
     EVT_TEXT(XRCID("txtComment"),                   dlgView::OnChange)
-    EVT_STC_MODIFIED(CTL_SQLBOX,                    dlgView::OnChange)
+    EVT_STC_MODIFIED(CTL_SQLBOX,                    dlgView::OnChangeStyled)
 END_EVENT_TABLE();
 
 
@@ -117,6 +117,12 @@
 
         EnableOK(enable);
     }
+}
+
+
+void dlgView::OnChangeStyled(wxStyledTextEvent &ev)
+{
+    OnChange(ev);
 }
 
 
