--- stub/l_linux.c.orig	Wed Jan 21 00:32:56 2004
+++ stub/l_linux.c	Wed Jan  5 14:43:57 2005
@@ -51,7 +51,11 @@
     // note: we can assert(count > 0);
     do {
         int n = read(fd, buf, count);
+#if defined(__FreeBSD__)
+        if (n < 0 && errno == EINTR)
+#else
         if (n == -EINTR)
+#endif
             continue;
         if (n <= 0)
             break;
@@ -71,7 +75,11 @@
     // note: we can assert(count > 0);
     do {
         int n = write(fd, buf, count);
+#if defined(__FreeBSD__)
+        if (n < 0 && errno == EINTR)
+#else
         if (n == -EINTR)
+#endif
             continue;
         if (n <= 0)
             break;
@@ -154,6 +162,16 @@
 #define nrv2e_decompress        nrv2e_decompress_asm_fast
 #endif /* __i386__ */
 
+#if defined(__FreeBSD__)
+#undef errno
+int errno;
+
+void
+exit(int status)
+{
+        _exit(status);
+}
+#endif
 
 /*************************************************************************
 // upx_main - called by our entry code
@@ -184,9 +202,13 @@
     // decompression buffer
 #if defined(USE_MALLOC)
     unsigned char *buf;
+#if defined(__FreeBSD__)
+    static int mmapsize = UPX5;
+#else
     static int malloc_args[6] = {
         0, UPX5, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0
     };
+#endif
 #else
     static unsigned char buf[BLOCKSIZE + OVERHEAD];
 #endif
@@ -207,6 +229,10 @@
     // ----- Step 1: prepare input file -----
     //
 
+#if defined(__FreeBSD__)
+    SET4(procself, 'f', 'i', 'l', 'e');
+    fdi = open(procself_buf, O_RDONLY, 0);
+#else
     // Open the exe.
     SET3(procself, 'e', 'x', 'e');
     fdi = open(procself_buf, O_RDONLY, 0);
@@ -218,6 +244,7 @@
         fdi = open(procself_buf, O_RDONLY, 0);
     }
 #endif
+#endif
 #if 0
     // Save some bytes of code - the lseek() below will fail anyway.
     if (fdi < 0)
@@ -294,12 +321,20 @@
     // Just in case, remove the file.
     {
         int err = unlink(tmpname);
+#if defined(__FreeBSD__)
+        if (err < 0 && errno != ENOENT)
+#else
         if (err != -ENOENT && err != 0)
+#endif
             goto error1;
     }
 
     // Create the temporary output file.
+#if defined(__FreeBSD__)
+    fdo = open(tmpname, O_RDWR | O_CREAT | O_EXCL, 0700);
+#else
     fdo = open(tmpname, O_WRONLY | O_CREAT | O_EXCL, 0700);
+#endif
 #if 0
     // Save some bytes of code - the ftruncate() below will fail anyway.
     if (fdo < 0)
@@ -316,7 +351,11 @@
     //
 
 #if defined(USE_MALLOC)
+#if defined(__FreeBSD__)
+    buf = (unsigned char *) mmap(0, mmapsize, PROT_READ | PROT_WRITE, MAP_PRIVATE, fdo, 0);
+#else
     buf = (unsigned char *) mmap(malloc_args);
+#endif
     if ((unsigned long) buf >= (unsigned long) -4095)
         goto error;
 #else
@@ -403,8 +442,12 @@
     //
 
 #if defined(USE_MALLOC)
+#if defined(__FreeBSD__)
+    munmap(buf, mmapsize);
+#else
     munmap(buf, malloc_args[1]);
 #endif
+#endif
 
     if (close(fdo) != 0)
         goto error;
@@ -416,6 +459,7 @@
     // ----- Step 6: try to start program via /proc/self/fd/X -----
     //
 
+#if !defined(__FreeBSD__)
     // Many thanks to Andi Kleen <ak@muc.de> and
     // Jamie Lokier <nospam@cern.ch> for this nice idea.
 
@@ -446,6 +490,7 @@
 
     // The proc filesystem isn't working. No problem.
     close(fdi);
+#endif
 
 
     //
@@ -472,7 +517,11 @@
     }
 
     // Wait for the first fork()'d process to die.
+#if defined(__FreeBSD__)
+    wait4(-1, 0, 0, 0);
+#else
     waitpid(-1, (int *)0, 0);
+#endif
 
     // Execute the original program.
     execve(tmpname, argv, envp);
