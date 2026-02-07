--- src/TypeDefs.hpp.orig	2015-04-06 10:28:07 UTC
+++ src/TypeDefs.hpp
@@ -57,16 +57,18 @@ extern  bool  g_bDebug;  // Declared in 
 //**************************************************************************************************
 // Type definitions
 
-//typedef  unsigned long  ulong;
-//typedef  unsigned int   uint;
-//typedef  unsigned char  uchar;
+#ifdef __BSD__
+typedef  unsigned long  ulong;
+typedef  unsigned int   uint;
+typedef  unsigned char  uchar;
+#endif
 
 typedef  wxStaticText   wxLabel;
 
 //**************************************************************************************************
 // Operating System specific macro declarations
 
-#ifdef __WXOSX__
+#if defined(__WXOSX__) || defined(__BSD__)
   #define  EXP10(X)   pow(10.0,X)
   #define  EXP10F(X)  powf(10.0,X)
 #else
