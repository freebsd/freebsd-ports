--- src/syscall/syscall_freebsd.go.orig	2016-09-28 22:05:26.262297000 +0200
+++ src/syscall/syscall_freebsd.go	2016-09-28 22:09:24.748502000 +0200
@@ -88,7 +88,23 @@ func Pipe(p []int) (err error) {
 	if len(p) != 2 {
 		return EINVAL
 	}
-	p[0], p[1], err = pipe()
+	var pp [2]_C_int
+	err = pipe2(&pp, 0)
+	p[0] = int(pp[0])
+	p[1] = int(pp[1])
+	return
+}
+
+//sysnb pipe2(p *[2]_C_int, flags int) (err error)
+
+func Pipe2(p []int, flags int) (err error) {
+	if len(p) != 2 {
+		return EINVAL
+	}
+	var pp [2]_C_int
+	err = pipe2(&pp, flags)
+	p[0] = int(pp[0])
+	p[1] = int(pp[1])
 	return
 }
 
