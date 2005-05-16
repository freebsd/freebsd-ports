--- input/mp3/mp3stat.cpp.orig	Tue Sep 14 12:50:17 2004
+++ input/mp3/mp3stat.cpp	Tue Sep 14 15:35:44 2004
@@ -5,6 +5,7 @@
  * mp3check - check mp3 file for consistency and print infos
  * Copyright (C) 1998 by Johannes Overmann <overmann@iname.com>
  */
+#include <unistd.h>
 #include <sys/stat.h>
 #include <sys/mman.h>
 #include <fcntl.h>
