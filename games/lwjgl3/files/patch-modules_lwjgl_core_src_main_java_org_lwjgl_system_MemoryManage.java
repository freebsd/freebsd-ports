--- modules/lwjgl/core/src/main/java/org/lwjgl/system/MemoryManage.java.orig	2023-12-18 14:22:59 UTC
+++ modules/lwjgl/core/src/main/java/org/lwjgl/system/MemoryManage.java
@@ -34,6 +34,9 @@ final class MemoryManage {
             String className;
             if (allocator == null || "jemalloc".equals(allocator)) {
                 className = "org.lwjgl.system.jemalloc.JEmallocAllocator";
+                if (Platform.get() == Platform.FREEBSD) {
+                    Configuration.JEMALLOC_LIBRARY_NAME.set("libc.so.7");
+                }
             } else if ("rpmalloc".equals(allocator)) {
                 className = "org.lwjgl.system.rpmalloc.RPmallocAllocator";
             } else {
