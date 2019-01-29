--- pybonjour.py.orig	2013-10-02 17:41:05 UTC
+++ pybonjour.py
@@ -1116,7 +1116,7 @@ def DNSServiceRegister(
             type=type(txtRecord)))
 
     if not txtRecord:
-        txtLen, txtRecord = 1, '\0'
+        txtLen, txtRecord = 1, '\0'.encode('utf-8')
     else:
         txtLen, txtRecord = _string_to_length_and_void_p(txtRecord)
 
