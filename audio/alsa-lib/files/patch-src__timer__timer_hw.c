--- src/timer/timer_hw.c~
+++ src/timer/timer_hw.c
@@ -91,10 +91,12 @@ static int snd_timer_hw_async(snd_timer_
 	}
 	if (sig < 0)
 		return 0;
+#ifdef F_SETSIG
 	if (fcntl(fd, F_SETSIG, (long)sig) < 0) {
 		SYSERR("F_SETSIG failed");
 		return -errno;
 	}
+#endif
 	if (fcntl(fd, F_SETOWN, (long)pid) < 0) {
 		SYSERR("F_SETOWN failed");
 		return -errno;
