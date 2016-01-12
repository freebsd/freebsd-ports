--- cmake/FindRuby.cmake.orig	2016-01-10 08:17:50 UTC
+++ cmake/FindRuby.cmake
@@ -31,22 +31,16 @@ if(RUBY_FOUND)
    set(RUBY_FIND_QUIETLY TRUE)
 endif()
 
-find_package(PkgConfig)
-if(PKG_CONFIG_FOUND)
-  pkg_search_module(RUBY ruby-2.2 ruby-2.1 ruby-2.0 ruby-1.9 ruby-1.8)
-endif()
-
 if(RUBY_FOUND)
   set(RUBY_LIB "")
   mark_as_advanced(RUBY_LIB)
 else()
   find_program(RUBY_EXECUTABLE
-    NAMES ruby2.2.3 ruby223 ruby2.2.2 ruby222 ruby2.2.1 ruby221 ruby2.2.0 ruby220 ruby2.2 ruby22 ruby2.1.7 ruby217 ruby2.1.6 ruby216 ruby2.1.5 ruby215 ruby2.1.4 ruby214 ruby2.1.3 ruby213 ruby2.1.2 ruby212 ruby2.1.1 ruby211 ruby2.1.0 ruby210 ruby2.1 ruby21 ruby2.0 ruby20 ruby1.9.3 ruby193 ruby1.9.2 ruby192 ruby1.9.1 ruby191 ruby1.9 ruby19 ruby1.8 ruby18 ruby
-    PATHS /usr/bin /usr/local/bin /usr/pkg/bin
+    NAMES ${BSD_RUBY_CMD}
     )
   if(RUBY_EXECUTABLE)
     execute_process(
-      COMMAND ${RUBY_EXECUTABLE} -r rbconfig -e "print RbConfig::CONFIG['rubyhdrdir'] || RbConfig::CONFIG['archdir']"
+      COMMAND ${RUBY_EXECUTABLE} -r rbconfig -e "print RbConfig::CONFIG['rubyhdrdir'] || RbConfig::CONFIG['topdir']"
       OUTPUT_VARIABLE RUBY_ARCH_DIR
       )
     execute_process(
@@ -54,11 +48,11 @@ else()
       OUTPUT_VARIABLE RUBY_ARCH
       )
     execute_process(
-      COMMAND ${RUBY_EXECUTABLE} -r rbconfig -e "print RbConfig::CONFIG['libdir']"
+		COMMAND ${RUBY_EXECUTABLE} -r rbconfig -e "print RbConfig::TOPDIR + '/lib'"
       OUTPUT_VARIABLE RUBY_POSSIBLE_LIB_PATH
       )
     execute_process(
-      COMMAND ${RUBY_EXECUTABLE} -r rbconfig -e "print RbConfig::CONFIG['rubylibdir']"
+		COMMAND ${RUBY_EXECUTABLE} -r rbconfig -e "print RbConfig::TOPDIR + '/lib/ruby/' + RbConfig::CONFIG['ruby_version']"
       OUTPUT_VARIABLE RUBY_RUBY_LIB_PATH
       )
     find_path(RUBY_INCLUDE_DIRS
@@ -67,8 +61,7 @@ else()
       )
     set(RUBY_INCLUDE_ARCH "${RUBY_INCLUDE_DIRS}/${RUBY_ARCH}")
     find_library(RUBY_LIB
-      NAMES ruby-1.9.3 ruby1.9.3 ruby193 ruby-1.9.2 ruby1.9.2 ruby192 ruby-1.9.1 ruby1.9.1 ruby191 ruby1.9 ruby19 ruby1.8 ruby18 ruby
-      PATHS ${RUBY_POSSIBLE_LIB_PATH} ${RUBY_RUBY_LIB_PATH}
+		NAMES ${BSD_RUBY_VER}
       )
     if(RUBY_LIB AND RUBY_INCLUDE_DIRS)
       set(RUBY_FOUND TRUE)
