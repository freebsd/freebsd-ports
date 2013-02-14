--- cmake/readline.cmake.orig	2013-02-13 11:49:33.000000000 +0100
+++ cmake/readline.cmake	2013-02-13 11:49:56.000000000 +0100
@@ -192,7 +192,7 @@
     IF(WITH_LIBEDIT) 
      MYSQL_USE_BUNDLED_LIBEDIT()
     ELSE()
-      FIND_SYSTEM_LIBEDIT(edit)
+      FIND_SYSTEM_LIBEDIT(readline)
       IF(NOT_LIBEDIT_FOUND)
         MESSAGE(FATAL_ERROR "Cannot find system libedit libraries.Use WITH_LIBEDIT") 
       ENDIF()
