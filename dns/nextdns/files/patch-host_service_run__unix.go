Keep SIGTERM sent during the 5s startup wait: restart hung forever.
--- host/service/run_unix.go.orig	2026-11-24 00:54:49 UTC
+++ host/service/run_unix.go
@@ -15,13 +15,22 @@ func runService(name string, r Runner) error {
 	sig := make(chan os.Signal, 1)
 	signal.Notify(sig)
 	defer signal.Stop(sig)
+	// sig is not drained during start: SIGURG/SIGCHLD can fill it and a
+	// SIGTERM sent meanwhile would be dropped. Give SIGTERM its own buffer.
+	term := make(chan os.Signal, 1)
+	signal.Notify(term, syscall.SIGTERM)
+	defer signal.Stop(term)
 
 	if err := start(r, syscall.SIGTERM); err != nil {
 		return err
 	}
 
 	for {
-		s := <-sig
+		var s os.Signal
+		select {
+		case s = <-term:
+		case s = <-sig:
+		}
 		switch s {
 		case syscall.SIGTERM:
 			r.Log(fmt.Sprintf("Received signal: %s", s))
