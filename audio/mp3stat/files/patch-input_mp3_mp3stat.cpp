--- input/mp3/mp3stat.cpp.orig	2004-09-16 00:32:05 UTC
+++ input/mp3/mp3stat.cpp
@@ -5,6 +5,7 @@
  * mp3check - check mp3 file for consistency and print infos
  * Copyright (C) 1998 by Johannes Overmann <overmann@iname.com>
  */
+#include <unistd.h>
 #include <sys/stat.h>
 #include <sys/mman.h>
 #include <fcntl.h>
