--- src/server/user_handler.cpp.orig	2013-11-09 20:09:08.000000000 +0400
+++ src/server/user_handler.cpp	2013-11-09 20:09:19.000000000 +0400
@@ -18,6 +18,7 @@
 #include "serialization/string_utils.hpp"
 
 #include <ctime>
+#include <time.h>
 
 bool user_handler::send_mail(const std::string& to_user,
 		const std::string& /*subject*/, const std::string& /*message*/) {
