--- c/codemanager.c.orig	Tue Dec  2 17:46:39 2003
+++ c/codemanager.c	Sun Aug  1 08:41:16 2004
@@ -2,21 +2,12 @@
 #include <ipyencoding.h>
 
 /*** Allocators for Large Executable Blocks of Memory ***/
-/* Defaults, possibly overridden below */
-#define LEBM_WITH_MMAP         0  /* assume memory executable by default */
-#define LEBM_NUM_BIGBLOCKS     1  /* not too large blocks */
 
 #ifndef MS_WINDOWS
 /* Assume UNIX */
 #  include <sys/mman.h>
-#  if defined(MAP_ANONYMOUS) || defined(MAP_ANON)
-#    undef LEBM_WITH_MMAP
-#    undef LEBM_NUM_BIGBLOCKS
-#    define LEBM_WITH_MMAP           1  /* use mmap() with PROT_EXEC */
-#    define LEBM_NUM_BIGBLOCKS      32  /* ask for 32MB at a time */
-#    ifndef MAP_ANONYMOUS
-#      define MAP_ANONYMOUS  MAP_ANON
-#    endif
+#  if defined(MAP_ANON) && !defined(MAP_ANONYMOUS)
+#    define MAP_ANONYMOUS  MAP_ANON
 #  endif
 #endif
 
@@ -42,22 +33,44 @@
 
 static void allocate_more_buffers(codemanager_buf_t** bb)
 {
-  char* p;
-  int i;
-  
-#if LEBM_WITH_MMAP
-  p = (char*) mmap(NULL, BIG_BUFFER_SIZE * LEBM_NUM_BIGBLOCKS,
-                   PROT_EXEC|PROT_READ|PROT_WRITE,
-                   MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
-  if (p == MAP_FAILED)
-    OUT_OF_MEMORY();
-#else
-  p = (char*) PyMem_MALLOC(BIG_BUFFER_SIZE * LEBM_NUM_BIGBLOCKS);
-  if (!p)
-    OUT_OF_MEMORY();
+  char* p = NULL;
+  int num_bigblocks = 1;
+
+#if defined(MAP_ANONYMOUS) && defined(MAP_PRIVATE)
+  /* if we have anonymous mmap's, try using that -- this is known
+     to fail on some platforms */
+  static int mmap_works = -1;
+  if (mmap_works != 0)
+    {
+      num_bigblocks = 32;    /* allocate 32MB at a time */
+      p = (char*) mmap(NULL, BIG_BUFFER_SIZE * num_bigblocks,
+                       PROT_EXEC|PROT_READ|PROT_WRITE,
+                       MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
+      if (p == MAP_FAILED || p == NULL)
+        {
+          if (mmap_works == 1)
+            OUT_OF_MEMORY();
+          mmap_works = 0;   /* doesn't work */
+          p = NULL;
+          num_bigblocks = 1;
+          /* note that some platforms *require* the allocation to be performed
+             by mmap, because PyMem_MALLOC() doesn't set the PROT_EXEC flag.
+             On these platforms we just hope that the first allocation is
+             successful, which sets mmap_works to 1; a failure in a subsequent
+             allocation correctly signals the OUT_OF_MEMORY. */
+        }
+      else
+        mmap_works = 1;
+    }
 #endif
 
-  for (i=0; i<LEBM_NUM_BIGBLOCKS; i++)
+  if (p == NULL)
+    {
+      p = (char*) PyMem_MALLOC(BIG_BUFFER_SIZE);
+      if (p == NULL)
+        OUT_OF_MEMORY();
+    }
+  while (--num_bigblocks >= 0)
     {
       /* the codemanager_buf_t structure is put at the end of the buffer,
          with its signature to detect overflows (just in case) */
