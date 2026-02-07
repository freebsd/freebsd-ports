--- src/sqlite3/sqlite3.c.orig	2022-08-09 21:05:11 UTC
+++ src/sqlite3/sqlite3.c
@@ -14487,7 +14487,8 @@ typedef INT16_TYPE LogEst;
 # if defined(i386)      || defined(__i386__)      || defined(_M_IX86) ||    \
      defined(__x86_64)  || defined(__x86_64__)    || defined(_M_X64)  ||    \
      defined(_M_AMD64)  || defined(_M_ARM)        || defined(__x86)   ||    \
-     defined(__ARMEL__) || defined(__AARCH64EL__) || defined(_M_ARM64)
+     defined(__ARMEL__) || defined(__AARCH64EL__) || defined(_M_ARM64) || \
+     defined(__LITTLE_ENDIAN__)
 #   define SQLITE_BYTEORDER    1234
 # elif defined(sparc)     || defined(__ppc__) || \
        defined(__ARMEB__) || defined(__AARCH64EB__)
