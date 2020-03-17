--- src/gcc/gcc/config/arm/arm.h.orig	2019-10-11 00:03:43 UTC
+++ src/gcc/gcc/config/arm/arm.h
@@ -2211,7 +2211,7 @@ extern const char *arm_target_thumb_only (int argc, co
 
 /* -mcpu=native handling only makes sense with compiler running on
    an ARM chip.  */
-#if defined(__arm__)
+#if defined(__arm__) && !defined(CROSS_DIRECTORY_STRUCTURE)
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 #define HAVE_LOCAL_CPU_DETECT
 # define MCPU_MTUNE_NATIVE_FUNCTIONS			\
