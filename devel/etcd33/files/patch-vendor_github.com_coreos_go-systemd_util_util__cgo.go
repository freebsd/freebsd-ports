--- vendor/github.com/coreos/go-systemd/util/util_cgo.go.orig	2019-10-11 17:23:13 UTC
+++ vendor/github.com/coreos/go-systemd/util/util_cgo.go
@@ -127,7 +127,7 @@ func runningFromSystemService() (ret bool, err error) 
 	switch {
 	case errno >= 0:
 		ret = false
-	case serrno == syscall.ENOENT, serrno == syscall.ENXIO, serrno == syscall.ENODATA:
+	case serrno == syscall.ENOENT, serrno == syscall.ENXIO, serrno == syscall.ENOATTR:
 		// Since the implementation of sessions in systemd relies on
 		// the `pam_systemd` module, using the sd_pid_get_owner_uid
 		// heuristic alone can result in false positives if that module
