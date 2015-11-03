--- announcefetch.py.orig	2015-06-10 21:49:31 UTC
+++ announcefetch.py
@@ -235,6 +235,8 @@ class AnnounceDataFetcher(object):
             argsMap['os'] = 'win'
          elif OS_LINUX:
             argsMap['os'] = 'lin'
+         elif OS_FREEBSD:
+            argsMap['os'] = 'bsd'
          elif OS_MACOSX:
             argsMap['os'] = 'mac'
          else:
