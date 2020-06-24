--- src/gui/globalHotKeys/KeyHandlerFactory.cpp.orig	2020-06-24 10:56:55 UTC
+++ src/gui/globalHotKeys/KeyHandlerFactory.cpp
@@ -25,7 +25,7 @@ AbstractKeyHandler* KeyHandlerFactory::create()
     return new DummyKeyHandler;
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
     if(PlatformChecker::instance()->isWayland()) {
 	    return new DummyKeyHandler;
     } else {
@@ -36,4 +36,4 @@ AbstractKeyHandler* KeyHandlerFactory::create()
 #if  defined(_WIN32)
     return new WinKeyHandler;
 #endif
-}
\ No newline at end of file
+}
