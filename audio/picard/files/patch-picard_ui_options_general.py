Disable checking for updates by default.

--- picard/ui/options/general.py.orig	2023-10-12 06:54:36 UTC
+++ picard/ui/options/general.py
@@ -71,7 +71,7 @@ class GeneralOptionsPage(OptionsPage):
         TextOption('persist', 'oauth_access_token', ''),
         IntOption('persist', 'oauth_access_token_expires', 0),
         TextOption('persist', 'oauth_username', ''),
-        BoolOption('setting', 'check_for_updates', True),
+        BoolOption('setting', 'check_for_updates', False),
         IntOption('setting', 'update_check_days', 7),
         IntOption('setting', 'update_level', DEFAULT_PROGRAM_UPDATE_LEVEL),
         IntOption('persist', 'last_update_check', 0),
