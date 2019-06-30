--- src/robotide/publish/publisher.py.orig	2019-06-28 07:27:57 UTC
+++ src/robotide/publish/publisher.py
@@ -18,10 +18,10 @@ if PY3:
     from robotide.utils import basestring, unicode
 
 try:
-    from pubsub import Publisher
+    from wx.lib.pubsub import Publisher
     WxPublisher = Publisher()
 except ImportError:
-    from pubsub import pub
+    from wx.lib.pubsub import pub
     WxPublisher = pub.getDefaultPublisher()
 
 
