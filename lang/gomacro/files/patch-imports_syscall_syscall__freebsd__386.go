--- imports/syscall/syscall_freebsd_386.go.orig	2022-12-20 19:25:38 UTC
+++ imports/syscall/syscall_freebsd_386.go
@@ -1724,7 +1724,6 @@ func init() {
 		"SYS_LISTEN":	ValueOf(syscall.SYS_LISTEN),
 		"SYS_LPATHCONF":	ValueOf(syscall.SYS_LPATHCONF),
 		"SYS_LSEEK":	ValueOf(syscall.SYS_LSEEK),
-		"SYS_LSTAT":	ValueOf(syscall.SYS_LSTAT),
 		"SYS_LUTIMES":	ValueOf(syscall.SYS_LUTIMES),
 		"SYS_MAC_SYSCALL":	ValueOf(syscall.SYS_MAC_SYSCALL),
 		"SYS_MADVISE":	ValueOf(syscall.SYS_MADVISE),
@@ -1855,7 +1854,6 @@ func init() {
 		"SYS_SOCKET":	ValueOf(syscall.SYS_SOCKET),
 		"SYS_SOCKETPAIR":	ValueOf(syscall.SYS_SOCKETPAIR),
 		"SYS_SSTK":	ValueOf(syscall.SYS_SSTK),
-		"SYS_STAT":	ValueOf(syscall.SYS_STAT),
 		"SYS_STATFS":	ValueOf(syscall.SYS_STATFS),
 		"SYS_SWAPCONTEXT":	ValueOf(syscall.SYS_SWAPCONTEXT),
 		"SYS_SWAPOFF":	ValueOf(syscall.SYS_SWAPOFF),
@@ -3672,7 +3670,6 @@ func init() {
 		"SYS_LISTEN":	"int:106",
 		"SYS_LPATHCONF":	"int:513",
 		"SYS_LSEEK":	"int:478",
-		"SYS_LSTAT":	"int:190",
 		"SYS_LUTIMES":	"int:276",
 		"SYS_MAC_SYSCALL":	"int:394",
 		"SYS_MADVISE":	"int:75",
