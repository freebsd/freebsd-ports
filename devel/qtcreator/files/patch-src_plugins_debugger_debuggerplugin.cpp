--- src/plugins/debugger/debuggerplugin.cpp.orig	2016-06-21 13:37:35 UTC
+++ src/plugins/debugger/debuggerplugin.cpp
@@ -3834,6 +3834,9 @@ QList<QObject *> DebuggerPlugin::createT
 #endif // if  WITH_TESTS
 
 } // namespace Internal
+
+void *AnalyzerConnection::staticTypeId = &AnalyzerConnection::staticTypeId;
+
 } // namespace Debugger
 
 #include "debuggerplugin.moc"
