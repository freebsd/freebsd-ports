--- src/mpdpp.h.orig	2016-04-17 05:41:01 UTC
+++ src/mpdpp.h
@@ -23,6 +23,7 @@
 
 #include <cassert>
 #include <exception>
+#include <random>
 #include <set>
 #include <vector>
 
@@ -587,6 +588,7 @@ private:
 	int m_port;
 	int m_timeout;
 	std::string m_password;
+	std::mt19937 m_gen;
 };
 
 }
