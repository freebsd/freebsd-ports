--- lib/Logger/LogAppenderSyslog.cpp.orig	2017-11-15 11:23:07 UTC
+++ lib/Logger/LogAppenderSyslog.cpp
@@ -64,7 +64,7 @@ LogAppenderSyslog::LogAppenderSyslog(std
   if ('0' <= facility[0] && facility[0] <= '9') {
     value = StringUtils::int32(facility);
   } else {
-    CODE* ptr = reinterpret_cast<CODE*>(TRI_facilitynames);
+    const CODE* ptr = reinterpret_cast<const CODE*>(TRI_facilitynames);
 
     while (ptr->c_name != 0) {
       if (strcmp(ptr->c_name, facility.c_str()) == 0) {
