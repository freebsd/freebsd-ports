--- src/display/fbdev.cpp.orig	Fri Feb 15 20:15:58 2002
+++ src/display/fbdev.cpp	Sun Feb 24 14:25:35 2002
@@ -202,7 +202,11 @@
     }
 
     // printf ("len %d\n", mpBufLen);
+#if (__FreeBSD__ <= 3)
     if ((mFd = open("/dev/vga", O_RDWR | O_NDELAY)) < 0) {
+#else
+    if ((mFd = open("/dev/mem", O_RDWR | O_NDELAY)) < 0) {
+#endif
         throw(runtime_error("Can not open vga device.\n"));
     }
 
@@ -229,8 +233,13 @@
             throw(runtime_error("color depth unsupported in this version\n"
                 "use 8bpp instead!"));
     }
+#if (__FreeBSD__ <= 3)
+#define GRAPH_BASE 0x0
+#else
+#define GRAPH_BASE 0xA0000
+#endif
     mpBuf = static_cast<char *>(mmap(0, mpBufLen, PROT_READ | PROT_WRITE,
-                                MAP_SHARED, mFd, 0));
+			MAP_FILE|MAP_SHARED|MAP_FIXED, mFd, GRAPH_BASE));
 
     if (mpBuf == MAP_FAILED)
         throw(runtime_error("mmap() failed!"));
