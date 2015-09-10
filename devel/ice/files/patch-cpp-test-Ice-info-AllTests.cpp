--- cpp.orig/test/Ice/info/AllTests.cpp	2015-01-23 12:42:09.819774063 +0000
+++ cpp/test/Ice/info/AllTests.cpp	2015-01-23 12:42:59.341774435 +0000
@@ -157,7 +157,7 @@
         test(info->adapterName.empty());
         test(info->localPort > 0);
         test(info->remotePort == 12010);
-        if(defaultHost == "127.0.0.1")
+        if(defaultHost == "127.0.0.1" && !inFreeBSDJail())
         {
             test(info->remoteAddress == defaultHost);
             test(info->localAddress == defaultHost);
@@ -182,7 +182,7 @@
         test(info->adapterName.empty());
         test(info->localPort > 0);
         test(info->remotePort == 12010);
-        if(defaultHost == "127.0.0.1")
+        if(defaultHost == "127.0.0.1" && !inFreeBSDJail())
         {
             test(info->remoteAddress == defaultHost);
             test(info->localAddress == defaultHost);
