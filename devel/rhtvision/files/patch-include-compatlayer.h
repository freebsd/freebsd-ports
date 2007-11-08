--- include/compatlayer.h.orig	2007-11-05 15:25:07.000000000 +0600
+++ include/compatlayer.h	2007-11-05 15:25:43.000000000 +0600
@@ -324,7 +324,7 @@
     library. GCC implemented it in version 3.0. BC++ implemented some
     stuff in versions like BC++ 5.5. So that's a real mess. */
  #if __GNUC__>=3
-  #if __GNUC_MINOR__>=4
+  #if __GNUC__ >= 4 || __GNUC_MINOR__>=4
    // gcc 3.4. It have __gnu_cxx::stdio_filebuf class.
    #define CLY_filebuf       __gnu_cxx::stdio_filebuf<char>
    #define CLY_int_filebuf   CLY_filebuf
