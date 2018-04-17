Use CMake to find libofx instead of just relying on pkgconf

--- cmake/modules/FindLibOfx.cmake.orig	2018-02-06 18:22:38 UTC
+++ cmake/modules/FindLibOfx.cmake
@@ -25,14 +25,13 @@ IF (NOT WIN32)
    # use pkg-config to get the directories and then use these values
    # in the FIND_PATH() and FIND_LIBRARY() calls
    FIND_PACKAGE(PkgConfig)
-   PKG_CHECK_MODULES(LIBOFX libofx>=${LIBOFX_MIN_VERSION})
+   PKG_CHECK_MODULES(PC_OFX libofx>=${LIBOFX_MIN_VERSION})
    # I am not sure what the next statement should do, since the
    # var LIBOFX_DEFINITIONS is not used anywhere. Leave it here
    # in case I overlooked something, but it could really go
    # at some point in time (ipwizard, 2011-02-15)
    # SET(LIBOFX_DEFINITIONS ${LIBOFX_CFLAGS_OTHER})
 
-ELSE (NOT WIN32)
   FIND_PATH(LIBOFX_INCLUDE_DIR libofx/libofx.h
       PATHS
       ${PC_OFX_INCLUDEDIR}
