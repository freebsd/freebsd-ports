--- lib/Logger/LogAppenderSyslog.cpp.orig	2018-04-12 15:37:36 UTC
+++ lib/Logger/LogAppenderSyslog.cpp
@@ -62,7 +62,7 @@ LogAppenderSyslog::LogAppenderSyslog(std
   if ('0' <= facility[0] && facility[0] <= '9') {
     value = StringUtils::int32(facility);
   } else {
-    CODE* ptr = reinterpret_cast<CODE*>(facilitynames);
+    const CODE* ptr = reinterpret_cast<const CODE*>(facilitynames);
 
     while (ptr->c_name != 0) {
       if (strcmp(ptr->c_name, facility.c_str()) == 0) {
