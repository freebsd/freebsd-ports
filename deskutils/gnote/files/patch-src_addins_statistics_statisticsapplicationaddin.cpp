--- src/addins/statistics/statisticsapplicationaddin.cpp.orig	2015-11-28 15:44:34 UTC
+++ src/addins/statistics/statisticsapplicationaddin.cpp
@@ -44,7 +44,7 @@ void StatisticsApplicationAddin::initial
 {
   if(!m_initialized) {
     m_initialized = true;
-    if(m_action == 0) {
+    if(!m_action) {
       m_action = Gtk::Action::create();
       m_action->set_name("ShowStatistics");
       m_action->set_label(_("Show Statistics"));
