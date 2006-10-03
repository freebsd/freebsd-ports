--- PExpr.h.orig	Mon Oct  2 20:26:17 2006
+++ PExpr.h	Mon Oct  2 20:26:23 2006
@@ -324,7 +324,7 @@
       virtual NetEConst*elaborate_expr(Design*des, NetScope*,
 				     bool sys_task_arg =false) const;
       virtual NetEConst*elaborate_pexpr(Design*des, NetScope*sc) const;
-      verinum* PEString::eval_const(const Design*, const NetScope*) const;
+      verinum* eval_const(const Design*, const NetScope*) const;
 
       virtual bool is_constant(Module*) const;
 
