--- ui/base/accelerators/global_accelerator_listener/global_accelerator_listener_ozone.cc.orig	2025-11-02 19:17:57 UTC
+++ ui/base/accelerators/global_accelerator_listener/global_accelerator_listener_ozone.cc
@@ -12,7 +12,7 @@
 #include "ui/base/accelerators/accelerator.h"
 #include "ui/ozone/public/ozone_platform.h"
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 #include "base/environment.h"
 #include "base/feature_list.h"
 #include "base/nix/xdg_util.h"
@@ -23,7 +23,7 @@ namespace {
 using content::BrowserThread;
 
 namespace {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
 BASE_FEATURE(kGlobalShortcutsPortal, base::FEATURE_ENABLED_BY_DEFAULT);
 constexpr char kChannelEnvVar[] = "CHROME_VERSION_EXTRA";
 
@@ -73,7 +73,7 @@ GlobalAcceleratorListener* GlobalAcceleratorListener::
     return instance->get();
   }
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS)
   // ListShortcuts on GNOME will return an empty list when the session is
   // created, making this class incorrectly believe it must rebind all
   // shortcuts, leading to a dialog shown on every browser start.
