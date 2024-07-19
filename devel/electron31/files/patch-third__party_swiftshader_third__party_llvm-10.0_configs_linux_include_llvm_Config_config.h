--- third_party/swiftshader/third_party/llvm-10.0/configs/linux/include/llvm/Config/config.h.orig	2022-05-19 14:06:27 UTC
+++ third_party/swiftshader/third_party/llvm-10.0/configs/linux/include/llvm/Config/config.h
@@ -29,7 +29,7 @@
 
 /* Define to 1 if you have the declaration of `arc4random', and to 0 if you
    don't. */
-#define HAVE_DECL_ARC4RANDOM 0
+#define HAVE_DECL_ARC4RANDOM 1
 
 /* Define to 1 if you have the declaration of `FE_ALL_EXCEPT', and to 0 if you
    don't. */
@@ -53,7 +53,7 @@
 #define HAVE_DLOPEN 1
 
 /* Define if dladdr() is available on this platform. */
-/* #undef HAVE_DLADDR */
+#define HAVE_DLADDR 1
 
 /* Define to 1 if you have the <errno.h> header file. */
 #define HAVE_ERRNO_H 1
@@ -92,7 +92,7 @@
 #define HAVE_ISATTY 1
 
 /* Define to 1 if you have the `edit' library (-ledit). */
-/* #undef HAVE_LIBEDIT */
+#define HAVE_LIBEDIT 1
 
 /* Define to 1 if you have the `pfm' library (-lpfm). */
 /* #undef HAVE_LIBPFM */
@@ -110,13 +110,13 @@
 /* #undef HAVE_PTHREAD_SETNAME_NP */
 
 /* Define to 1 if you have the `z' library (-lz). */
-/* #undef HAVE_LIBZ */
+#define HAVE_LIBZ 1
 
 /* Define to 1 if you have the <link.h> header file. */
-#define HAVE_LINK_H 1
+/* #undef HAVE_LINK_H */
 
 /* Define to 1 if you have the `lseek64' function. */
-#define HAVE_LSEEK64 1
+/* #undef HAVE_LSEEK64 */
 
 /* Define to 1 if you have the <mach/mach.h> header file. */
 /* #undef HAVE_MACH_MACH_H */
@@ -125,7 +125,7 @@
 /* #undef HAVE_MALLCTL */
 
 /* Define to 1 if you have the `mallinfo' function. */
-#define HAVE_MALLINFO 1
+/* #undef HAVE_MALLINFO */
 
 /* Define to 1 if you have the <malloc/malloc.h> header file. */
 /* #undef HAVE_MALLOC_MALLOC_H */
@@ -134,10 +134,10 @@
 /* #undef HAVE_MALLOC_ZONE_STATISTICS */
 
 /* Define to 1 if you have the `posix_fallocate' function. */
-#define HAVE_POSIX_FALLOCATE 1
+/* #undef HAVE_POSIX_FALLOCATE */
 
 /* Define to 1 if you have the `posix_spawn' function. */
-/* #undef HAVE_POSIX_SPAWN */
+#define HAVE_POSIX_SPAWN 1
 
 /* Define to 1 if you have the `pread' function. */
 #define HAVE_PREAD 1
@@ -161,10 +161,10 @@
 #define HAVE_SETENV 1
 
 /* Define to 1 if you have the `sched_getaffinity' function. */
-#define HAVE_SCHED_GETAFFINITY 1
+/* #undef HAVE_SCHED_GETAFFINITY */
 
 /* Define to 1 if you have the `CPU_COUNT' macro. */
-#define HAVE_CPU_COUNT 1
+/* #undef HAVE_CPU_COUNT */
 
 /* Define to 1 if you have the `setrlimit' function. */
 #define HAVE_SETRLIMIT 1
@@ -182,7 +182,7 @@
 #define HAVE_STRERROR_R 1
 
 /* Define to 1 if you have the `sysconf' function. */
