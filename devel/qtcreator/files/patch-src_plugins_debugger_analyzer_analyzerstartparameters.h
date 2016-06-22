--- src/plugins/debugger/analyzer/analyzerstartparameters.h.orig	2016-06-21 13:37:35 UTC
+++ src/plugins/debugger/analyzer/analyzerstartparameters.h
@@ -42,6 +42,8 @@ public:
     QString analyzerHost;
     QString analyzerSocket;
     quint16 analyzerPort = 0;
+
+    static void *staticTypeId;
 };
 
 DEBUGGER_EXPORT bool operator==(const AnalyzerConnection &c1, const AnalyzerConnection &c2);
