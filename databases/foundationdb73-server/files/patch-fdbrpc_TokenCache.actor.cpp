--- fdbrpc/TokenCache.actor.cpp.orig	2025-07-02 21:14:39 UTC
+++ fdbrpc/TokenCache.actor.cpp
@@ -17,6 +17,7 @@
 #include <boost/unordered_set.hpp>
 
 #include <fmt/format.h>
+#include <fmt/ranges.h>
 #include <list>
 #include <deque>
 
