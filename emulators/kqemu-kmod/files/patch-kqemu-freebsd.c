Index: kqemu-freebsd.c
@@ -236,6 +236,7 @@
 };
 
 static int kqemu_ref_count = 0;
+static int max_locked_pages;
 static struct kqemu_global_state *kqemu_gs = NULL;
 
 #if __FreeBSD_version < 500000
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

