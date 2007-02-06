Index: kqemu-freebsd.c
@@ -321,6 +321,9 @@
 #if __FreeBSD_version >= 500000
     dev->si_drv1 = NULL;
     TAILQ_REMOVE(&kqemuhead, ks, kqemu_ent);
+#if __FreeBSD_version >= 700024
+    dev_relthread(dev); 
+#endif
     destroy_dev(dev);
 #endif
     free(ks, M_KQEMU);

