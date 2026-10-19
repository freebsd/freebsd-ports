-- Adapt bun_collections feature list for FreeBSD's newer Rust nightly.
-- (core_intrinsics is no longer needed after the type_info API rework.)

--- src/collections/lib.rs.orig	2026-10-04 00:00:00 UTC
+++ src/collections/lib.rs	2026-10-04 00:00:00 UTC
@@ -6,7 +6,6 @@
     unsized_const_params,
     const_cmp,
     const_trait_impl,
-    core_intrinsics,
     allocator_api
 )]
 #![allow(incomplete_features, internal_features)]
