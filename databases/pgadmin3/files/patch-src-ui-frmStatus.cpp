--- src/ui/frmStatus.cpp.orig	Mon Jun 28 01:15:25 2004
+++ src/ui/frmStatus.cpp	Mon Jun 28 01:25:17 2004
@@ -26,9 +26,9 @@
 BEGIN_EVENT_TABLE(frmStatus, wxDialog)
     EVT_BUTTON(XRCID("btnRefresh"),         frmStatus::OnRefresh)
     EVT_BUTTON (XRCID("btnClose"),          frmStatus::OnClose)
-    EVT_SPINCTRL(XRCID("spnRefreshRate"),   frmStatus::OnRateChange)
+    EVT_SPINCTRL(XRCID("spnRefreshRate"),   frmStatus::OnRateChangeSpin)
     EVT_TEXT(XRCID("spnRefreshRate"),       frmStatus::OnRateChange)
-    EVT_TIMER(TIMER_ID,                     frmStatus::OnRefresh)
+    EVT_TIMER(TIMER_ID,                     frmStatus::OnRefreshTimer)
 END_EVENT_TABLE();
 
 
@@ -112,6 +112,11 @@
 }
 
 
+void frmStatus::OnRateChangeSpin(wxSpinEvent &event)
+{
+    OnRateChangeSpin(event);
+}
+
 
 void frmStatus::OnRefresh(wxCommandEvent &event)
 {
@@ -158,4 +163,12 @@
             dataSet->MoveNext();
         }
     }
+}
+
+
+void frmStatus::OnRefreshTimer(wxTimerEvent &event)
+{
+    wxCommandEvent nullEvent;
+
+    OnRefresh(nullEvent);
 }
