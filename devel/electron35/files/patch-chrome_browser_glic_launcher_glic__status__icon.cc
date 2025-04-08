--- chrome/browser/glic/launcher/glic_status_icon.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/glic/launcher/glic_status_icon.cc
@@ -84,7 +84,7 @@ GlicStatusIcon::GlicStatusIcon(GlicController* control
   if (!status_icon_) {
     return;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   //  Set a vector icon for proper themeing on Linux.
   status_icon_->SetIcon(
       GlicVectorIconManager::GetVectorIcon(IDR_GLIC_BUTTON_VECTOR_ICON));
@@ -108,7 +108,7 @@ GlicStatusIcon::~GlicStatusIcon() {
 GlicStatusIcon::~GlicStatusIcon() {
   context_menu_ = nullptr;
   if (status_icon_) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     status_icon_->RemoveObserver(this);
 #endif
     std::unique_ptr<StatusIcon> removed_icon =
@@ -196,7 +196,7 @@ std::unique_ptr<StatusIconMenuModel> GlicStatusIcon::C
   menu->AddItem(
       IDC_GLIC_STATUS_ICON_MENU_REMOVE_ICON,
       l10n_util::GetStringUTF16(IDS_GLIC_STATUS_ICON_MENU_REMOVE_ICON));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   menu->AddItem(IDC_GLIC_STATUS_ICON_MENU_EXIT,
                 l10n_util::GetStringUTF16(IDS_GLIC_STATUS_ICON_MENU_EXIT));
 #endif
