--- indiserver/LocalDvrInfo.cpp.orig	2025-03-31 09:12:20 UTC
+++ indiserver/LocalDvrInfo.cpp
@@ -25,6 +25,7 @@
 
 #include "Fifo.hpp"
 #include <sys/socket.h>
+#include <sys/wait.h>
 #include <fcntl.h>
 #include <libgen.h>
 #include <unistd.h>
