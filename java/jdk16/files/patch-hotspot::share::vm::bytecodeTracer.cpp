--- ../../hotspot/src/share/vm/interpreter/bytecodeTracer.cpp.orig	Tue Oct 19 14:42:10 2004
+++ ../../hotspot/src/share/vm/interpreter/bytecodeTracer.cpp	Thu May 24 17:28:49 2007
@@ -51,7 +51,11 @@
       // Note 1: This code will not work as expected with true MT/MP.
       //         Need an explicit lock or a different solution.
       tty->cr();
+#if defined(_ALLBSD_SOURCE)
+      tty->print("[%ld] ", (intptr_t) Thread::current()->osthread()->thread_id());
+#else
       tty->print("[%d] ", (int) Thread::current()->osthread()->thread_id());
+#endif
       method->print_name(tty);
       tty->cr();
       _current_method = method();
@@ -64,7 +68,11 @@
       code = Bytecodes::cast(*bcp);
     }
     int bci = bcp - method->code_base();
+#if defined(_ALLBSD_SOURCE)
+    tty->print("[%ld] ", (intptr_t) Thread::current()->osthread()->thread_id());
+#else
     tty->print("[%d] ", (int) Thread::current()->osthread()->thread_id());
+#endif
     if (Verbose) {
       tty->print("%8d  %4d  " INTPTR_FORMAT " " INTPTR_FORMAT " %s", 
 	   BytecodeCounter::counter_value(), bci, tos, tos2, Bytecodes::name(code));
