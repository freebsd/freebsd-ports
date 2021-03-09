--- src/VBox/Additions/x11/VBoxClient/logging.cpp.orig	2021-01-07 15:34:30 UTC
+++ src/VBox/Additions/x11/VBoxClient/logging.cpp
@@ -17,6 +17,7 @@
 
 
 #include <stdlib.h>
+#include <sys/wait.h>
 #include <iprt/buildconfig.h>
 #include <iprt/file.h>
 #include <iprt/process.h>
