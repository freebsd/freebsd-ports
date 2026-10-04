--- thirdparty/level_zero/level-zero/source/utils/logging.h.orig	2026-02-14 21:47:38 UTC
+++ thirdparty/level_zero/level-zero/source/utils/logging.h
@@ -29,7 +29,7 @@
 #include "ze_api.h"
 #include "ze_util.h"
 
-#ifdef __linux__
+#ifdef __FreeBSD__
 #include <unistd.h>
 #include <sys/types.h>
 #include <pwd.h>
