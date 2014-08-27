--- cpp.orig/test/Glacier2/staticFiltering/run.py	2013-10-04 17:48:14.000000000 +0200
+++ cpp/test/Glacier2/staticFiltering/run.py	2014-08-27 10:17:57.233098328 +0200
@@ -8,7 +8,7 @@
 #
 # **********************************************************************
 
-import os, sys, time, socket
+import os, sys, time, socket, subprocess
 
 path = [ ".", "..", "../..", "../../..", "../../../.." ]
 head = os.path.dirname(sys.argv[0])
@@ -100,6 +100,12 @@
     fqdn = ""
     domainname = ""
 
+print "Network and process debug output:"
+subprocess.call(["/usr/bin/netstat", "-an"])
+subprocess.call(["/bin/ps", "-alxww"])
+subprocess.call(["/usr/bin/sockstat"])
+subprocess.call(["/sbin/ifconfig", "-a"])
+subprocess.call(["/sbin/sysctl", "-a"])
 testcases = [
         ('testing category filter',
                 ('', '', '', 'foo "a cat with spaces"', '', ''),
