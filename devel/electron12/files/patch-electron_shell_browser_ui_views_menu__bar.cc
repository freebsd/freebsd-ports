--- electron/shell/browser/ui/views/menu_bar.cc.orig	2021-04-22 08:42:01 UTC
+++ electron/shell/browser/ui/views/menu_bar.cc
@@ -17,7 +17,7 @@
 #include "ui/views/layout/box_layout.h"
 #include "ui/views/widget/widget.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gtk/gtk_util.h"
 #endif
 
@@ -291,7 +291,7 @@ void MenuBar::ButtonPressed(int id, const ui::Event& e
 void MenuBar::RefreshColorCache() {
   const ui::NativeTheme* theme = GetNativeTheme();
   if (theme) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     background_color_ = gtk::GetBgColor("GtkMenuBar#menubar");
     enabled_color_ =
         gtk::GetFgColor("GtkMenuBar#menubar GtkMenuItem#menuitem GtkLabel");
@@ -329,7 +329,7 @@ void MenuBar::UpdateViewColors() {
   // set child colors
   if (menu_model_ == nullptr)
     return;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const auto& textColor = has_focus_ ? enabled_color_ : disabled_color_;
   for (auto* child : GetChildrenInZOrder()) {
     auto* button = static_cast<SubmenuButton*>(child);
