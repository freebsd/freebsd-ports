--- main/gui/source/messaging/linux.cpp.orig	2025-02-22 05:35:48 UTC
+++ main/gui/source/messaging/linux.cpp
@@ -3,6 +3,7 @@
 #include <stdexcept>
 #include <fcntl.h>
 #include <sys/file.h>
+#include <unistd.h>
 
 #include <hex/helpers/logger.hpp>
 #include <hex/api/events/events_lifecycle.hpp>
