--- electron/shell/browser/ui/views/menu_bar.cc.orig	2025-05-07 07:36:13 UTC
+++ electron/shell/browser/ui/views/menu_bar.cc
@@ -14,7 +14,7 @@
 #include "ui/views/background.h"
 #include "ui/views/layout/box_layout.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/gtk/gtk_util.h"  // nogncheck
 #endif
 
@@ -213,7 +213,7 @@ void MenuBar::RefreshColorCache(const ui::NativeTheme*
 
 void MenuBar::RefreshColorCache(const ui::NativeTheme* theme) {
   if (theme) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     background_color_ = gtk::GetBgColor("GtkMenuBar#menubar");
     enabled_color_ =
         gtk::GetFgColor("GtkMenuBar#menubar GtkMenuItem#menuitem GtkLabel");
@@ -239,7 +239,7 @@ void MenuBar::UpdateViewColors() {
 }
 
 void MenuBar::UpdateViewColors() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // set menubar background color
   SetBackground(views::CreateSolidBackground(background_color_));
 #endif
@@ -247,7 +247,7 @@ void MenuBar::UpdateViewColors() {
   // set child colors
   if (menu_model_ == nullptr)
     return;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const auto& textColor =
       window_->IsFocused() ? enabled_color_ : disabled_color_;
   for (views::View* child : GetChildrenInZOrder()) {
