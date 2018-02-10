As we install libqgpgme as libqgpgme4, we have to search for 'gpgme4'.

--- cmake/modules/FindQGpgme.cmake.orig	2015-06-24 12:43:14 UTC
+++ cmake/modules/FindQGpgme.cmake
@@ -20,7 +20,7 @@ if(GPGME_FOUND)
                    HINTS ${GPGME_LIBRARY_DIR})
    endif()
 
-   find_library(QGPGME_LIBRARY qgpgme
+   find_library(QGPGME_LIBRARY qgpgme4
                 HINTS ${GPGME_LIBRARY_DIR})
 
    if (QGPGME_LIBRARY)
