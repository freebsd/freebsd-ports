--- svtools/source/svrtf/parrtf.cxx.orig	2022-12-22 00:14:09 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -51,6 +51,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
