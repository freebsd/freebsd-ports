--- weechat/files/patch-cmake_FindRuby.cmake	(nonexistent)
+++ weechat/files/patch-cmake_FindRuby.cmake	(working copy)
@@ -0,0 +1,20 @@ 
+--- cmake/FindRuby.cmake.orig	2019-12-08 08:48:53 UTC
++++ cmake/FindRuby.cmake
+@@ -33,7 +33,7 @@ endif()
+ 
+ find_package(PkgConfig)
+ if(PKG_CONFIG_FOUND)
+-  pkg_search_module(RUBY ruby-2.6 ruby-2.5 ruby-2.4 ruby-2.3 ruby-2.2 ruby-2.1 ruby-2.0 ruby-1.9)
++  pkg_search_module(RUBY ruby-2.7 ruby-2.6 ruby-2.5 ruby-2.4 ruby-2.3 ruby-2.2 ruby-2.1 ruby-2.0 ruby-1.9)
+ endif()
+ 
+ if(RUBY_FOUND)
+@@ -41,7 +41,7 @@ if(RUBY_FOUND)
+   mark_as_advanced(RUBY_LIB)
+ else()
+   find_program(RUBY_EXECUTABLE
+-    NAMES ruby2.6.0 ruby260 ruby2.6 ruby2.5.0 ruby250 ruby2.5 ruby2.4.0 ruby240 ruby2.4 ruby2.3.0 ruby230 ruby2.3 ruby23 ruby2.2.3 ruby223 ruby2.2.2 ruby222 ruby2.2.1 ruby221 ruby2.2.0 ruby220 ruby2.2 ruby22 ruby2.1.7 ruby217 ruby2.1.6 ruby216 ruby2.1.5 ruby215 ruby2.1.4 ruby214 ruby2.1.3 ruby213 ruby2.1.2 ruby212 ruby2.1.1 ruby211 ruby2.1.0 ruby210 ruby2.1 ruby21 ruby2.0 ruby20 ruby1.9.3 ruby193 ruby1.9.2 ruby192 ruby1.9.1 ruby191 ruby1.9 ruby19 ruby
++    NAMES ruby2.7.0 ruby270 ruby2.7 ruby2.6.0 ruby260 ruby2.6 ruby2.5.0 ruby250 ruby2.5 ruby2.4.0 ruby240 ruby2.4 ruby2.3.0 ruby230 ruby2.3 ruby23 ruby2.2.3 ruby223 ruby2.2.2 ruby222 ruby2.2.1 ruby221 ruby2.2.0 ruby220 ruby2.2 ruby22 ruby2.1.7 ruby217 ruby2.1.6 ruby216 ruby2.1.5 ruby215 ruby2.1.4 ruby214 ruby2.1.3 ruby213 ruby2.1.2 ruby212 ruby2.1.1 ruby211 ruby2.1.0 ruby210 ruby2.1 ruby21 ruby2.0 ruby20 ruby1.9.3 ruby193 ruby1.9.2 ruby192 ruby1.9.1 ruby191 ruby1.9 ruby19 ruby
+     PATHS /usr/bin /usr/local/bin /usr/pkg/bin
+   )
+   if(RUBY_EXECUTABLE)
