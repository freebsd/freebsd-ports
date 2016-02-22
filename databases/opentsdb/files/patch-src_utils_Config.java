--- src/utils/Config.java.orig	2016-02-15 22:56:56 UTC
+++ src/utils/Config.java
@@ -562,6 +562,7 @@ public class Config {
     } else {
       file_locations.add("/etc/opentsdb.conf");
       file_locations.add("/etc/opentsdb/opentsdb.conf");
+      file_locations.add("%%PREFIX%%/etc/opentsdb/opentsdb.conf");
       file_locations.add("/opt/opentsdb/opentsdb.conf");
     }
 
