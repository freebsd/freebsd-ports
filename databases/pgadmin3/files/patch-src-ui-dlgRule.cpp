--- src/ui/dlgRule.cpp.orig	Mon Jun 28 00:57:12 2004
+++ src/ui/dlgRule.cpp	Mon Jun 28 00:57:52 2004
@@ -47,7 +47,7 @@
     EVT_CHECKBOX(XRCID("chkDelete"),                dlgRule::OnChange)
     EVT_CHECKBOX(XRCID("chkDoInstead"),             dlgRule::OnChange)
     EVT_RADIOBOX(XRCID("rbxEvent"),                 dlgRule::OnChange)
-    EVT_STC_MODIFIED(CTL_SQLBOX,                    dlgRule::OnChange)
+    EVT_STC_MODIFIED(CTL_SQLBOX,                    dlgRule::OnChangeStyled)
 END_EVENT_TABLE();
 
 
@@ -166,6 +166,12 @@
 
         EnableOK(enable);
     }
+}
+
+
+void dlgRule::OnChangeStyled(wxStyledTextEvent &ev)
+{
+    OnChange(ev);
 }
 
 
