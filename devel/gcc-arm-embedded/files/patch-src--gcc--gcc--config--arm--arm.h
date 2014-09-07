--- src/gcc/gcc//config/arm/arm.h.orig	2014-05-27 05:44:10.000000000 +0400
+++ src/gcc/gcc//config/arm/arm.h	2014-09-07 22:16:57.000000000 +0400
@@ -2325,7 +2325,7 @@
 
 /* -mcpu=native handling only makes sense with compiler running on
    an ARM chip.  */
-#if defined(__arm__)
+#if defined(__arm__) && !defined(CROSS_DIRECTORY_STRUCTURE)
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 # define EXTRA_SPEC_FUNCTIONS						\
   { "local_cpu_detect", host_detect_local_cpu },
