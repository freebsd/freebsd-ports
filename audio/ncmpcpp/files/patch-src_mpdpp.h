--- src/mpdpp.h.orig	2015-07-05 02:18:34 UTC
+++ src/mpdpp.h
@@ -23,6 +23,7 @@
 
 #include <cassert>
 #include <exception>
+#include <random>
 #include <set>
 #include <vector>
 
@@ -277,6 +278,8 @@ private:
 	std::string m_password;
 	
 	mpd_tag_type m_searched_field;
+
+	std::mt19937 m_gen;
 };
 
 }
