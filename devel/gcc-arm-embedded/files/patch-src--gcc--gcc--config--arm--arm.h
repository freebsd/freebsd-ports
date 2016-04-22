--- src/gcc/gcc/config/arm/arm.h.orig	2016-03-30 20:55:09.000000000 +0300
+++ src/gcc/gcc/config/arm/arm.h	2016-04-19 22:13:19.910442000 +0300
@@ -2414,7 +2414,7 @@ extern const char *arm_rewrite_mcpu (int
 
 /* -mcpu=native handling only makes sense with compiler running on
    an ARM chip.  */
-#if defined(__arm__)
+#if defined(__arm__) && !defined(CROSS_DIRECTORY_STRUCTURE)
 extern const char *host_detect_local_cpu (int argc, const char **argv);
 # define EXTRA_SPEC_FUNCTIONS						\
   { "local_cpu_detect", host_detect_local_cpu },			\
