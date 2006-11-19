--- iodev/eth_fbsd.cc.orig	Sat Dec 10 19:37:35 2005
+++ iodev/eth_fbsd.cc	Sun Nov 19 15:56:46 2006
@@ -227,6 +227,14 @@
     return;
   }
 
+  v = 1;
+  if (ioctl(this->bpf_fd, BIOCIMMEDIATE, &v) < 0) {
+    BX_PANIC(("eth_freebsd: could not enable immediate mode"));
+    close(this->bpf_fd);
+    this->bpf_fd = -1;
+    return;
+  }
+
   // Set up non-blocking i/o
   v = 1;
   if (ioctl(this->bpf_fd, FIONBIO, &v) < 0) {
