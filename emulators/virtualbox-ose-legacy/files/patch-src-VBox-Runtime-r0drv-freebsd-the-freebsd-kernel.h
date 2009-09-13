--- src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h.orig	2009-09-11 14:48:47.000000000 +0200
+++ src/VBox/Runtime/r0drv/freebsd/the-freebsd-kernel.h	2009-09-11 14:48:54.000000000 +0200
@@ -76,7 +76,7 @@
 # define SLEEPQ_TIMEDWAIT_SIG(EventInt) sleepq_timedwait_sig(EventInt, 0)
 # define SLEEPQ_WAIT(EventInt) sleepq_wait(EventInt, 0)
 # define SLEEPQ_WAIT_SIG(EventInt) sleepq_wait_sig(EventInt, 0)
-#elif
+#else
 # define SLEEPQ_TIMEDWAIT(EventInt) sleepq_timedwait(EventInt)
 # define SLEEPQ_TIMEDWAIT_SIG(EventInt) sleepq_timedwait_sig(EventInt)
 # define SLEEPQ_WAIT(EventInt) sleepq_wait(EventInt)
