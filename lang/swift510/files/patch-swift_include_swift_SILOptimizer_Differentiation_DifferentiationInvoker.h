--- swift/include/swift/SILOptimizer/Differentiation/DifferentiationInvoker.h.orig	2024-06-06 04:26:30 UTC
+++ swift/include/swift/SILOptimizer/Differentiation/DifferentiationInvoker.h
@@ -60,7 +60,12 @@ struct DifferentiationInvoker { (private)
 
 private:
   Kind kind;
+#if defined(__FreeBSD__)
+  // Workaround. On FreeBSD you can't have an std::pair in a union.
+  struct Value {
+#else
   union Value {
+#endif
     /// The instruction associated with the `DifferentiableFunctionInst` case.
     DifferentiableFunctionInst *diffFuncInst;
     Value(DifferentiableFunctionInst *inst) : diffFuncInst(inst) {}
