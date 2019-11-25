--- chrome/browser/diagnostics/diagnostics_writer.h.orig	2019-09-10 10:42:29 UTC
+++ chrome/browser/diagnostics/diagnostics_writer.h
@@ -15,6 +15,8 @@ namespace diagnostics {
 // Console base class used internally.
 class SimpleConsole;
 
+#undef MACHINE
+
 class DiagnosticsWriter : public DiagnosticsModel::Observer {
  public:
   // The type of formatting done by this writer.
