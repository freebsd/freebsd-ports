--- cargo-crates/proc-maps-0.4.0/src/freebsd_maps/ptrace.rs.orig	2026-02-18 12:55:35 UTC
+++ cargo-crates/proc-maps-0.4.0/src/freebsd_maps/ptrace.rs
@@ -185,7 +185,7 @@ pub fn read_vm_entry(pid: Pid, vm_entry: ptrace_vm_ent
 
 /// Read virtual memory entry
 pub fn read_vm_entry(pid: Pid, vm_entry: ptrace_vm_entry) -> io::Result<ptrace_vm_entry> {
-    let result = unsafe { ptrace(PT_VM_ENTRY, pid, &vm_entry as *const _ as *mut i8, 0) };
+    let result = unsafe { ptrace(PT_VM_ENTRY, pid, &vm_entry as *const _ as *mut c_char, 0) };
 
     if result == -1 {
         Err(io::Error::last_os_error())
