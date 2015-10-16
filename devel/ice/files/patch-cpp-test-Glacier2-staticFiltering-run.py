--- cpp/test/Glacier2/staticFiltering/run.py.orig	2015-06-23 17:30:20.000000000 +0200
+++ cpp/test/Glacier2/staticFiltering/run.py	2015-09-22 16:23:30.270288987 +0200
@@ -8,7 +8,7 @@
 #
 # **********************************************************************
 
-import os, sys, time, socket
+import os, sys, time, socket, subprocess
 
 path = [ ".", "..", "../..", "../../..", "../../../.." ]
 head = os.path.dirname(sys.argv[0])
@@ -99,12 +99,26 @@
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
 
+if limitedTests:
+    print("Running limited tests")
+
 testcases = [
         ('testing category filter',
                 ('', '', '', 'foo "a cat with spaces"', '', ''),
