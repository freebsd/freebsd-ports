--- include/private/gcconfig.h.orig	2025-10-18 20:23:23 UTC
+++ include/private/gcconfig.h
@@ -400,7 +400,7 @@ EXTERN_C_BEGIN
 #    endif
 #    define mach_type_known
 # endif
-# if defined(LINUX) && defined(__loongarch__)
+# if defined(__loongarch__) && (defined(FREEBSD) || defined(LINUX))
 #    define LOONGARCH
 #    define mach_type_known
 # endif
@@ -1764,12 +1764,12 @@ EXTERN_C_BEGIN
 
 # ifdef LOONGARCH
 #   define MACH_TYPE "LoongArch"
+#   define CPP_WORDSZ (__SIZEOF_SIZE_T__ * 8)
+#   define ALIGNMENT (CPP_WORDSZ/8)
 #   ifdef LINUX
 #     pragma weak __data_start
       extern int __data_start[];
 #     define DATASTART ((ptr_t)(__data_start))
-#     define CPP_WORDSZ (__SIZEOF_SIZE_T__ * 8)
-#     define ALIGNMENT (CPP_WORDSZ/8)
 #   endif
 # endif /* LOONGARCH */
 
