--- components/policy/tools/generate_policy_source.py.orig	2019-03-15 06:37:17 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -92,7 +92,7 @@ class PolicyDetails:
         raise RuntimeError('is_device_only is only allowed for Chrome OS: "%s"'
                            % p)
       if platform not in ['chrome_frame', 'chrome_os',
-                          'android', 'webview_android',
+                          'android', 'webview_android', 'chrome.bsd',
                           'chrome.win', 'chrome.linux', 'chrome.mac',
                           'chrome.fuchsia', 'chrome.*']:
         raise RuntimeError('Platform "%s" is not supported' % platform)
@@ -112,7 +112,7 @@ class PolicyDetails:
       if platform.startswith('chrome.'):
         platform_sub = platform[7:]
         if platform_sub == '*':
-          self.platforms.extend(['win', 'mac', 'linux', 'fuchsia'])
+          self.platforms.extend(['win', 'mac', 'linux', 'fuchsia', 'freebsd'])
         else:
           self.platforms.append(platform_sub)
       else:
