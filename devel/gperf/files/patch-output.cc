--- src/output.cc.orig	2025-04-09 10:17:59 UTC
+++ src/output.cc
@@ -953,11 +953,6 @@ Output::output_hash_function () const
           /* Pseudo-statement or comment that avoids a compiler warning or
              lint warning.  */
           const char * const fallthrough_marker =
-            "#if (defined __cplusplus && (__cplusplus >= 201703L || (__cplusplus >= 201103L && defined __clang__ && __clang_major__ + (__clang_minor__ >= 9) > 3))) || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L && ((defined __GNUC__ && __GNUC__ >= 10) || (defined __clang__ && __clang_major__ >= 9)))\n"
-            "      [[fallthrough]];\n"
-            "#elif (defined __GNUC__ && __GNUC__ >= 7) || (defined __clang__ && __clang_major__ >= 10)\n"
-            "      __attribute__ ((__fallthrough__));\n"
-            "#endif\n"
             "      /*FALLTHROUGH*/\n";
           /* It doesn't really matter whether hval is an 'int' or
              'unsigned int', but 'unsigned int' gives fewer warnings.  */
