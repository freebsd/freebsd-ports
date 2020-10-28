--- modules/javafx.web/src/main/native/Source/WTF/wtf/MemoryPressureHandler.cpp.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/WTF/wtf/MemoryPressureHandler.cpp
@@ -49,7 +49,7 @@ MemoryPressureHandler& MemoryPressureHandler::singleto
 }
 
 MemoryPressureHandler::MemoryPressureHandler()
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD)
     : m_holdOffTimer(RunLoop::main(), this, &MemoryPressureHandler::holdOffTimerFired)
 #elif OS(WINDOWS)
     : m_windowsMeasurementTimer(RunLoop::main(), this, &MemoryPressureHandler::windowsMeasurementTimerFired)
