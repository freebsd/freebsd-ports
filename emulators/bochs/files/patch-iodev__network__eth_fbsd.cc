--- iodev/network/eth_fbsd.cc.orig	2012-09-02 20:30:11.000000000 +0900
+++ iodev/network/eth_fbsd.cc	2012-09-03 23:41:03.000000000 +0900
@@ -235,6 +235,14 @@
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
