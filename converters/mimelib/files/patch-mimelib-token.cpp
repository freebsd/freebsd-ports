--- mimelib/token.cpp.bak	1997-09-27 13:54:21.000000000 +0200
+++ mimelib/token.cpp	2011-01-20 11:19:49.000000000 +0100
@@ -32,7 +32,7 @@
 #include <mimelib/token.h>
 
 
-ostream* DwTokenizer::mDebugOut = 0;
+std::ostream* DwTokenizer::mDebugOut = 0;
 
 
 DwTokenizer::DwTokenizer(const DwString& aStr)
@@ -221,7 +221,7 @@
 }
 
 
-void DwTokenizer::PrintToken(ostream* aOut)
+void DwTokenizer::PrintToken(std::ostream* aOut)
 {
     if (!aOut) return;
     char* type = 0;
