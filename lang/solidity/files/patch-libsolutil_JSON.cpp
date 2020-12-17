--- libsolutil/JSON.cpp.orig	2020-12-16 17:41:40 UTC
+++ libsolutil/JSON.cpp
@@ -32,10 +32,12 @@
 
 using namespace std;
 
+/*
 static_assert(
 	(JSONCPP_VERSION_MAJOR == 1) && (JSONCPP_VERSION_MINOR == 9) && (JSONCPP_VERSION_PATCH == 3),
 	"Unexpected jsoncpp version: " JSONCPP_VERSION_STRING ". Expecting 1.9.3."
 );
+*/
 
 namespace solidity::util
 {
