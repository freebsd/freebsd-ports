Author: lattner
Date: Fri Sep 21 13:30:39 2007
New Revision: 42205

Log:
#ifdef out unsafe tracing code, which fixes PR1689

==============================================================================
--- lib/ExecutionEngine/Interpreter/Execution.cpp (original)
+++ lib/ExecutionEngine/Interpreter/Execution.cpp Fri Sep 21 13:30:39 2007
@@ -1338,20 +1338,6 @@
   StackFrame.VarArgs.assign(ArgVals.begin()+i, ArgVals.end());
 }
 
-static void PrintGenericValue(const GenericValue &Val, const Type* Ty) {
-  switch (Ty->getTypeID()) {
-    default: assert(0 && "Invalid GenericValue Type");
-    case Type::VoidTyID:    DOUT << "void"; break;
-    case Type::FloatTyID:   DOUT << "float " << Val.FloatVal; break;
-    case Type::DoubleTyID:  DOUT << "double " << Val.DoubleVal; break;
-    case Type::PointerTyID: DOUT << "void* " << intptr_t(Val.PointerVal); break;
-    case Type::IntegerTyID: 
-      DOUT << "i" << Val.IntVal.getBitWidth() << " "
-           << Val.IntVal.toStringUnsigned(10)
-           << " (0x" << Val.IntVal.toStringUnsigned(16) << ")\n";
-      break;
-  }
-}
 
 void Interpreter::run() {
   while (!ECStack.empty()) {
@@ -1364,12 +1350,28 @@
 
     DOUT << "About to interpret: " << I;
     visit(I);   // Dispatch to one of the visit* methods...
+#if 0
+    // This is not safe, as visiting the instruction could lower it and free I.
 #ifndef NDEBUG
     if (!isa<CallInst>(I) && !isa<InvokeInst>(I) && 
         I.getType() != Type::VoidTy) {
       DOUT << "  --> ";
-      PrintGenericValue(SF.Values[&I], I.getType());
+      const GenericValue &Val = SF.Values[&I];
+      switch (I.getType()->getTypeID()) {
+      default: assert(0 && "Invalid GenericValue Type");
+      case Type::VoidTyID:    DOUT << "void"; break;
+      case Type::FloatTyID:   DOUT << "float " << Val.FloatVal; break;
+      case Type::DoubleTyID:  DOUT << "double " << Val.DoubleVal; break;
+      case Type::PointerTyID: DOUT << "void* " << intptr_t(Val.PointerVal);
+        break;
+      case Type::IntegerTyID: 
+        DOUT << "i" << Val.IntVal.getBitWidth() << " "
+        << Val.IntVal.toStringUnsigned(10)
+        << " (0x" << Val.IntVal.toStringUnsigned(16) << ")\n";
+        break;
+      }
     }
 #endif
+#endif
   }
 }
