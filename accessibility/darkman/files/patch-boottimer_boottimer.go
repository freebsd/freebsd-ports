Unbreak on FreeBSD < 13 and i386

boottimer/boottimer.go:35:17: could not determine kind of name for C.CLOCK_BOOTTIME
boottimer/boottimer.go:47:13: cannot use _Ctype_long(seconds) (value of type _Ctype_long) as type _Ctype_int in struct literal

--- boottimer/boottimer.go.orig	2022-10-22 10:12:59 UTC
+++ boottimer/boottimer.go
@@ -32,7 +32,7 @@ func SetTimer(d time.Duration) {
 // the same channel `Alarms` above.
 func SetTimer(d time.Duration) {
 	var timer C.timer_t
-	C.timer_create(C.CLOCK_BOOTTIME, nil, &timer)
+	C.timer_create(C.CLOCK_UPTIME, nil, &timer)
 
 	seconds := d.Round(time.Second).Seconds()
 	ns := (d - d.Truncate(time.Second)).Nanoseconds()
@@ -44,7 +44,7 @@ func SetTimer(d time.Duration) {
 			tv_nsec: 0,
 		},
 		it_value: C.struct_timespec{
-			tv_sec:  C.long(seconds),
+			tv_sec:  C.time_t(seconds),
 			tv_nsec: C.long(ns),
 		},
 	}
