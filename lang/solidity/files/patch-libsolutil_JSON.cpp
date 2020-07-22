--- libsolutil/JSON.cpp.orig	2020-01-27 15:36:51 UTC
+++ libsolutil/JSON.cpp
@@ -31,10 +31,12 @@
 
 using namespace std;
 
+/*
 static_assert(
 	(JSONCPP_VERSION_MAJOR == 1) && (JSONCPP_VERSION_MINOR == 9) && (JSONCPP_VERSION_PATCH == 3),
 	"Unexpected jsoncpp version: " JSONCPP_VERSION_STRING ". Expecting 1.9.3."
 );
+*/
 
 namespace solidity::util
 {
