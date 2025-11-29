--- libdd-library-config/src/lib.rs.orig	2025-02-11 17:46:31 UTC
+++ libdd-library-config/src/lib.rs
@@ -461,14 +461,19 @@ pub enum Target {
 }
 
 pub enum Target {
+    FreeBSD,
     Linux,
     Macos,
     Windows,
 }
 
 impl Target {
-    #[cfg(any(target_os = "linux", target_os = "macos", windows))]
+    #[cfg(any(target_os = "freebsd", target_os = "linux", target_os = "macos", windows))]
     const fn current() -> Self {
+        #[cfg(target_os = "freebsd")]
+        {
+            Self::FreeBSD
+        }
         #[cfg(target_os = "linux")]
         {
             Self::Linux
@@ -485,16 +490,17 @@ impl Configurator {
 }
 
 impl Configurator {
-    #[cfg(any(target_os = "linux", target_os = "macos", windows))]
+    #[cfg(any(target_os = "freebsd", target_os = "linux", target_os = "macos", windows))]
     pub const FLEET_STABLE_CONFIGURATION_PATH: &'static str =
         Self::fleet_stable_configuration_path(Target::current());
 
-    #[cfg(any(target_os = "linux", target_os = "macos", windows))]
+    #[cfg(any(target_os = "freebsd", target_os = "linux", target_os = "macos", windows))]
     pub const LOCAL_STABLE_CONFIGURATION_PATH: &'static str =
         Self::local_stable_configuration_path(Target::current());
 
     pub const fn local_stable_configuration_path(target: Target) -> &'static str {
         match target {
+            Target::FreeBSD => "%%LOCALBASE%%/etc/datadog-agent/application_monitoring.yaml",
             Target::Linux => "/etc/datadog-agent/application_monitoring.yaml",
             Target::Macos => "/opt/datadog-agent/etc/application_monitoring.yaml",
             Target::Windows => "C:\\ProgramData\\Datadog\\application_monitoring.yaml",
@@ -503,6 +509,7 @@ impl Configurator {
 
     pub const fn fleet_stable_configuration_path(target: Target) -> &'static str {
         match target {
+            Target::FreeBSD => "%%LOCALBASE%%/etc/datadog-agent/managed/datadog-agent/stable/application_monitoring.yaml",
             Target::Linux => "/etc/datadog-agent/managed/datadog-agent/stable/application_monitoring.yaml",
             Target::Macos => "/opt/datadog-agent/etc/stable/application_monitoring.yaml",
             Target::Windows => "C:\\ProgramData\\Datadog\\managed\\datadog-agent\\stable\\application_monitoring.yaml",
