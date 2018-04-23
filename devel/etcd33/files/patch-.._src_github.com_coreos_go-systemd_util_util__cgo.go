--- ../src/github.com/coreos/go-systemd/util/util_cgo.go.orig
+++ ../src/github.com/coreos/go-systemd/util/util_cgo.go
@@ -127,7 +127,7 @@
 	switch {
 	case errno >= 0:
 		ret = false
-	case serrno == syscall.ENOENT, serrno == syscall.ENXIO, serrno == syscall.ENODATA:
+	case serrno == syscall.ENOENT, serrno == syscall.ENXIO:
 		// Since the implementation of sessions in systemd relies on
 		// the `pam_systemd` module, using the sd_pid_get_owner_uid
 		// heuristic alone can result in false positives if that module
