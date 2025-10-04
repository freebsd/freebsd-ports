Supply the version of LLVM we are intending to use via QDOC_USER_CLANG_VERSION,
a custom CMake varible derived from LLVM_VERSION in the port Makefile instead of
iterating through all potential candidates. This avoids mismatches during the
configure stage when a user has a version of LLVM installed greater than what is
set in DEFAULT_VERSIONS.

PR: 287430

--- src/qdoc/cmake/QDocConfiguration.cmake.orig	2025-09-25 00:29:00 UTC
+++ src/qdoc/cmake/QDocConfiguration.cmake
@@ -11,3 +11,5 @@ set(QDOC_SUPPORTED_CLANG_VERSIONS
     "21.1" "20.1" "19.1" "18.1" "17.0"
 )
 
+# Try user-selected version of Clang first
+list(PREPEND QDOC_SUPPORTED_CLANG_VERSIONS "${QDOC_USER_CLANG_VERSION}")
