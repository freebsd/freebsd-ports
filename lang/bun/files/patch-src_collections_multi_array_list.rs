-- Adapt MultiArrayList reflection to the core::mem::type_info API rework in
-- newer Rust nightlies (FreeBSD ships nightly-2026-09-20, bun 1.4.2 pins
-- nightly-2026-07-20). Backported from upstream commit c6b7fcb5bb81.

--- src/collections/multi_array_list.rs.orig	2026-10-04 00:00:00 UTC
+++ src/collections/multi_array_list.rs	2026-10-04 00:00:00 UTC
@@ -46,9 +46,8 @@
 //! `<[MaybeUninit<u8>]>` slice ops over [`Col`]/[`ColMut`] views.
 
 use core::alloc::Layout;
-use core::any::TypeId;
 use core::marker::PhantomData;
-use core::mem::type_info::{Type as TypeInfo, TypeKind};
+use core::mem::type_info;
 use core::mem::{ManuallyDrop, MaybeUninit};
 use core::ptr::{self, NonNull};
 use std::alloc::{Allocator, Global};
@@ -242,36 +241,20 @@
 
 /// Upper bound on struct field count. The reflected per-field metadata is
 /// cached in fixed-size `[_; MAX_FIELDS]` arrays so `Slice<T>` can be a plain
-/// value type without a `where [(); field_count::<T>()]:` bound propagating to
-/// every caller.
+/// value type without a `where [(); Reflected::<T>::COUNT]:` bound propagating
+/// to every caller.
 const MAX_FIELDS: usize = 32;
 
 // ──────────────────────── const-eval reflection helpers ───────────────────
 
 use crate::const_str_eq;
-
-/// `TypeId` of `F` without the `'static` bound `TypeId::of` imposes — needed
-/// because reflected `Field::ty` ids are not `'static`-restricted, and column
-/// callers routinely use lifetime-carrying field types (`&'a [u8]`, `Ref<'a>`).
-#[inline(always)]
-const fn type_id_of<F: ?Sized>() -> TypeId {
-    const { core::intrinsics::type_id::<F>() }
-}
 
-/// Reflected fields of `T` (struct only). Panics at const-eval for non-structs.
-const fn fields_of<T>() -> &'static [core::mem::type_info::Field] {
-    match TypeInfo::of::<T>().kind {
-        TypeKind::Struct(s) => s.fields,
-        _ => panic!("MultiArrayList<T>: T must be a struct with named fields"),
-    }
-}
+// The reflection methods on `TypeId` are compile-time-only functions: they can
+// be called from a `const` item or an inline `const { }` block, not from a
+// `const fn` body. `type_info::of::<F>()` is `TypeId::of` without the `'static`
+// bound — reflected field ids are not `'static`-restricted, and column callers
+// routinely use lifetime-carrying field types (`&'a [u8]`, `Ref<'a>`).
 
-/// Number of fields in `T`.
-#[inline(always)]
-const fn field_count<T>() -> usize {
-    fields_of::<T>().len()
-}
-
 /// Column-layout sort key for a field of `size` bytes within a struct of
 /// alignment `struct_align`.
 ///
