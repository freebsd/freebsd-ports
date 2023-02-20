--- write_audio/write_audio.cc.orig	2022-10-01 15:28:01 UTC
+++ write_audio/write_audio.cc
@@ -3,7 +3,7 @@
 #include <cassert>
 #include <cstdio>
 #include <cstring>
-#include <endian.h>
+#include <sys/endian.h>
 #include <iostream>
 #include <math.h>
 #include <string>
