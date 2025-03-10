--- cmake/Libraries.cmake.orig	2017-12-20 09:59:37 UTC
+++ cmake/Libraries.cmake
@@ -7,11 +7,6 @@ if(ENABLE_TESTS)
                     "ef5e700c8a0f3ee123e2e0209b8b4961")
 endif()
 
-download_external(SPDLOG "spdlog-0.14.0"
-                  "https://github.com/gabime/spdlog/archive/v0.14.0.zip"
-                  "f213d83c466aa7044a132e2488d71b11"
-                  "spdlog-1")
-
 # Find standard libraries
 find_package(Socket REQUIRED)
 find_package(Threads REQUIRED)