@@ -323,7 +306,41 @@
 struct Reflected<T>(PhantomData<T>);
 
 impl<T> Reflected<T> {
-    const COUNT: usize = field_count::<T>();
+    /// Number of fields in `T`; const-panics unless `T` is laid out as a struct.
+    ///
+    /// The reflection API has no "is this a struct" query (`Type::of::<T>().kind`
+    /// ICEs on nightly-2026-09-15, and `variant(0)` is a hard error on a struct),
+    /// so the check is on what the scatter/gather needs: one variant (not a
+    /// multi-variant enum), fields unless `T` is zero-sized (not a primitive,
+    /// pointer or array), and fields that do not overlap (not a union; disjoint
+    /// fields cannot sum past `size_of::<T>()`). A single-variant enum with an
+    /// explicit `#[repr(int)]` still passes; its tag would never be written.
+    const COUNT: usize = {
+        let id = type_info::of::<T>();
+        assert!(
+            id.variants() == 1,
+            "MultiArrayList<T>: T must be a struct with named fields",
+        );
+        let n = id.fields(0);
+        assert!(
+            n > 0 || core::mem::size_of::<T>() == 0,
+            "MultiArrayList<T>: T must be a struct with named fields",
+        );
+        let mut sum = 0usize;
+        let mut i = 0;
+        while i < n {
+            sum += match id.field(0, i).type_id().size() {
+                Some(s) => s,
+                None => panic!("MultiArrayList: field type must be Sized"),
+            };
+            i += 1;
+        }
+        assert!(
+            sum <= core::mem::size_of::<T>(),
+            "MultiArrayList<T>: T must be a struct with named fields",
+        );
+        n
+    };
     const ALIGN: usize = core::mem::align_of::<T>();
 
     /// Dangling sentinel for an empty buffer. Aligned to `align_of::<T>()`,
@@ -333,8 +350,8 @@
 
     /// `[FieldMeta; COUNT]` in declaration order.
     const META: [FieldMeta; MAX_FIELDS] = {
-        let fields = fields_of::<T>();
-        let n = fields.len();
+        let id = type_info::of::<T>();
+        let n = Self::COUNT;
         assert!(
             n <= MAX_FIELDS,
             "MultiArrayList: too many fields (raise MAX_FIELDS)",
@@ -343,15 +360,15 @@
         let struct_align = core::mem::align_of::<T>();
         let mut i = 0;
         while i < n {
-            let f = &fields[i];
-            let size = match f.ty.size() {
+            let f = id.field(0, i);
+            let size = match f.type_id().size() {
                 Some(s) => s,
                 None => panic!("MultiArrayList: field type must be Sized"),
             };
             let align = align_sort_key(size, struct_align);
             out[i] = FieldMeta {
                 size,
-                offset: f.offset,
+                offset: f.offset(),
                 align,
             };
             i += 1;
@@ -423,15 +440,18 @@
     /// Field index for `NAME`; const-panics if no such field.
     #[cfg(test)]
     const fn index_of<const NAME: &'static str>() -> usize {
-        let fields = fields_of::<T>();
-        let mut i = 0;
-        while i < fields.len() {
-            if const_str_eq(fields[i].name, NAME) {
-                return i;
+        const {
+            let id = type_info::of::<T>();
+            let mut i = 0;
+            while i < Self::COUNT {
+                if const_str_eq(id.field(0, i).name(), NAME) {
+                    break;
+                }
+                i += 1;
             }
-            i += 1;
+            assert!(i < Self::COUNT, "MultiArrayList: no such field");
+            i
         }
-        panic!("MultiArrayList: no such field");
     }
 
     /// Const-panics unless field `NAME` exists and has type `F`.
@@ -443,22 +463,25 @@
     /// so a size match is accepted when ids differ. Size mismatch is always
     /// rejected.
     const fn check<const NAME: &'static str, F>() -> usize {
-        let fields = fields_of::<T>();
-        let mut i = 0;
-        while i < fields.len() {
-            if const_str_eq(fields[i].name, NAME) {
-                if fields[i].ty == type_id_of::<F>() {
-                    return i;
-                }
-                assert!(
-                    Self::META[i].size == core::mem::size_of::<F>(),
-                    "MultiArrayList: column type does not match field type",
-                );
-                return i;
+        const {
+            let id = type_info::of::<T>();
+            let mut i = 0;
+            while i < Self::COUNT {
+                let f = id.field(0, i);
+                if const_str_eq(f.name(), NAME) {
+                    if !(f.type_id() == type_info::of::<F>()) {
+                        assert!(
+                            Self::META[i].size == core::mem::size_of::<F>(),
+                            "MultiArrayList: column type does not match field type",
+                        );
+                    }
+                    break;
+                }
+                i += 1;
             }
-            i += 1;
+            assert!(i < Self::COUNT, "MultiArrayList: no such field");
+            i
         }
-        panic!("MultiArrayList: no such field");
     }
 }
 
