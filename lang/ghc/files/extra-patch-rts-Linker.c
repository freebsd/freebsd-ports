--- rts/Linker.c.orig	2007-12-10 19:11:32.000000000 +0100
+++ rts/Linker.c	2008-01-09 22:17:46.459941137 +0100
@@ -59,12 +59,12 @@
 #include <sys/wait.h>
 #endif
 
-#if defined(ia64_HOST_ARCH) || defined(openbsd_HOST_OS) || defined(linux_HOST_OS) || defined(freebsd_HOST_OS)
+#if defined(ia64_HOST_ARCH) || defined(linux_HOST_OS) || defined(freebsd_HOST_OS) || defined(netbsd_HOST_OS) || defined(openbsd_HOST_OS)
 #define USE_MMAP
 #include <fcntl.h>
 #include <sys/mman.h>
 
-#if defined(openbsd_HOST_OS) || defined(linux_HOST_OS) || defined(freebsd_HOST_OS)
+#if defined(linux_HOST_OS) || defined(freebsd_HOST_OS) || defined(netbsd_HOST_OS) || defined(openbsd_HOST_OS)
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
@@ -1199,8 +1199,10 @@
    struct stat st;
    int r, n;
 #ifdef USE_MMAP
+   /* In the absence of a MAP_32BIT flag to mmap() we map objects one
+    * after the other starting from a fixed location in memory. */
    int fd, pagesize;
-   void *map_addr = NULL;
+   static void *map_addr = (void *)0x40000000L;
 #else
    FILE *f;
 #endif
@@ -1262,6 +1264,7 @@
 
 #ifdef USE_MMAP
 #define ROUND_UP(x,size) ((x + size - 1) & ~(size - 1))
+#define ROUND_DOWN(x,size) (x & ~(size - 1))
 
    /* On many architectures malloc'd memory isn't executable, so we need to use mmap. */
 
@@ -1278,7 +1281,7 @@
 #ifdef ia64_HOST_ARCH
    /* The PLT needs to be right before the object */
    n = ROUND_UP(PLTSize(), pagesize);
-   oc->plt = mmap(NULL, n, PROT_EXEC|PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
+   oc->plt = mmap(map_addr, n, PROT_EXEC|PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    if (oc->plt == MAP_FAILED)
       barf("loadObj: can't allocate PLT");
 
@@ -1297,7 +1300,7 @@
 #if defined(x86_64_HOST_ARCH) && defined(MAP_32BIT)
 #define EXTRA_MAP_FLAGS MAP_32BIT
 #else
-#define EXTRA_MAP_FLAGS 0
+#define EXTRA_MAP_FLAGS MAP_FIXED
 #endif
 
    /* MAP_ANONYMOUS is MAP_ANON on some systems, e.g. OpenBSD */
@@ -1309,6 +1312,7 @@
 		    MAP_PRIVATE|EXTRA_MAP_FLAGS, fd, 0);
    if (oc->image == MAP_FAILED)
       barf("loadObj: can't map `%s'", path);
+   map_addr += n;
 
    close(fd);
 
@@ -2596,10 +2600,12 @@
 #define Elf_Sym     Elf64_Sym
 #define Elf_Rel     Elf64_Rel
 #define Elf_Rela    Elf64_Rela
+#if !defined(freebsd_HOST_OS)
 #define ELF_ST_TYPE ELF64_ST_TYPE
 #define ELF_ST_BIND ELF64_ST_BIND
 #define ELF_R_TYPE  ELF64_R_TYPE
 #define ELF_R_SYM   ELF64_R_SYM
+#endif
 #else
 #define ELFCLASS    ELFCLASS32
 #define Elf_Addr    Elf32_Addr
@@ -2772,15 +2778,35 @@
 x86_64_high_symbol( char *lbl, void *addr )
 {
     x86_64_bounce *bounce;
+    int pagesize;
+
+    pagesize = getpagesize();
 
-    if ( x86_64_bounce_buffer == NULL || 
+    if ( x86_64_bounce_buffer == NULL ||
 	 x86_64_bb_next_off >= X86_64_BB_SIZE ) {
-	x86_64_bounce_buffer = 
-	    mmap(NULL, X86_64_BB_SIZE * sizeof(x86_64_bounce), 
-		 PROT_EXEC|PROT_READ|PROT_WRITE, 
-		 MAP_PRIVATE|EXTRA_MAP_FLAGS|MAP_ANONYMOUS, -1, 0);
+#ifdef MAP_32BIT
+	    x86_64_bounce_buffer =
+		mmap(NULL, X86_64_BB_SIZE * sizeof(x86_64_bounce),
+		     PROT_EXEC|PROT_READ|PROT_WRITE,
+		     MAP_PRIVATE|EXTRA_MAP_FLAGS|MAP_ANONYMOUS, -1, 0);
+#else
+#define X86_64_BOUNCE_BUFFER_TOP 0x80000000L;
+	    x86_64_bounce *map_addr;
+
+	    x86_64_bounce_buffer = x86_64_bounce_buffer ?
+		    x86_64_bounce_buffer : (x86_64_bounce *)X86_64_BOUNCE_BUFFER_TOP;
+	    map_addr = x86_64_bounce_buffer - X86_64_BB_SIZE;
+	    map_addr = ROUND_DOWN((int)map_addr, pagesize);
+	    /* In the absence of MAP_32BIT we allocate the bounce
+	     * buffers at a fixed address, one after the other,
+	     * starting from the top and growing downwards. */
+	    x86_64_bounce_buffer =
+		mmap(map_addr, X86_64_BB_SIZE * sizeof(x86_64_bounce),
+		     PROT_EXEC|PROT_READ|PROT_WRITE,
+		     MAP_PRIVATE|EXTRA_MAP_FLAGS|MAP_ANONYMOUS, -1, 0);
+#endif
 	if (x86_64_bounce_buffer == MAP_FAILED) {
-	    barf("x86_64_high_symbol: mmap failed");
+	    barf("x86_64_high_symbol: mmap failed at %p", x86_64_bounce_buffer);
 	}
 	x86_64_bb_next_off = 0;
     }
