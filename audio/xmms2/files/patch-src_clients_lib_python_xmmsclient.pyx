--- src/clients/lib/python/xmmsclient.pyx.orig	Tue May 23 01:02:46 2006
+++ src/clients/lib/python/xmmsclient.pyx	Tue May 23 01:03:14 2006
@@ -273,7 +273,8 @@
 						if k[1] == item:
 							return v
 				try:
-					return dict.__getitem__(self, (src, item))
+					x = dict.__getitem__(self, (src, item))
+					return x
 				except KeyError:
 					pass
 			raise KeyError, item
