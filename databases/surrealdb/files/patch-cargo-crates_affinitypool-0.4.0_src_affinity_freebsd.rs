-- https://github.com/surrealdb/affinitypool/pull/19

--- cargo-crates/affinitypool-0.4.0/src/affinity/freebsd.rs.orig	2026-03-14 15:58:36 UTC
+++ cargo-crates/affinitypool-0.4.0/src/affinity/freebsd.rs
@@ -6,9 +6,7 @@ use libc::CPU_WHICH_TID;
 use libc::CPU_SET;
 use libc::CPU_SETSIZE;
 use libc::CPU_WHICH_TID;
-use libc::cpu_set_t;
-use libc::sched_getaffinity;
-use libc::sched_setaffinity;
+use libc::cpuset_t;
 use std::mem;
 
 pub fn get_core_ids() -> Option<Vec<CoreId>> {
@@ -40,10 +38,10 @@ pub fn set_for_current(core_id: CoreId) -> bool {
 	let res = unsafe {
 		// FreeBSD's sched_setaffinity currently operates on process id,
 		// therefore using cpuset_setaffinity instead.
-		cpuset_setaffinity(
+		libc::cpuset_setaffinity(
 			CPU_LEVEL_WHICH,
 			CPU_WHICH_TID,
-			-1, // -1 == current thread
+			-1 as libc::id_t, // -1 == current thread
 			mem::size_of::<cpuset_t>(),
 			&set,
 		)
@@ -58,10 +56,10 @@ fn get_affinity_mask() -> Option<cpuset_t> {
 	let result = unsafe {
 		// FreeBSD's sched_getaffinity currently operates on process id,
 		// therefore using cpuset_getaffinity instead.
-		cpuset_getaffinity(
+		libc::cpuset_getaffinity(
 			CPU_LEVEL_WHICH,
 			CPU_WHICH_TID,
-			-1, // -1 == current thread
+			-1 as libc::id_t, // -1 == current thread
 			mem::size_of::<cpuset_t>(),
 			&mut set,
 		)
