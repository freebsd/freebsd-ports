--- ./cmake/modules/FindQGpgme.cmake.orig	2009-05-06 14:13:19.000000000 +0400
+++ ./cmake/modules/FindQGpgme.cmake	2010-05-21 23:58:20.499901479 +0400
@@ -17,11 +17,11 @@
                    HINTS ${GPGME_LIBRARY_DIR})
    else ( WIN32 )
       find_library(_QGPGME_EXTRA_LIBRARY gpgme++-pthread
-                   HINTS ${GPGME_LIBRARY_DIR})
+                   HINTS ${GPGME_LIBRARY_DIR} %%KDE4_PREFIX%%/lib)
    endif ( WIN32 )
 
    find_library(QGPGME_LIBRARY qgpgme
-                HINTS ${GPGME_LIBRARY_DIR})
+                HINTS ${GPGME_LIBRARY_DIR} %%KDE4_PREFIX%%/lib)
 
    if (QGPGME_LIBRARY)
       # get the libdirectory and then go one up
