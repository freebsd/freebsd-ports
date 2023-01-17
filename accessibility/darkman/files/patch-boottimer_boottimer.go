Unbreak on FreeBSD < 13

boottimer/boottimer.go:35:17: could not determine kind of name for C.CLOCK_BOOTTIME

--- boottimer/boottimer.go.orig	2023-01-17 10:14:08 UTC
+++ boottimer/boottimer.go
@@ -32,7 +32,7 @@ func SetTimer(d time.Duration) {
 // the same channel `Alarms` above.
 func SetTimer(d time.Duration) {
 	var timer C.timer_t
-	C.timer_create(C.CLOCK_BOOTTIME, nil, &timer)
+	C.timer_create(C.CLOCK_UPTIME, nil, &timer)
 
 	seconds := d.Round(time.Second).Seconds()
 	ns := (d - d.Truncate(time.Second)).Nanoseconds()
