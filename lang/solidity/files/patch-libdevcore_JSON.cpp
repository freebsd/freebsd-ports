--- libdevcore/JSON.cpp.orig	2018-05-16 14:30:44 UTC
+++ libdevcore/JSON.cpp
@@ -27,10 +27,12 @@
 
 using namespace std;
 
+/*
 static_assert(
 	(JSONCPP_VERSION_MAJOR == 1) && (JSONCPP_VERSION_MINOR == 8) && (JSONCPP_VERSION_PATCH == 4),
 	"Unexpected jsoncpp version: " JSONCPP_VERSION_STRING ". Expecting 1.8.4."
 );
+*/
 
 namespace dev
 {
