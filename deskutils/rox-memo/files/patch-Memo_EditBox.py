
$FreeBSD$

--- Memo/EditBox.py.orig	Fri Mar 21 21:22:53 2003
+++ Memo/EditBox.py	Fri Mar 21 21:23:23 2003
@@ -74,7 +74,7 @@
 
 		if memo:
 			buffer = self.text.get_buffer()
-			buffer.insert_at_cursor(memo.message, -1)
+			buffer.insert_at_cursor(memo.message)
 		if memo and memo.at:
 			self.at.set_active(TRUE)
 		if memo == None or memo.at == 0:
