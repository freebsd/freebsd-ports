Index: kqemu-freebsd.c
@@ -208,9 +208,17 @@
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
@@ -320,6 +328,9 @@
 #if __FreeBSD_version >= 500000
     dev->si_drv1 = NULL;
     TAILQ_REMOVE(&kqemuhead, ks, kqemu_ent);
+#if __FreeBSD_version >= 700024
+    dev_relthread(dev); 
+#endif
     destroy_dev(dev);
 #endif
     free(ks, M_KQEMU);
