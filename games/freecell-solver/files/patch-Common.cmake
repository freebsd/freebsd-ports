--- Common.cmake.orig	2009-01-26 21:46:25.000000000 +0800
+++ Common.cmake	2009-01-26 21:46:40.000000000 +0800
@@ -84,7 +84,7 @@
         FILES
             ${SOURCE}
         DESTINATION
-            "share/man/man${SECTION}"
+            "man/man${SECTION}"
    )
 ENDMACRO(INSTALL_MAN)
 
