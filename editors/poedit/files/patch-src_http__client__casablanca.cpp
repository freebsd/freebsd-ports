--- src/http_client_casablanca.cpp.orig	2015-08-03 10:49:16 UTC
+++ src/http_client_casablanca.cpp
@@ -30,10 +30,13 @@
 
 #include <boost/algorithm/string/predicate.hpp>
 
+
 #include <cpprest/asyncrt_utils.h>
 #include <cpprest/http_client.h>
 #include <cpprest/http_msg.h>
 #include <cpprest/filestream.h>
+#include <sstream>
+
 
 #ifdef _WIN32
     #include <windows.h>
@@ -66,6 +69,14 @@ struct json_dict::native
     }
 };
 
+static trtoi(const std::string& s)
+{
+    std::istringstream str(s);
+    int i;
+    str >> i;
+    return i;
+}
+
 static inline json_dict make_json_dict(const web::json::value& x)
 {
     return std::make_shared<json_dict::native>(x);
@@ -102,7 +113,7 @@ int json_dict::number(const char *name) 
     {
         // Some broken APIs may return strings instead of numbers, so lets try
         // that too as a fallback
-        return std::stoi(val.as_string());
+        return strtoi(val.as_string());
     }
 }
 
