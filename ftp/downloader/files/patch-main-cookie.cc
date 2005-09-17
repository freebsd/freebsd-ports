--- main/cookie.cc.orig	Tue Sep 13 19:59:44 2005
+++ main/cookie.cc	Fri Sep 16 23:10:02 2005
@@ -109,7 +109,7 @@
 };
 
 void tCookie::set_time(const std::string &what){
-	time_of_life=atoll(what.c_str());
+	time_of_life=strtoll(what.c_str(), (char **)NULL, 10);
 };
 
 void tCookie::init(char *a,char *b,char *c,char *d){
