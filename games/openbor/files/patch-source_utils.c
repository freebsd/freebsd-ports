source/utils.c:18:10: fatal error: 'features.h' file not found
   18 | #include <features.h>
      |          ^~~~~~~~~~~~
source/utils.c:303:54: error: implicit declaration of function 'mallinfo' is invalid in C99
      [-Werror,-Wimplicit-function-declaration]
        writeToLogFile("Memory usage at exit: %u\n", mallinfo().arena);
                                                     ^
source/utils.c:303:64: error: member reference base type 'int' is not a structure or union
        writeToLogFile("Memory usage at exit: %u\n", mallinfo().arena);
                                                     ~~~~~~~~~~^~~~~~

--- source/utils.c.orig	2024-04-11 18:46:01 UTC
+++ source/utils.c
@@ -14,7 +14,7 @@
 #include <locale.h>
 #include <math.h>
 
-#ifdef LINUX
+#if defined(__linux__)
 #include <features.h>
 #endif
 
@@ -307,7 +307,7 @@ void *checkAlloc(void *ptr, size_t size, const char *f
                        "\n*            Shutting Down            *\n\n");
         writeToLogFile("Out of memory!\n");
         writeToLogFile("Allocation of size %i failed in function '%s' at %s:%i.\n", size, func, file, line);
-#if LINUX && !DARWIN
+#if defined(__GLIBC__) || defined(ANDROID) || defined(VITA)
         writeToLogFile("Memory usage at exit: %u\n", mallinfo2().arena);
 #else
         writeToLogFile("Memory usage at exit: %u\n", getUsedRam(BYTES));
