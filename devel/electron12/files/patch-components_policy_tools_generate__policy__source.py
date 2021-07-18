--- components/policy/tools/generate_policy_source.py.orig	2021-01-07 00:36:31 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -37,8 +37,9 @@ PLATFORM_STRINGS = {
     'ios': ['ios'],
     'chrome.win': ['win'],
     'chrome.linux': ['linux'],
+    'chrome.freebsd': ['freebsd'],
     'chrome.mac': ['mac'],
-    'chrome.*': ['win', 'mac', 'linux'],
+    'chrome.*': ['win', 'mac', 'linux', 'freebsd'],
     'chrome.win7': ['win']
 }
 
