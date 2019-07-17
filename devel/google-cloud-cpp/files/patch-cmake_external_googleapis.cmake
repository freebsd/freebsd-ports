Workaround for the upstream bug
https://github.com/googleapis/google-cloud-cpp/issues/2875 (Installs files into the same directory where build is performed from)
suggested by Anthony <amzo1337@gmail.com>.

Also see post-patch in Makefile.

--- cmake/external/googleapis.cmake.orig	2019-07-17 17:31:29 UTC
+++ cmake/external/googleapis.cmake
@@ -109,7 +109,7 @@ if (NOT TARGET googleapis_project)
                    -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
                    -DBUILD_SHARED_LIBS=${BUILD_SHARED_LIBS}
                    -DCMAKE_PREFIX_PATH=${GOOGLE_CLOUD_CPP_PREFIX_PATH}
-                   -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
+                   -DCMAKE_INSTALL_PREFIX=%%LOCALBASE%%
                    -DCMAKE_INSTALL_RPATH=${GOOGLE_CLOUD_CPP_INSTALL_RPATH}
                    ${_googleapis_toolchain_flag}
                    ${_googleapis_triplet_flag}
