--- cmake/objects.cmake.orig	2025-07-02 10:21:03 UTC
+++ cmake/objects.cmake
@@ -90,30 +90,6 @@ set(LIBDDWAF_SOURCE
     ${libddwaf_SOURCE_DIR}/src/libcxx-compat/monotonic_buffer_resource.cpp
     ${libddwaf_SOURCE_DIR}/src/vendor/fmt/format.cc
     ${libddwaf_SOURCE_DIR}/src/vendor/radixlib/radixlib.c
-    ${libddwaf_SOURCE_DIR}/src/vendor/lua-aho-corasick/ac_fast.cxx
-    ${libddwaf_SOURCE_DIR}/src/vendor/lua-aho-corasick/ac_slow.cxx
-    ${libddwaf_SOURCE_DIR}/src/vendor/lua-aho-corasick/ac.cxx
-    ${libddwaf_SOURCE_DIR}/src/vendor/libinjection/src/xss.c
-    ${libddwaf_SOURCE_DIR}/src/vendor/libinjection/src/libinjection_html5.c
-    ${libddwaf_SOURCE_DIR}/src/vendor/libinjection/src/libinjection_xss.c
-    ${libddwaf_SOURCE_DIR}/src/vendor/libinjection/src/libinjection_sqli.c
-    ${libddwaf_SOURCE_DIR}/src/vendor/utf8proc/utf8proc.c
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/bitstate.cc
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/compile.cc
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/dfa.cc
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/nfa.cc
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/onepass.cc
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/parse.cc
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/perl_groups.cc
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/prog.cc
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/re2.cc
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/regexp.cc
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/simplify.cc
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/tostring.cc
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/unicode_casefold.cc
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/unicode_groups.cc
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/util/rune.cc
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/util/strutil.cc
 )
 
 set(LIBDDWAF_PUBLIC_INCLUDES ${libddwaf_SOURCE_DIR}/include)
@@ -121,12 +97,29 @@ set(LIBDDWAF_PRIVATE_INCLUDES
 set(LIBDDWAF_PRIVATE_INCLUDES
     ${libddwaf_SOURCE_DIR}/src
     ${libddwaf_SOURCE_DIR}/src/vendor
-    ${libddwaf_SOURCE_DIR}/src/vendor/libinjection/src/
     ${libddwaf_SOURCE_DIR}/src/vendor/radixlib/
-    ${libddwaf_SOURCE_DIR}/src/vendor/lua-aho-corasick/
-    ${libddwaf_SOURCE_DIR}/src/vendor/utf8proc/
-    ${libddwaf_SOURCE_DIR}/src/vendor/re2/
 )
+
+find_library(LIBAC ac)
+if (LIBAC)
+    list(APPEND LIBDDWAF_INTERFACE_LIBRARIES ac)
+endif()
+find_library(LIBFMT fmt)
+if (LIBFMT)
+    list(APPEND LIBDDWAF_INTERFACE_LIBRARIES fmt)
+endif()
+find_library(LIBINJECTION injection)
+if (LIBINJECTION)
+    list(APPEND LIBDDWAF_INTERFACE_LIBRARIES injection)
+endif()
+find_library(LIBRE2 re2)
+if (LIBRE2)
+    list(APPEND LIBDDWAF_INTERFACE_LIBRARIES re2)
+endif()
+find_library(LIBUTF8PROC utf8proc)
+if (LIBUTF8PROC)
+    list(APPEND LIBDDWAF_INTERFACE_LIBRARIES utf8proc)
+endif()
 
 function(gen_objects target_name)
     add_library(${target_name} OBJECT ${LIBDDWAF_SOURCE} )
