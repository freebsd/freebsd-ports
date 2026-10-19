--- electron/shell/browser/ui/views/menu_bar.cc.orig	2026-10-16 03:32:58 UTC
+++ electron/shell/browser/ui/views/menu_bar.cc
@@ -16,7 +16,7 @@
 #include "ui/views/background.h"
 #include "ui/views/layout/box_layout.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/ui/gtk_util.h"
 #include "ui/gtk/gtk_util.h"  // nogncheck
 #endif
@@ -218,7 +218,7 @@ void MenuBar::RefreshColorCache(const ui::NativeTheme*
 
 void MenuBar::RefreshColorCache(const ui::NativeTheme* theme) {
   if (theme) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (gtk_util::IsGtkAvailable()) {
       background_color_ = gtk::GetBgColor("GtkMenuBar#menubar");
       enabled_color_ =
@@ -254,7 +254,7 @@ void MenuBar::UpdateViewColors() {
 }
 
 void MenuBar::UpdateViewColors() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // set menubar background color
   SetBackground(views::CreateSolidBackground(background_color_));
 #endif
@@ -262,7 +262,7 @@ void MenuBar::UpdateViewColors() {
   // set child colors
   if (menu_model_ == nullptr)
     return;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const auto& textColor =
       window_->IsFocused() ? enabled_color_ : disabled_color_;
   for (views::View* child : GetChildrenInZOrder()) {