-#define HAVE_SYSCONF 1
+/* #undef HAVE_SYSCONF */
 
 /* Define to 1 if you have the <sys/ioctl.h> header file. */
 #define HAVE_SYS_IOCTL_H 1
@@ -209,7 +209,7 @@
 #define HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC 1
 
 /* Define to 1 if you have the <sys/types.h> header file. */
-#define HAVE_SYS_TYPES_H 1
+/* #undef HAVE_SYS_TYPES_H */
 
 /* Define if the setupterm() function is supported this platform. */
 /* #undef HAVE_TERMINFO */
@@ -218,16 +218,16 @@
 /* #undef HAVE_LIBXAR */
 
 /* Define to 1 if you have the <termios.h> header file. */
-/* #undef HAVE_TERMIOS_H */
+#define HAVE_TERMIOS_H 1
 
 /* Define to 1 if you have the <unistd.h> header file. */
 #define HAVE_UNISTD_H 1
 
 /* Define to 1 if you have the <valgrind/valgrind.h> header file. */
-/* #undef HAVE_VALGRIND_VALGRIND_H */
+/* #define HAVE_VALGRIND_VALGRIND_H 1 */
 
 /* Define to 1 if you have the <zlib.h> header file. */
-/* #undef HAVE_ZLIB_H */
+#define HAVE_ZLIB_H 1
 
 /* Have host's _alloca */
 /* #undef HAVE__ALLOCA */
@@ -292,30 +292,8 @@
 /* Linker version detected at compile time. */
 /* #undef HOST_LINK_VERSION */
 
-/* Target triple LLVM will generate code for by default */
-/* Doesn't use `cmakedefine` because it is allowed to be empty. */
-#if defined(__x86_64__)
-#define LLVM_DEFAULT_TARGET_TRIPLE "x86_64-unknown-linux-gnu"
-#elif defined(__i386__)
-#define LLVM_DEFAULT_TARGET_TRIPLE "i686-pc-linux-gnu"
-#elif defined(__arm__)
-#define LLVM_DEFAULT_TARGET_TRIPLE "armv7-linux-gnueabihf"
-#elif defined(__aarch64__)
-#define LLVM_DEFAULT_TARGET_TRIPLE "aarch64-linux-gnu"
-#elif defined(__mips__)
-#define LLVM_DEFAULT_TARGET_TRIPLE "mipsel-linux-gnu"
-#elif defined(__mips64)
-#define LLVM_DEFAULT_TARGET_TRIPLE "mips64el-linux-gnuabi64"
-#elif defined(__powerpc64__)
-#define LLVM_DEFAULT_TARGET_TRIPLE "powerpc64le-unknown-linux-gnu"
-#elif defined(__riscv) && __riscv_xlen == 64
-#define LLVM_DEFAULT_TARGET_TRIPLE "riscv64-unknown-linux-gnu"
-#else
-#error "unknown architecture"
-#endif
-
 /* Define if zlib compression is available */
-#define LLVM_ENABLE_ZLIB 0
+/* #define LLVM_ENABLE_ZLIB 1 */
 
 /* Define if overriding target triple is enabled */
 /* #undef LLVM_TARGET_TRIPLE_ENV */
@@ -339,10 +317,10 @@
 #define PACKAGE_NAME "LLVM"
 
 /* Define to the full name and version of this package. */
-#define PACKAGE_STRING "LLVM 10.0.0"
+#define PACKAGE_STRING "LLVM 11.1.0"
 
 /* Define to the version of this package. */
-#define PACKAGE_VERSION "10.0.0"
+#define PACKAGE_VERSION "11.1.0"
 
 /* Define to the vendor of this package. */
 /* #undef PACKAGE_VENDOR */
@@ -361,9 +339,6 @@
 
 /* Whether GlobalISel rule coverage is being collected */
 #define LLVM_GISEL_COV_ENABLED 0
-
-/* Define if we have z3 and want to build it */
-#define LLVM_WITH_Z3 1
 
 /* Define to the default GlobalISel coverage file prefix */
 /* #undef LLVM_GISEL_COV_PREFIX */
