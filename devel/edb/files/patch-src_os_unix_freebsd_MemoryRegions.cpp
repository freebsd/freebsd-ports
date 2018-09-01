FreeBSD and OpenBSD promote NULL to nullptr for C++11 or later.
https://svnweb.freebsd.org/changeset/base/228918

os/unix/freebsd/MemoryRegions.cpp:99:9: error: no matching function for call to 'ptrace'
                while(ptrace(PT_VM_ENTRY, pid_, reinterpret_cast<char*>(&vm_entry), NULL) == 0) {
                      ^~~~~~
/usr/include/sys/ptrace.h:218:5: note: candidate function not viable: no known conversion from 'nullptr_t' to 'int' for 4th argument
int     ptrace(int _request, pid_t _pid, caddr_t _addr, int _data);
        ^

--- src/os/unix/freebsd/MemoryRegions.cpp.orig	2011-07-19 20:29:01 UTC
+++ src/os/unix/freebsd/MemoryRegions.cpp
@@ -96,7 +96,7 @@ void MemoryRegions::sync() {
 		memset(&vm_entry, 0, sizeof(vm_entry));
 		vm_entry.pve_entry = 0;
 
-		while(ptrace(PT_VM_ENTRY, pid_, reinterpret_cast<char*>(&vm_entry), NULL) == 0) {
+		while(ptrace(PT_VM_ENTRY, pid_, reinterpret_cast<char*>(&vm_entry), 0) == 0) {
 			vm_entry.pve_path    = buffer;
 			vm_entry.pve_pathlen = sizeof(buffer);
 
