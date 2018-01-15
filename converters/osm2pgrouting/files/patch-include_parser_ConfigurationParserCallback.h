--- include/parser/ConfigurationParserCallback.h.orig	2017-12-18 15:44:24 UTC
+++ include/parser/ConfigurationParserCallback.h
@@ -22,12 +22,13 @@
 #ifndef SRC_CONFIGURATIONPARSERCALLBACK_H_
 #define SRC_CONFIGURATIONPARSERCALLBACK_H_
 #pragma once
-
+/*
 #if __GNUC__ > 4 || \
                     (__GNUC__ == 4 && (__GNUC_MINOR__ >= 6))
 #else
 #define nullptr NULL
 #endif
+*/
 
 #include <string.h>
 #include "XMLParser.h"
