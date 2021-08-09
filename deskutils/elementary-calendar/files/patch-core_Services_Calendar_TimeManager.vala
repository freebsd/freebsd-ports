--- core/Services/Calendar/TimeManager.vala.orig	2021-07-21 02:56:10 UTC
+++ core/Services/Calendar/TimeManager.vala
@@ -1,4 +1,4 @@
-[DBus (name = "org.freedesktop.login1.Manager")]
+[DBus (name = "org.freedesktop.ConsoleKit.Manager")]
 private interface FDO.LoginManager : Object {
     // Called when computer is going to sleep or waking up.
     // start is true when going to sleep, false when waking up.
@@ -27,7 +27,7 @@ public class Calendar.TimeManager : Object {
         try {
             // Setup login_manager to listen for sleep signal.
             // When computer wakes up (!sleeping), update time.
-            login_manager = Bus.get_proxy_sync (BusType.SYSTEM, "org.freedesktop.login1", "/org/freedesktop/login1");
+            login_manager = Bus.get_proxy_sync (BusType.SYSTEM, "org.freedesktop.ConsoleKit", "/org/freedesktop/ConsoleKit/Manager");
             login_manager.prepare_for_sleep.connect ((sleeping) => {
                 if (!sleeping) {
                     on_update_today ();
