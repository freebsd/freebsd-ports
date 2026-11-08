--- swift/lib/IRGen/GenOpaque.cpp.orig	2026-10-10 18:48:34 UTC
+++ swift/lib/IRGen/GenOpaque.cpp
@@ -179,15 +179,26 @@
   case ValueWitness::Destroy:
   case ValueWitness::DestructiveInjectEnumTag:
   case ValueWitness::DestructiveProjectEnumData:
-  case ValueWitness::GetEnumTag:
   case ValueWitness::StoreEnumTagSinglePayload:
     return attrs.addParamAttribute(ctx, 0, llvm::Attribute::NoAlias);
 
+  // getEnumTag returns the case index as an unsigned value.  Mark the result
+  // zeroext so that on targets which return sub-word integers in the low bits
+  // of a wider register without guaranteeing the high bits (e.g. PowerPC64,
+  // where a GPR is 64 bits and has no zeroing narrow sub-registers), the
+  // callee extends the result.  Otherwise callers that consume the tag as a
+  // full-width index read stale high bits and compute an out-of-bounds field
+  // record address.
+  case ValueWitness::GetEnumTag:
+    return attrs.addParamAttribute(ctx, 0, llvm::Attribute::NoAlias)
+        .addRetAttribute(ctx, llvm::Attribute::ZExt);
+
   case ValueWitness::GetEnumTagSinglePayload:
     return attrs
         .addFnAttribute(ctx, llvm::Attribute::getWithMemoryEffects(
                                  ctx, llvm::MemoryEffects::readOnly()))
-        .addParamAttribute(ctx, 0, llvm::Attribute::NoAlias);
+        .addParamAttribute(ctx, 0, llvm::Attribute::NoAlias)
+        .addRetAttribute(ctx, llvm::Attribute::ZExt);
 
   // These have two arguments and they don't alias each other.
   case ValueWitness::AssignWithTake:
