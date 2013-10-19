--- services/plugins/dndcp/dnd/dndLinux.c.orig
+++ services/plugins/dndcp/dnd/dndLinux.c
@@ -455,7 +455,7 @@
 DnD_CheckBlockFuse(int blockFd)                    // IN
 {
    char buf[sizeof(VMBLOCK_FUSE_READ_RESPONSE)];
-   size_t size;
+   ssize_t size;
 
    size = read(blockFd, buf, sizeof(VMBLOCK_FUSE_READ_RESPONSE));
    if (size < 0) {
