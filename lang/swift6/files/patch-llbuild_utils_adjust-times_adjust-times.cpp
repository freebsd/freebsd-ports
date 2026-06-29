--- llbuild/utils/adjust-times/adjust-times.cpp.orig	2024-01-09 06:44:05 UTC
+++ llbuild/utils/adjust-times/adjust-times.cpp
@@ -50,7 +50,7 @@ static int file_time_set_fixed(const char* filename, s
     struct timeval times[2] = { tv, tv };
     return utimes(filename, times);
   }
-#elif defined __linux__
+#elif defined __linux__ || defined(__FreeBSD__)
   struct timespec times[2] = { time_to_set, time_to_set };
   return utimensat(AT_FDCWD, filename, times, 0);
 #else
