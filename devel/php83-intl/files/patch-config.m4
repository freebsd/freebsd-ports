https://github.com/php/php-src/commit/037855fcd3f2

--- config.m4.orig	2024-04-09 18:46:23 UTC
+++ config.m4
@@ -80,7 +80,16 @@ if test "$PHP_INTL" != "no"; then
     breakiterator/codepointiterator_methods.cpp"
 
   PHP_REQUIRE_CXX()
-  PHP_CXX_COMPILE_STDCXX(11, mandatory, PHP_INTL_STDCXX)
+
+  AC_MSG_CHECKING([if intl requires -std=gnu++17])
+  AS_IF([test "$PKG_CONFIG icu-uc --atleast-version=74"],[
+    AC_MSG_RESULT([yes])
+    PHP_CXX_COMPILE_STDCXX(17, mandatory, PHP_INTL_STDCXX)
+  ],[
+    AC_MSG_RESULT([no])
+    PHP_CXX_COMPILE_STDCXX(11, mandatory, PHP_INTL_STDCXX)
+  ])
+
   PHP_INTL_CXX_FLAGS="$INTL_COMMON_FLAGS $PHP_INTL_STDCXX $ICU_CXXFLAGS"
   case $host_alias in
   *cygwin*) PHP_INTL_CXX_FLAGS="$PHP_INTL_CXX_FLAGS -D_POSIX_C_SOURCE=200809L"
