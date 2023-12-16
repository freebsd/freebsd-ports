Fix search for OpenSSL with CMake >= 3.27. This port uses OPENSSL_PATHS to set
OPENSSL_ROOT_DIR, so CMake tries to find OpenSSL in TILEDB_EP_INSTALL_PREFIX
which is problably not where we want to look.

--- cmake/Modules/FindOpenSSL_EP.cmake.orig    2023-10-25 06:36:39 UTC
+++ cmake/Modules/FindOpenSSL_EP.cmake
@@ -41,7 +41,7 @@ endif()
 endif()
 
 # Search the path set during the superbuild for the EP.
-set(OPENSSL_PATHS ${TILEDB_EP_INSTALL_PREFIX})
+set(OPENSSL_PATHS ${FREEBSD_OPENSSLBASE})
 
 # Add /usr/local/opt, as Homebrew sometimes installs it there.
 set (HOMEBREW_BASE "/usr/local/opt/openssl")
