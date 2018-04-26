--- libdevcore/JSON.cpp.orig	2018-04-19 21:36:04 UTC
+++ libdevcore/JSON.cpp
@@ -27,10 +27,12 @@
 
 using namespace std;
 
+/*
 static_assert(
 	(JSONCPP_VERSION_MAJOR == 1) && (JSONCPP_VERSION_MINOR == 7) && (JSONCPP_VERSION_PATCH == 7),
 	"Unexpected jsoncpp version: " JSONCPP_VERSION_STRING ". Expecting 1.7.7."
 );
+*/
 
 namespace dev
 {
