--- modules/javafx.web/src/main/native/Source/WTF/wtf/MemoryPressureHandler.h.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/WTF/wtf/MemoryPressureHandler.h
@@ -66,7 +66,7 @@ class MemoryPressureHandler { (public)
 
     WTF_EXPORT_PRIVATE void setShouldUsePeriodicMemoryMonitor(bool);
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD)
     WTF_EXPORT_PRIVATE void triggerMemoryPressureEvent(bool isCritical);
 #endif
 
@@ -200,7 +200,7 @@ class MemoryPressureHandler { (public)
     Win32Handle m_lowMemoryHandle;
 #endif
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD)
     RunLoop::Timer<MemoryPressureHandler> m_holdOffTimer;
     void holdOffTimerFired();
 #endif
