--- imports/syscall/syscall_freebsd_amd64.go.orig	2022-12-20 19:25:43 UTC
+++ imports/syscall/syscall_freebsd_amd64.go
@@ -1725,7 +1725,6 @@ func init() {
 		"SYS_LISTEN":	ValueOf(syscall.SYS_LISTEN),
 		"SYS_LPATHCONF":	ValueOf(syscall.SYS_LPATHCONF),
 		"SYS_LSEEK":	ValueOf(syscall.SYS_LSEEK),
-		"SYS_LSTAT":	ValueOf(syscall.SYS_LSTAT),
 		"SYS_LUTIMES":	ValueOf(syscall.SYS_LUTIMES),
 		"SYS_MAC_SYSCALL":	ValueOf(syscall.SYS_MAC_SYSCALL),
 		"SYS_MADVISE":	ValueOf(syscall.SYS_MADVISE),
@@ -1856,7 +1855,6 @@ func init() {
 		"SYS_SOCKET":	ValueOf(syscall.SYS_SOCKET),
 		"SYS_SOCKETPAIR":	ValueOf(syscall.SYS_SOCKETPAIR),
 		"SYS_SSTK":	ValueOf(syscall.SYS_SSTK),
-		"SYS_STAT":	ValueOf(syscall.SYS_STAT),
 		"SYS_STATFS":	ValueOf(syscall.SYS_STATFS),
 		"SYS_SWAPCONTEXT":	ValueOf(syscall.SYS_SWAPCONTEXT),
 		"SYS_SWAPOFF":	ValueOf(syscall.SYS_SWAPOFF),
