Index: kqemu-freebsd.c
@@ -236,6 +236,7 @@
 };
 
 static int kqemu_ref_count = 0;
+static int max_locked_pages;
 static struct kqemu_global_state *kqemu_gs = NULL;
 
 #if __FreeBSD_version < 500000
