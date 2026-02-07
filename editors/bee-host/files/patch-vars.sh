--- vars.sh.orig	2025-05-06 17:29:25 UTC
+++ vars.sh
@@ -47,9 +47,9 @@ case "$kernel" in
   *)
     if [ $EUID == 0 ]; then
       # If superuser
-      chrome_target_manifest_dir='/etc/opt/chrome/native-messaging-hosts'
-      chromium_target_manifest_dir='/etc/chromium/native-messaging-hosts'
-      firefox_target_manifest_dir='/usr/lib/mozilla/native-messaging-hosts'
+      chrome_target_manifest_dir='%%LOCALBASE%%/chrome/native-messaging-hosts'
+      chromium_target_manifest_dir='%%LOCALBASE%%/chromium/native-messaging-hosts'
+      firefox_target_manifest_dir='%%LOCALBASE%%/lib/mozilla/native-messaging-hosts'
     else
       # If normal user
       chrome_target_manifest_dir="$HOME/.config/google-chrome/NativeMessagingHosts"
