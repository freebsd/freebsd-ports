Patch obtained from upstream 
https://github.com/SOCI/soci/commit/165737c4be7d6c9acde92610b92e8f42a4cfe933

--- backends/mysql/session.cpp.orig	2018-01-04 20:29:49 UTC
+++ backends/mysql/session.cpp
@@ -199,7 +199,7 @@ void parse_connect_string(const string &
                 throw soci_error(err);
             }
             *port = std::atoi(val.c_str());
-            if (port < 0)
+            if (*port < 0)
             {
                 throw soci_error(err);
             }
