Obtained from:	https://github.com/protocolbuffers/protobuf/commit/56b40a8f055cfd05633054aed5d3466a6e058b72

--- tests.sh.orig	2018-07-27 20:30:28 UTC
+++ tests.sh
@@ -16,8 +16,8 @@ internal_build_cpp() {
   git submodule update --init --recursive
 
   ./autogen.sh
-  ./configure CXXFLAGS="-fPIC"  # -fPIC is needed for python cpp test.
-                                # See python/setup.py for more details
+  ./configure CXXFLAGS="-fPIC  -std=c++11"  # -fPIC is needed for python cpp test.
+                                            # See python/setup.py for more details
   make -j2
 }
 
