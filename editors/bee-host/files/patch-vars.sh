--- vars.sh.orig	2022-04-07 09:03:56 UTC
+++ vars.sh
@@ -45,8 +45,8 @@ case "$kernel" in
   *)
     if [ $EUID == 0 ]; then
       # If superuser
-      chrome_target_manifest_dir='/etc/opt/chrome/native-messaging-hosts'
-      firefox_target_manifest_dir='/usr/lib/mozilla/native-messaging-hosts'
+      chrome_target_manifest_dir='%%LOCALBASE%%/chrome/native-messaging-hosts'
+      firefox_target_manifest_dir='%%LOCALBASE%%/lib/mozilla/native-messaging-hosts'
     else
       # If normal user
       chrome_target_manifest_dir="$HOME/.config/google-chrome/NativeMessagingHosts"
