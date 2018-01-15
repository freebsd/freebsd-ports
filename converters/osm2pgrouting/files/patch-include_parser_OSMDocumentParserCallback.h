--- include/parser/OSMDocumentParserCallback.h.orig	2017-12-18 15:44:24 UTC
+++ include/parser/OSMDocumentParserCallback.h
@@ -22,13 +22,13 @@
 #ifndef SRC_OSMDOCUMENTPARSERCALLBACK_H_
 #define SRC_OSMDOCUMENTPARSERCALLBACK_H_
 #pragma once
-
+/*
 #if __GNUC__ > 4 || \
             (__GNUC__ == 4 && (__GNUC_MINOR__ >= 6))
 #else
 #define nullptr NULL
 #endif
-
+*/
 
 #include <string.h>
 #include "./XMLParser.h"
