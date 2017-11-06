--- source/utils.c.bak	2017-04-22 14:20:08 UTC
+++ source/utils.c
@@ -295,7 +295,7 @@ void *checkAlloc(void *ptr, size_t size, const char *f
                        "\n*            Shutting Down            *\n\n");
         writeToLogFile("Out of memory!\n");
         writeToLogFile("Allocation of size %i failed in function '%s' at %s:%i.\n", size, func, file, line);
-#ifndef WIN
+#if defined(__GLIBC__) || defined(ANDROID) || defined(VITA)
         writeToLogFile("Memory usage at exit: %u\n", mallinfo().arena);
 #endif
         exit(2);
