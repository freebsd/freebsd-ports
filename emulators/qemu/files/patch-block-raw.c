Index: qemu/block-raw.c
@@ -51,7 +51,7 @@
 #include <linux/cdrom.h>
 #include <linux/fd.h>
 #endif
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && __FreeBSD__ > 4
 #include <sys/disk.h>
 #endif
 
@@ -167,9 +167,20 @@
 static int aio_sig_num = SIGUSR2;
 static RawAIOCB *first_aio; /* AIO issued */
 static int aio_initialized = 0;
+// FreeBSD 4.x doesn't have sigwait
+#if defined(__FreeBSD__) && __FreeBSD__ <= 4
+static int sigaio_dont = 0;
+#endif
 
 static void aio_signal_handler(int signum)
 {
+// FreeBSD 4.x doesn't have sigwait
+#if defined(__FreeBSD__) && __FreeBSD__ <= 4
+    if (sigaio_dont) {
+	--sigaio_dont;
+	return;
+    }
+#endif
 #ifndef QEMU_TOOL
     CPUState *env = cpu_single_env;
     if (env) {
@@ -284,9 +295,17 @@
     if (qemu_bh_poll())
         return;
 #endif
+// FreeBSD 4.x doesn't have sigwait
+#if defined(__FreeBSD__) && __FreeBSD__ <= 4
+    ++sigaio_dont;
+    do
+	sigsuspend(&wait_oset);
+    while (sigaio_dont);
+#else
     sigemptyset(&set);
     sigaddset(&set, aio_sig_num);
     sigwait(&set, &nb_sigs);
+#endif
     qemu_aio_poll();
 }
 
