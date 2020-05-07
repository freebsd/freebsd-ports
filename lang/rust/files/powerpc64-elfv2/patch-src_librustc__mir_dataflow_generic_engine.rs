Revert https://github.com/rust-lang/rust/commit/e82ec2315e5adb1c291c3702cd2ac1f46ecd0fcf
it causes sigsegv on powerpc64

--- src/librustc_mir/dataflow/generic/engine.rs.orig	2020-04-21 00:17:56 UTC
+++ src/librustc_mir/dataflow/generic/engine.rs
@@ -239,27 +239,24 @@ where
             }
 
             SwitchInt { ref targets, ref values, ref discr, .. } => {
-                let Engine { tcx, body, .. } = *self;
-                let enum_ = discr
-                    .place()
-                    .and_then(|discr| switch_on_enum_discriminant(tcx, body, bb_data, discr));
-                match enum_ {
-                    // If this is a switch on an enum discriminant, a custom effect may be applied
-                    // along each outgoing edge.
-                    Some((enum_place, enum_def)) => {
+                // If this is a switch on an enum discriminant, a custom effect may be applied
+                // along each outgoing edge.
+                if let Some(place) = discr.place() {
+                    let enum_def = switch_on_enum_discriminant(self.tcx, self.body, bb_data, place);
+                    if let Some(enum_def) = enum_def {
                         self.propagate_bits_into_enum_discriminant_switch_successors(
-                            in_out, bb, enum_def, enum_place, dirty_list, &*values, &*targets,
+                            in_out, bb, enum_def, place, dirty_list, &*values, &*targets,
                         );
-                    }
 
-                    // Otherwise, it's just a normal `SwitchInt`, and every successor sees the same
-                    // exit state.
-                    None => {
-                        for target in targets.iter().copied() {
-                            self.propagate_bits_into_entry_set_for(&in_out, target, dirty_list);
-                        }
+                        return;
                     }
                 }
+
+                // Otherwise, it's just a normal `SwitchInt`, and every successor sees the same
+                // exit state.
+                for target in targets.iter().copied() {
+                    self.propagate_bits_into_entry_set_for(&in_out, target, dirty_list);
+                }
             }
 
             Call { cleanup, ref destination, ref func, ref args, .. } => {
@@ -345,27 +342,22 @@ where
     }
 }
 
-/// Inspect a `SwitchInt`-terminated basic block to see if the condition of that `SwitchInt` is
-/// an enum discriminant.
-///
-/// We expect such blocks to have a call to `discriminant` as their last statement like so:
-///   _42 = discriminant(_1)
+/// Look at the last statement of a block that ends with  to see if it is an assignment of an enum
+/// discriminant to the local that determines the target of a `SwitchInt` like so:
+///   _42 = discriminant(..)
 ///   SwitchInt(_42, ..)
-///
-/// If the basic block matches this pattern, this function returns the place corresponding to the
-/// enum (`_1` in the example above) as well as the `AdtDef` of that enum.
 fn switch_on_enum_discriminant(
     tcx: TyCtxt<'tcx>,
-    body: &'mir mir::Body<'tcx>,
-    block: &'mir mir::BasicBlockData<'tcx>,
+    body: &mir::Body<'tcx>,
+    block: &mir::BasicBlockData<'tcx>,
     switch_on: &mir::Place<'tcx>,
-) -> Option<(&'mir mir::Place<'tcx>, &'tcx ty::AdtDef)> {
+) -> Option<&'tcx ty::AdtDef> {
     match block.statements.last().map(|stmt| &stmt.kind) {
         Some(mir::StatementKind::Assign(box (lhs, mir::Rvalue::Discriminant(discriminated))))
             if lhs == switch_on =>
         {
             match &discriminated.ty(body, tcx).ty.kind {
-                ty::Adt(def, _) => Some((discriminated, def)),
+                ty::Adt(def, _) => Some(def),
 
                 // `Rvalue::Discriminant` is also used to get the active yield point for a
                 // generator, but we do not need edge-specific effects in that case. This may
