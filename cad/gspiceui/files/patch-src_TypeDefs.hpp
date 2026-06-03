--- src/TypeDefs.hpp.orig	2020-08-18 15:57:04 UTC
+++ src/TypeDefs.hpp
@@ -75,7 +75,7 @@ typedef  wxStaticText   wxLabel;
 //**************************************************************************************************
 // Operating System specific macro declarations
 
-#if defined( __WXMSW__ ) || defined( __WXOSX__ )
+#if defined( __WXMSW__ ) || defined( __WXOSX__ ) || defined(__BSD__)
   #define  EXP10(X)   pow(10.0,X)
   #define  EXP10F(X)  powf(10.0,X)
 #else
