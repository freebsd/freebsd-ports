--- lib/stdint.in.h.orig
+++ lib/stdint.in.h
@@ -306,7 +306,7 @@
    uintptr_t to avoid conflicting declarations of system functions like
    _findclose in <io.h>.  */
 # if !((defined __KLIBC__ && defined _INTPTR_T_DECLARED) \
-       || defined __MINGW32__)
+       || defined __MINGW32__ || defined __CHERI_PURE_CAPABILITY__)
 #  undef intptr_t
 #  undef uintptr_t
 #  ifdef _WIN64
