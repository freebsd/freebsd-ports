--- src/openrct2/network/NetworkServerAdvertiser.cpp.orig	2026-11-01 10:29:24 UTC
+++ src/openrct2/network/NetworkServerAdvertiser.cpp
@@ -25,6 +25,7 @@

     #include <chrono>
     #include <cstring>
+    #include <future>
     #include <iterator>
     #include <memory>
     #include <random>
