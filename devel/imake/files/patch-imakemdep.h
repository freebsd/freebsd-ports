--- imakemdep.h.orig	2013-08-17 10:11:06 UTC
+++ imakemdep.h
@@ -365,7 +365,7 @@ const char *cpp_argv[ARGUMENTS] = {
     defined(__GNUC__) || defined(__GLIBC__)
 #    ifdef __i386__
 	"-D__i386__",
-#     if defined(__GNUC__) && (__GNUC__ >= 3)
+#     if defined(__GNUC__) && (__GNUC__ >= 3) && !defined(__FreeBSD__)
 	"-m32",
 #     endif
 #    endif
