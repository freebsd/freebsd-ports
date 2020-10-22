--- vendor/github.com/muesli/termenv/termenv_unix.go.orig	2020-01-30 12:25:39 UTC
+++ vendor/github.com/muesli/termenv/termenv_unix.go
@@ -99,7 +99,7 @@ func termStatusReport(sequence int) (string, error) {
 func readWithTimeout(f *os.File) (string, bool) {
 	var readfds syscall.FdSet
 	fd := f.Fd()
-	readfds.Bits[fd/64] |= 1 << (fd % 64)
+	readfds.X__fds_bits[fd/64] |= 1 << (fd % 64)
 
 	// Use select to attempt to read from os.Stdout for 100 ms
 	err := sysSelect(int(fd)+1,
@@ -110,7 +110,7 @@ func readWithTimeout(f *os.File) (string, bool) {
 		// log.Printf("select(read stdout): %v", err)
 		return "", false
 	}
-	if readfds.Bits[fd/64]&(1<<(fd%64)) == 0 {
+	if readfds.X__fds_bits[fd/64]&(1<<(fd%64)) == 0 {
 		// log.Print("select(read timeout)")
 		return "", false
 	}
