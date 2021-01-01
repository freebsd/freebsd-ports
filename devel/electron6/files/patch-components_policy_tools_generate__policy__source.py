--- components/policy/tools/generate_policy_source.py.orig	2019-09-10 11:13:57 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -86,7 +86,7 @@ class PolicyDetails:
       if platform not in [
           'chrome_frame', 'chrome_os', 'android', 'webview_android',
           'chrome.win', 'chrome.linux', 'chrome.mac', 'chrome.fuchsia',
-          'chrome.*'
+          'chrome.freebsd', 'chrome.*'
       ]:
         raise RuntimeError('Platform "%s" is not supported' % platform)
 
@@ -105,7 +105,7 @@ class PolicyDetails:
       if platform.startswith('chrome.'):
         platform_sub = platform[7:]
         if platform_sub == '*':
-          self.platforms.extend(['win', 'mac', 'linux', 'fuchsia'])
+          self.platforms.extend(['win', 'mac', 'linux', 'fuchsia', 'freebsd'])
         else:
           self.platforms.append(platform_sub)
       else:
