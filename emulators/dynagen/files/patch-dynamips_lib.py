--- dynamips_lib.py.orig	Sun Feb 18 17:28:09 2007
+++ dynamips_lib.py	Mon Feb 26 21:05:00 2007
@@ -1411,7 +1411,11 @@
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
