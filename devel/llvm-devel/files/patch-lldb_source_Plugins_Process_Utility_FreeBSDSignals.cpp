--- lldb/source/Plugins/Process/Utility/FreeBSDSignals.cpp.orig
+++ lldb/source/Plugins/Process/Utility/FreeBSDSignals.cpp
@@ -11,6 +11,10 @@
 #ifdef __FreeBSD__
 #include <csignal>
 
+#ifndef FPE_FLTIDO
+#define	FPE_FLTIDO	9
+#endif
+
 #define ADD_SIGCODE(signal_name, signal_value, code_name, code_value, ...)     \
   static_assert(signal_name == signal_value,                                   \
                 "Value mismatch for signal number " #signal_name);             \
