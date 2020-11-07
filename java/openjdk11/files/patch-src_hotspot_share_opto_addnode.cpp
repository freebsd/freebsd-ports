--- src/hotspot/share/opto/addnode.cpp
+++ src/hotspot/share/opto/addnode.cpp
@@ -917,7 +917,7 @@ Node *MinINode::Ideal(PhaseGVN *phase, bool can_reshape) {
 
     // Transform MIN2(x + c0, MIN2(x + c1, z)) into MIN2(x + MIN2(c0, c1), z)
     // if x == y and the additions can't overflow.
-    if (phase->eqv(x,y) &&
+    if (phase->eqv(x,y) && tx != NULL &&
         !can_overflow(tx, x_off) &&
         !can_overflow(tx, y_off)) {
       return new MinINode(phase->transform(new AddINode(x, phase->intcon(MIN2(x_off, y_off)))), r->in(2));
@@ -925,7 +925,7 @@ Node *MinINode::Ideal(PhaseGVN *phase, bool can_reshape) {
   } else {
     // Transform MIN2(x + c0, y + c1) into x + MIN2(c0, c1)
     // if x == y and the additions can't overflow.
-    if (phase->eqv(x,y) &&
+    if (phase->eqv(x,y) && tx != NULL &&
         !can_overflow(tx, x_off) &&
         !can_overflow(tx, y_off)) {
       return new AddINode(x,phase->intcon(MIN2(x_off,y_off)));
