--- folly/detail/AtFork.h.orig	2020-09-08 16:35:06 UTC
+++ folly/detail/AtFork.h
@@ -18,6 +18,8 @@
 
 #include <folly/Function.h>
 
+#include <unistd.h>
+
 namespace folly {
 
 namespace detail {
