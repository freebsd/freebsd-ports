--- nxt_python/build/nxt-python-1.1.2/nxt/usbsock.py.orig	2009-11-20 15:11:58.000000000 +0100
+++ nxt_python/build/nxt-python-1.1.2/nxt/usbsock.py	2010-12-14 20:07:30.000000000 +0100
@@ -41,7 +41,6 @@
 		self.handle = self.device.open()
 		self.handle.setConfiguration(1)
 		self.handle.claimInterface(0)
-		self.handle.reset()
 		if self.debug:
                         print 'Connected.'
 		return Brick(self)
