source/utils.c:303:54: error: implicit declaration of function 'mallinfo' is invalid in C99
      [-Werror,-Wimplicit-function-declaration]
        writeToLogFile("Memory usage at exit: %u\n", mallinfo().arena);
                                                     ^
source/utils.c:303:64: error: member reference base type 'int' is not a structure or union
        writeToLogFile("Memory usage at exit: %u\n", mallinfo().arena);
                                                     ~~~~~~~~~~^~~~~~

--- source/utils.c.orig	2017-04-22 14:20:08 UTC
+++ source/utils.c
@@ -299,7 +299,7 @@ void *checkAlloc(void *ptr, size_t size, const char *f
                        "\n*            Shutting Down            *\n\n");
         writeToLogFile("Out of memory!\n");
         writeToLogFile("Allocation of size %i failed in function '%s' at %s:%i.\n", size, func, file, line);
-#ifndef WIN
+#if defined(__GLIBC__) || defined(ANDROID) || defined(VITA)
         writeToLogFile("Memory usage at exit: %u\n", mallinfo().arena);
 #endif
         exit(2);
