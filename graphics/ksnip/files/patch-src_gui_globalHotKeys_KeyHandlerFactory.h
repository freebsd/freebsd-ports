--- src/gui/globalHotKeys/KeyHandlerFactory.h.orig	2020-06-24 10:31:35 UTC
+++ src/gui/globalHotKeys/KeyHandlerFactory.h
@@ -24,7 +24,7 @@
 #include "DummyKeyHandler.h"
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "X11KeyHandler.h"
 #include "DummyKeyHandler.h"
 #include "src/common/platform/PlatformChecker.h"
