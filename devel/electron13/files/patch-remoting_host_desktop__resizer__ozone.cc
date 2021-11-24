--- remoting/host/desktop_resizer_ozone.cc.orig	2021-01-07 00:36:39 UTC
+++ remoting/host/desktop_resizer_ozone.cc
@@ -32,7 +32,7 @@ void DesktopResizerOzone::RestoreResolution(const Scre
 // To avoid multiple definitions when use_x11 && use_ozone is true, disable this
 // factory method for OS_LINUX as Linux has a factory method that decides what
 // desktopresizer to use based on IsUsingOzonePlatform feature flag.
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 std::unique_ptr<DesktopResizer> DesktopResizer::Create() {
   return base::WrapUnique(new DesktopResizerOzone);
 }
