--- src/sharp/datetime.cpp.orig	2009-07-21 22:13:30.000000000 -0500
+++ src/sharp/datetime.cpp	2009-07-21 22:25:29.000000000 -0500
@@ -69,14 +69,14 @@
   int DateTime::year() const
   {
     struct tm result;
-    localtime_r(&m_date.tv_sec, &result);
+    localtime_r((const time_t *)&m_date.tv_sec, &result);
     return result.tm_year;
   }
 
   int DateTime::day_of_year() const
   {
     struct tm result;
-    localtime_r(&m_date.tv_sec, &result);
+    localtime_r((const time_t *)&m_date.tv_sec, &result);
     return result.tm_yday;
   }
 
@@ -95,14 +95,14 @@
   std::string DateTime::to_string(const char * format) const
   {
     struct tm result; 
-    return _to_string(format, localtime_r(&m_date.tv_sec, &result));
+    return _to_string(format, localtime_r((const time_t *)&m_date.tv_sec, &result));
   }
 
 
   std::string DateTime::to_short_time_string() const
   {
     struct tm result;
-    return _to_string("%R", localtime_r(&m_date.tv_sec, &result));
+    return _to_string("%R", localtime_r((const time_t *)&m_date.tv_sec, &result));
   }
 
   std::string DateTime::to_iso8601() const
