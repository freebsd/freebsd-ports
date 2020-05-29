--- folly/experimental/symbolizer/Dwarf.cpp.orig	2020-05-27 18:46:20 UTC
+++ folly/experimental/symbolizer/Dwarf.cpp
@@ -1264,9 +1264,11 @@ Dwarf::LineNumberVM::StepResult Dwarf::LineNumberVM::s
       // use unbounded amounts of state (ie. use the heap).  We'll do a second
       // pass (using nextDefineFile()) if necessary.
       break;
+#if !defined(__FreeBSD__)
     case DW_LNE_set_discriminator:
       discriminator_ = readULEB(program);
       return CONTINUE;
+#endif
   }
 
   // Unrecognized extended opcode
