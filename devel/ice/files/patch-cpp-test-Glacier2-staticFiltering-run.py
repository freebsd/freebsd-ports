--- cpp/test/Glacier2/staticFiltering/run.py.orig	2019-08-12 19:54:18 UTC
+++ cpp/test/Glacier2/staticFiltering/run.py
@@ -8,7 +8,7 @@
 #
 # **********************************************************************
 
-import os, sys, time, socket
+import os, sys, time, socket, subprocess
 
 path = [ ".", "..", "../..", "../../..", "../../../.." ]
 head = os.path.dirname(sys.argv[0])
@@ -99,11 +99,25 @@ try:
         hostname = "127.0.0.1"
         fqdn = ""
         domainname = ""
+
+    # Check if IP addresses are configured on a local interface
+    if TestUtil.isFreeBSD():
+        p = subprocess.Popen("ifconfig", shell=1, stdout=subprocess.PIPE)
+        r = p.communicate()[0]
+        if r.find("inet " + testaddr1) == -1 or r.find("inet " + testaddr2) == 1:
+            print("Warning: Not all host IP addresses are available")
+            limitedTests = True
+            hostname = "127.0.0.1"
+            fqdn = ""
+            domainname = ""
 except:
     limitedTests = True
     hostname = "127.0.0.1"
     fqdn = ""
     domainname = ""
+
+if limitedTests:
+    print("Running limited tests")
 
 testcases = [
         ('testing category filter',
