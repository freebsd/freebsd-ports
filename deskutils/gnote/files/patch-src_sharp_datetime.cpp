--- src/sharp/datetime.cpp.orig	2009-12-28 12:46:01.000000000 +0100
+++ src/sharp/datetime.cpp	2010-02-14 15:47:21.000000000 +0100
@@ -69,28 +69,28 @@ namespace sharp {
   int DateTime::day() const
   {
     struct tm result;
-    localtime_r(&m_date.tv_sec, &result);
+    localtime_r((const time_t *)&m_date.tv_sec, &result);
     return result.tm_mday;
   }
 
   int DateTime::month() const
   {
     struct tm result;
-    localtime_r(&m_date.tv_sec, &result);
+    localtime_r((const time_t *)&m_date.tv_sec, &result);
     return result.tm_mon + 1;
   }
 
   int DateTime::year() const
   {
     struct tm result;
-    localtime_r(&m_date.tv_sec, &result);
+    localtime_r((const time_t *)&m_date.tv_sec, &result);
     return result.tm_year + 1900;
   }
 
   int DateTime::day_of_year() const
   {
     struct tm result;
-    localtime_r(&m_date.tv_sec, &result);
+    localtime_r((const time_t *)&m_date.tv_sec, &result);
     return result.tm_yday;
   }
 
@@ -109,14 +109,14 @@ namespace sharp {
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
