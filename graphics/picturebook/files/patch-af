--- ../picturebook.old/ptable.c	Mon Dec 25 19:01:43 2000
+++ ptable.c	Mon Dec 25 19:03:21 2000
@@ -38,8 +38,11 @@
 		perror("virt_to_phys: open(/dev/mem)");
 		exit(1);
 	}
-
+#ifdef LINUX
 	vmem = memalign(PAGE_SIZE, (npages+1)*PAGE_SIZE);
+#else __FreeBSD__
+	vmem = malloc((npages+1)*PAGE_SIZE);/*Never mind!PAGESIZE aligned memalign is equivalent to valloc and see valloc(3).*/
+#endif
 	if (!vmem) {
 		printf("failed to allocate ptable\n");
 		exit(1);
