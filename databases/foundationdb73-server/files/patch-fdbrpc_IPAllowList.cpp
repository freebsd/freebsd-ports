--- fdbrpc/IPAllowList.cpp.orig	2025-07-02 21:14:39 UTC
+++ fdbrpc/IPAllowList.cpp
@@ -26,6 +26,7 @@
 
 #include <fmt/printf.h>
 #include <fmt/format.h>
+#include <fmt/ranges.h>
 #include <bitset>
 
 namespace {
