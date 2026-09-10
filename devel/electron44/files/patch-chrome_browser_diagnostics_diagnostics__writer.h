--- chrome/browser/diagnostics/diagnostics_writer.h.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/diagnostics/diagnostics_writer.h
@@ -16,6 +16,8 @@ class SimpleConsole;
 // Console base class used internally.
 class SimpleConsole;
 
+#undef MACHINE
+
 class DiagnosticsWriter : public DiagnosticsModel::Observer {
  public:
   // The type of formatting done by this writer.
