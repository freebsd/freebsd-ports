--- src/utils/Config.java.orig	2015-11-04 10:25:48 UTC
+++ src/utils/Config.java
@@ -509,6 +509,7 @@ public class Config {
     } else {
       file_locations.add("/etc/opentsdb.conf");
       file_locations.add("/etc/opentsdb/opentsdb.conf");
+      file_locations.add("%%PREFIX%%/etc/opentsdb/opentsdb.conf");
       file_locations.add("/opt/opentsdb/opentsdb.conf");
     }
 
