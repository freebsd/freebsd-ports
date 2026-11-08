--- src/java.base/bsd/classes/sun/nio/ch/KQueue.java.orig	2026-10-22 00:00:00 UTC
+++ src/java.base/bsd/classes/sun/nio/ch/KQueue.java
@@ -90,7 +90,9 @@
      * Returns the file descriptor from a kevent (assuming it is in the ident field)
      */
     static int getDescriptor(long address) {
-        return unsafe.getInt(address + OFFSET_IDENT);
+        // ident is a uintptr_t: read it at its full width so that the
+        // descriptor is also right on big-endian hosts
+        return (int) unsafe.getAddress(address + OFFSET_IDENT);
     }
 
     static short getFilter(long address) {
