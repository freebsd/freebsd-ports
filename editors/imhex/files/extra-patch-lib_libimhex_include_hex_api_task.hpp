--- lib/libimhex/include/hex/api/task.hpp.orig	2022-10-08 08:03:47 UTC
+++ lib/libimhex/include/hex/api/task.hpp
@@ -1,6 +1,7 @@
 #pragma once
 
 #include <hex.hpp>
+#include <jthread.hpp>
 
 #include <cstdio>
 #include <thread>
@@ -11,6 +12,7 @@
 #include <memory>
 #include <list>
 #include <condition_variable>
+#include <vector>
 
 namespace hex {
 
