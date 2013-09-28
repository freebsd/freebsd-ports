--- ./cmake/FindExtraDeps.cmake.orig	2012-06-30 12:39:35.000000000 +0000
+++ ./cmake/FindExtraDeps.cmake	2013-09-25 12:11:22.000000000 +0000
@@ -1,13 +1,31 @@
 message("-- Checking for libgee...")
-pkg_check_modules(GEE gee-1.0)
+# libgee <= 0.6.x
+pkg_check_modules(GEE_10 gee-1.0)
+if(GEE_10_FOUND)
+    set(GEE_PACKAGE gee-1.0)
+
+    set(EXTRA_DEP_INCLUDES ${EXTRA_DEP_INCLUDES} ${GEE_10_INCLUDE_DIRS})
+    set(EXTRA_DEP_CFLAGS ${EXTRA_DEP_CFLAGS} ${GEE_10_CFLAGS_OTHER})
+    set(EXTRA_DEP_LIBS ${EXTRA_DEP_LIBS} ${GEE_10_LDFLAGS})
+
+    set(GEE_FOUND true)
+else()
+    # libgee >= 0.8.x
+    pkg_check_modules(GEE_08 gee-0.8)
+    if(GEE_08_FOUND)
+        set(GEE_PACKAGE gee-0.8)
+
+        set(EXTRA_DEP_INCLUDES ${EXTRA_DEP_INCLUDES} ${GEE_08_INCLUDE_DIRS})
+        set(EXTRA_DEP_CFLAGS ${EXTRA_DEP_CFLAGS} ${GEE_08_CFLAGS_OTHER})
+        set(EXTRA_DEP_LIBS ${EXTRA_DEP_LIBS} ${GEE_08_LDFLAGS})
+
+        set(GEE_FOUND true)
+    endif()
+endif()
 message("-- Checking for libnotify >= 0.7...")
 pkg_check_modules(LIBNOTIFY libnotify>=0.7)
 
-if(GEE_FOUND)
-    set(EXTRA_DEP_INCLUDES ${EXTRA_DEP_INCLUDES} ${GEE_INCLUDE_DIRS})
-    set(EXTRA_DEP_CFLAGS ${EXTRA_DEP_CFLAGS} ${GEE_CFLAGS_OTHER})
-    set(EXTRA_DEP_LIBS ${EXTRA_DEP_LIBS} ${GEE_LDFLAGS})
-else()
+if(NOT GEE_FOUND)
     message(FATAL_ERROR "libgee not found")
 endif()
 
