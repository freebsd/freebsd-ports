--- cmake/FindHUNSPELL.cmake.orig	2019-01-03 22:38:08 UTC
+++ cmake/FindHUNSPELL.cmake
@@ -40,7 +40,7 @@ find_path(HUNSPELL_INCLUDE_DIRS
           HINTS ${PKG_HUNSPELL_INCLUDE_DIRS}
 )
 find_library(HUNSPELL_LIBRARIES
-             NAMES ${PKG_HUNSPELL_LIBRARIES} hunspell hunspell-1.6 hunspell-1.5 hunspell-1.4 hunspell-1.3 hunspell-1.2 libhunspell
+             NAMES ${PKG_HUNSPELL_LIBRARIES} hunspell hunspell-1.7 hunspell-1.6 hunspell-1.5 hunspell-1.4 hunspell-1.3 hunspell-1.2 libhunspell
              HINTS ${PKG_HUNSPELL_LIBRARY_DIRS}
 )
 
