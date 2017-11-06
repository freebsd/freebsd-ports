--- src/gcc/gcc/config/arm/arm.h.orig	2016-12-05 16:07:09 UTC
+++ src/gcc/gcc/config/arm/arm.h
@@ -2273,7 +2273,7 @@ extern const char *arm_target_thumb_only
 
 /* -mcpu=native handling only makes sense with compiler running on
    an ARM chip.  */
-#if defined(__arm__)
+#if defined(__arm__) && !defined(CROSS_DIRECTORY_STRUCTURE)
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 # define EXTRA_SPEC_FUNCTIONS						\
   { "local_cpu_detect", host_detect_local_cpu },			\
