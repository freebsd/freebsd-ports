Index: kqemu-freebsd.c
@@ -222,9 +222,17 @@
 int CDECL kqemu_schedule(void)
 {
     /* kqemu_log("kqemu_schedule\n"); */
+#if __FreeBSD_version < 700044
     mtx_lock_spin(&sched_lock);
     mi_switch(SW_VOL, NULL);
     mtx_unlock_spin(&sched_lock);
+#else
+    /* -current no longer uses sched_lock */
+    struct thread *td = curthread;
+    thread_lock(td);
+    mi_switch(SW_VOL, NULL);
+    thread_unlock(td);
+#endif
     return SIGPENDING(curthread);
 }
 #endif
@@ -258,6 +266,10 @@
 static struct clonedevs *kqemuclones;
 static TAILQ_HEAD(,kqemu_instance) kqemuhead = TAILQ_HEAD_INITIALIZER(kqemuhead);
 static eventhandler_tag clonetag;
+#ifndef D_NEEDMINOR
+/* see http://svn.freebsd.org/viewvc/base?view=revision&revision=179726 */
+#define D_NEEDMINOR 0
+#endif
 #endif
 
 static d_close_t kqemu_close;
@@ -282,7 +294,7 @@
 	/* bmaj */	-1
 #else
 	.d_version =	D_VERSION,
-	.d_flags =	D_NEEDGIANT,
+	.d_flags =	D_NEEDGIANT | D_NEEDMINOR,
 	.d_open =	kqemu_open,
 	.d_ioctl =	kqemu_ioctl,
 	.d_close =	kqemu_close,
@@ -334,8 +346,15 @@
 #if __FreeBSD_version >= 500000
     dev->si_drv1 = NULL;
     TAILQ_REMOVE(&kqemuhead, ks, kqemu_ent);
+#if __FreeBSD_version >= 700051
+    destroy_dev_sched(dev);
+#else
+#if __FreeBSD_version >= 700024
+    dev_relthread(dev); 
+#endif
     destroy_dev(dev);
 #endif
+#endif
     free(ks, M_KQEMU);
     --kqemu_ref_count;
 }
@@ -412,6 +431,19 @@
 	ks->state = s;
 	break;
     }
+    case KQEMU_SET_PHYS_MEM: {
+	struct kqemu_phys_mem kphys_mem;
+	if (!s) {
+	    ret = -EIO;
+	    break;
+	}
+	kphys_mem = *(struct kqemu_phys_mem *)addr;
+	ret = kqemu_set_phys_mem(s, &kphys_mem);
+	if (ret != 0) {
+	    ret = -EINVAL;
+	}
+	break;
+    }
     case KQEMU_EXEC: {
 	struct kqemu_cpu_state *ctx;
 	if (s == NULL) {
@@ -514,7 +546,13 @@
 	while ((ks = TAILQ_FIRST(&kqemuhead)) != NULL) {
 	    kqemu_destroy(ks);
 	}
+#if __FreeBSD_version >= 700051
+	drain_dev_clone_events();
+#endif
 	clone_cleanup(&kqemuclones);
+#if __FreeBSD_version >= 700051
+	destroy_dev_drain(&kqemu_cdevsw);
+#endif
 #endif
         kqemu_global_delete(kqemu_gs);
         kqemu_gs = NULL;
