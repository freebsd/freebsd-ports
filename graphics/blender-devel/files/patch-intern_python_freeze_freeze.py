--- intern/python/freeze/freeze.py.orig	Sat Mar  1 22:57:16 2003
+++ intern/python/freeze/freeze.py	Sat Mar  1 23:10:45 2003
@@ -420,7 +420,7 @@
         outfp.close()
     infp.close()
 
-    cflags = defines + includes + ['$(OPT)']
+    cflags = defines + includes + ['$(OPT)'] + ['%%CFLAGS%%']
     libs = [os.path.join(binlib, 'libpython$(VERSION).a')]
 
     somevars = {}
