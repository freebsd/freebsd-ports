--- pybonjour.py.orig	2017-12-05 12:29:04.005301000 -0500
+++ pybonjour.py	2017-12-05 12:29:21.721981000 -0500
@@ -1116,7 +1116,7 @@
             type=type(txtRecord)))
 
     if not txtRecord:
-        txtLen, txtRecord = 1, '\0'
+        txtLen, txtRecord = 1, '\0'.encode('utf-8')
     else:
         txtLen, txtRecord = _string_to_length_and_void_p(txtRecord)
 
