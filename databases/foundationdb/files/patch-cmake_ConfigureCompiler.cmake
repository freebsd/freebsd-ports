--- cmake/ConfigureCompiler.cmake.orig	2021-10-21 22:10:27 UTC
+++ cmake/ConfigureCompiler.cmake
@@ -233,7 +233,7 @@ else()
         if (STATIC_LINK_LIBCXX)
           add_link_options(-static-libgcc -nostdlib++  -Wl,-Bstatic -lc++ -lc++abi -Wl,-Bdynamic)
         endif()
-        add_link_options(-stdlib=libc++ -Wl,-build-id=sha1)
+        add_link_options(-Wl,-z,notext)
       endif()
     endif()
     if (OPEN_FOR_IDE)
