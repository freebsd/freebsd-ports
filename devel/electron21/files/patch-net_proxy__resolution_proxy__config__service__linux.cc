--- net/proxy_resolution/proxy_config_service_linux.cc.orig	2022-08-31 12:19:35 UTC
+++ net/proxy_resolution/proxy_config_service_linux.cc
@@ -6,7 +6,9 @@
 
 #include <errno.h>
 #include <limits.h>
+#if !defined(OS_BSD)
 #include <sys/inotify.h>
+#endif
 #include <unistd.h>
 
 #include <map>
@@ -502,6 +504,7 @@ bool SettingGetterImplGSettings::CheckVersion(
 }
 #endif  // defined(USE_GIO)
 
+#if !defined(OS_BSD)
 // Converts |value| from a decimal string to an int. If there was a failure
 // parsing, returns |default_value|.
 int StringToIntOrDefault(base::StringPiece value, int default_value) {
@@ -1030,6 +1033,7 @@ class SettingGetterImplKDE : public ProxyConfigService
   // events on.
   scoped_refptr<base::SequencedTaskRunner> file_task_runner_;
 };
+#endif
 
 }  // namespace
 
@@ -1246,9 +1250,11 @@ ProxyConfigServiceLinux::Delegate::Delegate(
     case base::nix::DESKTOP_ENVIRONMENT_KDE3:
     case base::nix::DESKTOP_ENVIRONMENT_KDE4:
     case base::nix::DESKTOP_ENVIRONMENT_KDE5:
+#if !defined(OS_BSD)
       setting_getter_ =
           std::make_unique<SettingGetterImplKDE>(env_var_getter_.get());
       break;
+#endif
     case base::nix::DESKTOP_ENVIRONMENT_XFCE:
     case base::nix::DESKTOP_ENVIRONMENT_OTHER:
       break;
