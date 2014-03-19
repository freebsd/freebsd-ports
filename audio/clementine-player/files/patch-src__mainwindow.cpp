--- src/ui/mainwindow.cpp	2013-09-26 04:08:05.000000000 -0700
+++ src/ui/mainwindow.cpp.new	2014-03-19 07:30:06.648733063 -0700
@@ -920,7 +920,7 @@
   if (ui_->action_toggle_scrobbling->isVisible())
     SetToggleScrobblingIcon(value);
 
-  if (!app_->player()->GetState() == Engine::Idle) {
+  if (!(app_->player()->GetState() == Engine::Idle)) {
     return;
   }
   else {
