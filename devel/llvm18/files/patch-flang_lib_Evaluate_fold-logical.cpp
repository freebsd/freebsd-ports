--- flang/lib/Evaluate/fold-logical.cpp.orig
+++ flang/lib/Evaluate/fold-logical.cpp
@@ -255,7 +255,7 @@
                   const auto &xConst{DEREF(UnwrapExpr<Constant<xType>>(x))};
                   for (const auto &elt : xConst.values()) {
                     result->emplace_back(
-                        Scalar::template FromInteger(elt).flags.test(
+                        Scalar::FromInteger(elt).flags.test(
                             RealFlag::Overflow));
                   }
                 },
@@ -272,7 +272,7 @@
                   const auto &xConst{DEREF(UnwrapExpr<Constant<xType>>(x))};
                   for (const auto &elt : xConst.values()) {
                     result->emplace_back(elt.IsFinite() &&
-                        Scalar::template Convert(elt).flags.test(
+                        Scalar::Convert(elt).flags.test(
                             RealFlag::Overflow));
                   }
                 },
@@ -291,7 +291,7 @@
                   const auto &xConst{DEREF(UnwrapExpr<Constant<xType>>(x))};
                   for (const auto &elt : xConst.values()) {
                     result->emplace_back(
-                        Scalar::template ConvertSigned(elt).overflow);
+                        Scalar::ConvertSigned(elt).overflow);
                   }
                 },
                 intMold->u, xInt->u);
