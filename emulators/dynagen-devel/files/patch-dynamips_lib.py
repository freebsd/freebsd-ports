--- dynamips_lib.py.orig	Thu Sep 13 20:41:38 2007
+++ dynamips_lib.py	Thu Sep 13 20:43:22 2007
@@ -1681,7 +1681,11 @@
             flag = '1'
         else:
             flag = '0'
-        send(self.__d, 'vm set_sparse_mem %s %s' % (self.__name, flag))
+
+	# Workaround for "*** Error: Unknown command 'set_sparse_mem'" message
+	# with dynamips-0.2.5.
+	if flag == 1:
+        	send(self.__d, 'vm set_sparse_mem %s %s' % (self.__name, flag))
 
     def __getsparsemem(self):
         """ Returns the sparsemem
