--- ./liboslexec/constfold.cpp.orig	2013-07-12 08:31:18.000000000 +0930
+++ ./liboslexec/constfold.cpp	2013-11-03 18:07:25.648118961 +1030
@@ -882,19 +882,22 @@
 {
     Opcode &op (rop.inst()->ops()[opnum]);
     // Symbol &R (*rop.inst()->argsymbol(op.firstarg()+0));
-    Symbol &Str (*rop.inst()->argsymbol(op.firstarg()+1));
-    Symbol &Results (*rop.inst()->argsymbol(op.firstarg()+2));
-    Symbol &Sep (*rop.inst()->argsymbol(op.firstarg()+3));
-    Symbol &Maxsplit (*rop.inst()->argsymbol(op.firstarg()+4));
-    if (Str.is_constant() && Sep.is_constant() && Maxsplit.is_constant()) {
+    Symbol &Str (*rop.opargsym (op, 1));
+    Symbol &Results (*rop.opargsym (op, 2));
+    Symbol *Sep (rop.opargsym (op, 3));
+    Symbol *Maxsplit (rop.opargsym (op, 4));
+    if (Str.is_constant() && (!Sep || Sep->is_constant()) &&
+                             (!Maxsplit || Maxsplit->is_constant())) {
         // The split string, separator string, and maxsplit are all constants.
         // Compute the results with Strutil::split.
         int resultslen = Results.typespec().arraylength();
-        int maxsplit = Imath::clamp (*(int *)Maxsplit.data(), 0, resultslen);
+        int maxsplit = Maxsplit ? *(int *)Maxsplit->data() : resultslen;
+        maxsplit = std::min (maxsplit, resultslen);
         std::vector<std::string> splits;
+        ustring sep = Sep ? (*(ustring *)Sep->data()) : ustring("");
         Strutil::split ((*(ustring *)Str.data()).string(), splits,
-                        (*(ustring *)Sep.data()).string(), maxsplit);
-        int n = std::min (maxsplit, (int)splits.size());
+                        sep.string(), maxsplit);
+        int n = std::min (std::max(0,maxsplit), (int)splits.size());
         // Temporarily stash the index of the symbol holding results
         int resultsarg = rop.inst()->args()[op.firstarg()+2];
         // Turn the 'split' into a straight assignment of the return value...
@@ -1337,7 +1340,7 @@
             *(const float *)Y.data() == 2.0f) {
         // Turn x^2 into x*x, even if x is not constant
         static ustring kmul("mul");
-        op.reset (kmul, 2);
+        op.reset (kmul, 3);
         rop.inst()->args()[op.firstarg()+2] = rop.inst()->args()[op.firstarg()+1];
         return 1;
     }
