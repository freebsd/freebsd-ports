--- ./src/gmalloc.c.orig	2007-09-27 19:31:50.000000000 +0300
+++ ./src/gmalloc.c	2007-09-27 19:31:54.000000000 +0300
@@ -1,9 +1,6 @@
 /* This file is no longer automatically generated from libc.  */
 
 #define _MALLOC_INTERNAL
-#ifdef HAVE_GTK_AND_PTHREAD
-#define USE_PTHREAD
-#endif
 
 /* The malloc headers and source files from the C library follow here.  */
 
@@ -40,6 +37,10 @@
 #include <config.h>
 #endif
 
+#ifdef HAVE_GTK_AND_PTHREAD
+#define USE_PTHREAD
+#endif
+
 #if ((defined __cplusplus || (defined (__STDC__) && __STDC__) \
       || defined STDC_HEADERS || defined PROTOTYPES) \
      && ! defined (BROKEN_PROTOTYPES))
@@ -128,6 +129,8 @@
 #if ! (defined (_MALLOC_INTERNAL) && __DJGPP__ - 0 == 1) /* Avoid conflict.  */
 extern __ptr_t memalign PP ((__malloc_size_t __alignment,
 			     __malloc_size_t __size));
+extern int posix_memalign PP ((__ptr_t *, __malloc_size_t,
+			       __malloc_size_t size));
 #endif
 
 /* Allocate SIZE bytes on a page boundary.  */
@@ -135,6 +138,10 @@
 extern __ptr_t valloc PP ((__malloc_size_t __size));
 #endif
 
+#ifdef USE_PTHREAD
+/* Set up mutexes and make malloc etc. thread-safe.  */
+extern void malloc_enable_thread PP ((void));
+#endif
 
 #ifdef _MALLOC_INTERNAL
 
@@ -235,14 +242,38 @@
 extern __ptr_t _malloc_internal PP ((__malloc_size_t __size));
 extern __ptr_t _realloc_internal PP ((__ptr_t __ptr, __malloc_size_t __size));
 extern void _free_internal PP ((__ptr_t __ptr));
+extern __ptr_t _malloc_internal_nolock PP ((__malloc_size_t __size));
+extern __ptr_t _realloc_internal_nolock PP ((__ptr_t __ptr, __malloc_size_t __size));
+extern void _free_internal_nolock PP ((__ptr_t __ptr));
 
 #ifdef USE_PTHREAD
-extern pthread_mutex_t _malloc_mutex;
-#define LOCK()     pthread_mutex_lock (&_malloc_mutex)
-#define UNLOCK()   pthread_mutex_unlock (&_malloc_mutex)
+extern pthread_mutex_t _malloc_mutex, _aligned_blocks_mutex;
+extern int _malloc_thread_enabled_p;
+#define LOCK()					\
+  do {						\
+    if (_malloc_thread_enabled_p)		\
+      pthread_mutex_lock (&_malloc_mutex);	\
+  } while (0)
+#define UNLOCK()				\
+  do {						\
+    if (_malloc_thread_enabled_p)		\
+      pthread_mutex_unlock (&_malloc_mutex);	\
+  } while (0)
+#define LOCK_ALIGNED_BLOCKS()				\
+  do {							\
+    if (_malloc_thread_enabled_p)			\
+      pthread_mutex_lock (&_aligned_blocks_mutex);	\
+  } while (0)
+#define UNLOCK_ALIGNED_BLOCKS()				\
+  do {							\
+    if (_malloc_thread_enabled_p)			\
+      pthread_mutex_unlock (&_aligned_blocks_mutex);	\
+  } while (0)
 #else
 #define LOCK()
 #define UNLOCK()
+#define LOCK_ALIGNED_BLOCKS()
+#define UNLOCK_ALIGNED_BLOCKS()
 #endif
 
 #endif /* _MALLOC_INTERNAL.  */
@@ -373,7 +404,7 @@
 extern __ptr_t bss_sbrk PP ((ptrdiff_t __size));
 extern int bss_sbrk_did_unexec;
 #endif
-__ptr_t (*__morecore) PP ((ptrdiff_t __size)) = __default_morecore;
+__ptr_t (*__morecore) PP ((__malloc_ptrdiff_t __size)) = __default_morecore;
 
 /* Debugging hook for `malloc'.  */
 __ptr_t (*__malloc_hook) PP ((__malloc_size_t __size));
@@ -553,8 +584,49 @@
 }
 
 #ifdef USE_PTHREAD
-static pthread_once_t malloc_init_once_control = PTHREAD_ONCE_INIT;
-pthread_mutex_t _malloc_mutex;
+pthread_mutex_t _malloc_mutex = PTHREAD_MUTEX_INITIALIZER;
+pthread_mutex_t _aligned_blocks_mutex = PTHREAD_MUTEX_INITIALIZER;
+int _malloc_thread_enabled_p;
+
+static void
+malloc_atfork_handler_prepare ()
+{
+  LOCK ();
+  LOCK_ALIGNED_BLOCKS ();
+}
+
+static void
+malloc_atfork_handler_parent ()
+{
+  UNLOCK_ALIGNED_BLOCKS ();
+  UNLOCK ();
+}
+
+static void
+malloc_atfork_handler_child ()
+{
+  UNLOCK_ALIGNED_BLOCKS ();
+  UNLOCK ();
+}
+
+/* Set up mutexes and make malloc etc. thread-safe.  */
+void
+malloc_enable_thread ()
+{
+  if (_malloc_thread_enabled_p)
+    return;
+
+  /* Some pthread implementations call malloc for statically
+     initialized mutexes when they are used first.  To avoid such a
+     situation, we initialize mutexes here while their use is
+     disabled in malloc etc.  */
+  pthread_mutex_init (&_malloc_mutex, NULL);
+  pthread_mutex_init (&_aligned_blocks_mutex, NULL);
+  pthread_atfork (malloc_atfork_handler_prepare,
+		  malloc_atfork_handler_parent,
+		  malloc_atfork_handler_child);
+  _malloc_thread_enabled_p = 1;
+}
 #endif
 
 static void
@@ -567,17 +639,6 @@
   if (__malloc_initialize_hook)
     (*__malloc_initialize_hook) ();
 
-#ifdef USE_PTHREAD
-  {
-    pthread_mutexattr_t attr;
-
-    pthread_mutexattr_init (&attr);
-    pthread_mutexattr_settype (&attr, PTHREAD_MUTEX_RECURSIVE);
-    pthread_mutex_init (&_malloc_mutex, &attr);
-    pthread_mutexattr_destroy (&attr);
-  }
-#endif
-
   heapsize = HEAP / BLOCKSIZE;
   _heapinfo = (malloc_info *) align (heapsize * sizeof (malloc_info));
   if (_heapinfo == NULL)
@@ -596,18 +657,16 @@
   return;
 }
 
-/* Set everything up and remember that we have.  */
+/* Set everything up and remember that we have.
+   main will call malloc which calls this function.  That is before any threads
+   or signal handlers has been set up, so we don't need thread protection.  */
 int
 __malloc_initialize ()
 {
-#ifdef USE_PTHREAD
-  pthread_once (&malloc_init_once_control, malloc_initialize_1);
-#else
   if (__malloc_initialized)
     return 0;
 
   malloc_initialize_1 ();
-#endif
 
   return __malloc_initialized;
 }
@@ -616,9 +675,9 @@
 
 /* Get neatly aligned memory, initializing or
    growing the heap info table as necessary. */
-static __ptr_t morecore PP ((__malloc_size_t));
+static __ptr_t morecore_nolock PP ((__malloc_size_t));
 static __ptr_t
-morecore (size)
+morecore_nolock (size)
      __malloc_size_t size;
 {
   __ptr_t result;
@@ -661,7 +720,7 @@
 	     `morecore_recursing' flag and return null.  */
 	  int save = errno;	/* Don't want to clobber errno with ENOMEM.  */
 	  morecore_recursing = 1;
-	  newinfo = (malloc_info *) _realloc_internal
+	  newinfo = (malloc_info *) _realloc_internal_nolock
 	    (_heapinfo, newsize * sizeof (malloc_info));
 	  morecore_recursing = 0;
 	  if (newinfo == NULL)
@@ -717,7 +776,7 @@
       /* Reset _heaplimit so _free_internal never decides
 	 it can relocate or resize the info table.  */
       _heaplimit = 0;
-      _free_internal (oldinfo);
+      _free_internal_nolock (oldinfo);
       PROTECT_MALLOC_STATE (0);
 
       /* The new heap limit includes the new table just allocated.  */
@@ -732,7 +791,7 @@
 
 /* Allocate memory from the heap.  */
 __ptr_t
-_malloc_internal (size)
+_malloc_internal_nolock (size)
      __malloc_size_t size;
 {
   __ptr_t result;
@@ -752,7 +811,6 @@
     return NULL;
 #endif
 
-  LOCK ();
   PROTECT_MALLOC_STATE (0);
 
   if (size < sizeof (struct list))
@@ -802,8 +860,10 @@
 	  /* No free fragments of the desired size, so get a new block
 	     and break it into fragments, returning the first.  */
 #ifdef GC_MALLOC_CHECK
-	  result = _malloc_internal (BLOCKSIZE);
+	  result = _malloc_internal_nolock (BLOCKSIZE);
 	  PROTECT_MALLOC_STATE (0);
+#elif defined (USE_PTHREAD)
+	  result = _malloc_internal_nolock (BLOCKSIZE);
 #else
 	  result = malloc (BLOCKSIZE);
 #endif
@@ -874,7 +934,7 @@
  		  _heaplimit += wantblocks - lastblocks;
 		  continue;
 		}
-	      result = morecore (wantblocks * BLOCKSIZE);
+	      result = morecore_nolock (wantblocks * BLOCKSIZE);
 	      if (result == NULL)
 		goto out;
 	      block = BLOCK (result);
@@ -932,7 +992,19 @@
 
   PROTECT_MALLOC_STATE (1);
  out:
+  return result;
+}
+
+__ptr_t
+_malloc_internal (size)
+     __malloc_size_t size;
+{
+  __ptr_t result;
+
+  LOCK ();
+  result = _malloc_internal_nolock (size);
   UNLOCK ();
+
   return result;
 }
 
@@ -940,10 +1012,21 @@
 malloc (size)
      __malloc_size_t size;
 {
+  __ptr_t (*hook) (__malloc_size_t);
+
   if (!__malloc_initialized && !__malloc_initialize ())
     return NULL;
 
-  return (__malloc_hook != NULL ? *__malloc_hook : _malloc_internal) (size);
+  /* Copy the value of __malloc_hook to an automatic variable in case
+     __malloc_hook is modified in another thread between its
+     NULL-check and the use.
+
+     Note: Strictly speaking, this is not a right solution.  We should
+     use mutexes to access non-read-only variables that are shared
+     among multiple threads.  We just leave it for compatibility with
+     glibc malloc (i.e., assignments to __malloc_hook) for now.  */
+  hook = __malloc_hook;
+  return (hook != NULL ? *hook : _malloc_internal) (size);
 }
 
 #ifndef _LIBC
@@ -1024,9 +1107,9 @@
 struct alignlist *_aligned_blocks = NULL;
 
 /* Return memory to the heap.
-   Like `free' but don't call a __free_hook if there is one.  */
+   Like `_free_internal' but don't lock mutex.  */
 void
-_free_internal (ptr)
+_free_internal_nolock (ptr)
      __ptr_t ptr;
 {
   int type;
@@ -1043,9 +1126,9 @@
   if (ptr == NULL)
     return;
 
-  LOCK ();
   PROTECT_MALLOC_STATE (0);
 
+  LOCK_ALIGNED_BLOCKS ();
   for (l = _aligned_blocks; l != NULL; l = l->next)
     if (l->aligned == ptr)
       {
@@ -1053,6 +1136,7 @@
 	ptr = l->exact;
 	break;
       }
+  UNLOCK_ALIGNED_BLOCKS ();
 
   block = BLOCK (ptr);
 
@@ -1158,7 +1242,7 @@
 		 table's blocks to the system before we have copied them to
 		 the new location.  */
 	      _heaplimit = 0;
-	      _free_internal (_heapinfo);
+	      _free_internal_nolock (_heapinfo);
 	      _heaplimit = oldlimit;
 
 	      /* Tell malloc to search from the beginning of the heap for
@@ -1166,8 +1250,8 @@
 	      _heapindex = 0;
 
 	      /* Allocate new space for the info table and move its data.  */
-	      newinfo = (malloc_info *) _malloc_internal (info_blocks
-							  * BLOCKSIZE);
+	      newinfo = (malloc_info *) _malloc_internal_nolock (info_blocks
+								 * BLOCKSIZE);
 	      PROTECT_MALLOC_STATE (0);
 	      memmove (newinfo, _heapinfo, info_blocks * BLOCKSIZE);
 	      _heapinfo = newinfo;
@@ -1230,8 +1314,8 @@
 	  _chunks_free -= BLOCKSIZE >> type;
 	  _bytes_free -= BLOCKSIZE;
 
-#ifdef GC_MALLOC_CHECK
-	  _free_internal (ADDRESS (block));
+#if defined (GC_MALLOC_CHECK) || defined (USE_PTHREAD)
+	  _free_internal_nolock (ADDRESS (block));
 #else
 	  free (ADDRESS (block));
 #endif
@@ -1269,6 +1353,16 @@
     }
 
   PROTECT_MALLOC_STATE (1);
+}
+
+/* Return memory to the heap.
+   Like `free' but don't call a __free_hook if there is one.  */
+void
+_free_internal (ptr)
+     __ptr_t ptr;
+{
+  LOCK ();
+  _free_internal_nolock (ptr);
   UNLOCK ();
 }
 
@@ -1278,8 +1372,10 @@
 free (ptr)
      __ptr_t ptr;
 {
-  if (__free_hook != NULL)
-    (*__free_hook) (ptr);
+  void (*hook) (__ptr_t) = __free_hook;
+
+  if (hook != NULL)
+    (*hook) (ptr);
   else
     _free_internal (ptr);
 }
@@ -1415,7 +1511,7 @@
    new region.  This module has incestuous knowledge of the
    internals of both free and malloc. */
 __ptr_t
-_realloc_internal (ptr, size)
+_realloc_internal_nolock (ptr, size)
      __ptr_t ptr;
      __malloc_size_t size;
 {
@@ -1425,15 +1521,14 @@
 
   if (size == 0)
     {
-      _free_internal (ptr);
-      return _malloc_internal (0);
+      _free_internal_nolock (ptr);
+      return _malloc_internal_nolock (0);
     }
   else if (ptr == NULL)
-    return _malloc_internal (size);
+    return _malloc_internal_nolock (size);
 
   block = BLOCK (ptr);
 
-  LOCK ();
   PROTECT_MALLOC_STATE (0);
 
   type = _heapinfo[block].busy.type;
@@ -1443,11 +1538,11 @@
       /* Maybe reallocate a large block to a small fragment.  */
       if (size <= BLOCKSIZE / 2)
 	{
-	  result = _malloc_internal (size);
+	  result = _malloc_internal_nolock (size);
 	  if (result != NULL)
 	    {
 	      memcpy (result, ptr, size);
-	      _free_internal (ptr);
+	      _free_internal_nolock (ptr);
 	      goto out;
 	    }
 	}
@@ -1467,7 +1562,7 @@
 	     Now we will free this chunk; increment the statistics counter
 	     so it doesn't become wrong when _free_internal decrements it.  */
 	  ++_chunks_used;
-	  _free_internal (ADDRESS (block + blocks));
+	  _free_internal_nolock (ADDRESS (block + blocks));
 	  result = ptr;
 	}
       else if (blocks == _heapinfo[block].busy.info.size)
@@ -1482,8 +1577,8 @@
 	  /* Prevent free from actually returning memory to the system.  */
 	  oldlimit = _heaplimit;
 	  _heaplimit = 0;
-	  _free_internal (ptr);
-	  result = _malloc_internal (size);
+	  _free_internal_nolock (ptr);
+	  result = _malloc_internal_nolock (size);
 	  PROTECT_MALLOC_STATE (0);
 	  if (_heaplimit == 0)
 	    _heaplimit = oldlimit;
@@ -1493,13 +1588,13 @@
 		 the thing we just freed.  Unfortunately it might
 		 have been coalesced with its neighbors.  */
 	      if (_heapindex == block)
-	        (void) _malloc_internal (blocks * BLOCKSIZE);
+	        (void) _malloc_internal_nolock (blocks * BLOCKSIZE);
 	      else
 		{
 		  __ptr_t previous
-		    = _malloc_internal ((block - _heapindex) * BLOCKSIZE);
-		  (void) _malloc_internal (blocks * BLOCKSIZE);
-		  _free_internal (previous);
+		    = _malloc_internal_nolock ((block - _heapindex) * BLOCKSIZE);
+		  (void) _malloc_internal_nolock (blocks * BLOCKSIZE);
+		  _free_internal_nolock (previous);
 		}
 	      goto out;
 	    }
@@ -1519,18 +1614,31 @@
 	{
 	  /* The new size is different; allocate a new space,
 	     and copy the lesser of the new size and the old. */
-	  result = _malloc_internal (size);
+	  result = _malloc_internal_nolock (size);
 	  if (result == NULL)
 	    goto out;
 	  memcpy (result, ptr, min (size, (__malloc_size_t) 1 << type));
-	  _free_internal (ptr);
+	  _free_internal_nolock (ptr);
 	}
       break;
     }
 
   PROTECT_MALLOC_STATE (1);
  out:
+  return result;
+}
+
+__ptr_t
+_realloc_internal (ptr, size)
+     __ptr_t ptr;
+     __malloc_size_t size;
+{
+  __ptr_t result;
+
+  LOCK();
+  result = _realloc_internal_nolock (ptr, size);
   UNLOCK ();
+
   return result;
 }
 
@@ -1539,11 +1647,13 @@
      __ptr_t ptr;
      __malloc_size_t size;
 {
+  __ptr_t (*hook) (__ptr_t, __malloc_size_t);
+
   if (!__malloc_initialized && !__malloc_initialize ())
     return NULL;
 
-  return (__realloc_hook != NULL ? *__realloc_hook : _realloc_internal)
-    (ptr, size);
+  hook = __realloc_hook;
+  return (hook != NULL ? *hook : _realloc_internal) (ptr, size);
 }
 /* Copyright (C) 1991, 1992, 1994 Free Software Foundation, Inc.
 
@@ -1681,9 +1791,10 @@
 {
   __ptr_t result;
   unsigned long int adj, lastadj;
+  __ptr_t (*hook) (__malloc_size_t, __malloc_size_t) = __memalign_hook;
 
-  if (__memalign_hook)
-    return (*__memalign_hook) (alignment, size);
+  if (hook)
+    return (*hook) (alignment, size);
 
   /* Allocate a block with enough extra space to pad the block with up to
      (ALIGNMENT - 1) bytes if necessary.  */
@@ -1718,6 +1829,7 @@
 	 of an allocated block.  */
 
       struct alignlist *l;
+      LOCK_ALIGNED_BLOCKS ();
       for (l = _aligned_blocks; l != NULL; l = l->next)
 	if (l->aligned == NULL)
 	  /* This slot is free.  Use it.  */
@@ -1725,21 +1837,58 @@
       if (l == NULL)
 	{
 	  l = (struct alignlist *) malloc (sizeof (struct alignlist));
-	  if (l == NULL)
+	  if (l != NULL)
 	    {
-	      free (result);
-	      return NULL;
+	      l->next = _aligned_blocks;
+	      _aligned_blocks = l;
 	    }
-	  l->next = _aligned_blocks;
-	  _aligned_blocks = l;
 	}
-      l->exact = result;
-      result = l->aligned = (char *) result + alignment - adj;
+      if (l != NULL)
+	{
+	  l->exact = result;
+	  result = l->aligned = (char *) result + alignment - adj;
+	}
+      UNLOCK_ALIGNED_BLOCKS ();
+      if (l == NULL)
+	{
+	  free (result);
+	  result = NULL;
+	}
     }
 
   return result;
 }
 
+#ifndef ENOMEM
+#define ENOMEM 12
+#endif
+
+#ifndef EINVAL
+#define EINVAL 22
+#endif
+
+int
+posix_memalign (memptr, alignment, size)
+     __ptr_t *memptr;
+     __malloc_size_t alignment;
+     __malloc_size_t size;
+{
+  __ptr_t mem;
+
+  if (alignment == 0
+      || alignment % sizeof (__ptr_t) != 0
+      || (alignment & (alignment - 1)) != 0)
+    return EINVAL;
+
+  mem = memalign (alignment, size);
+  if (mem == NULL)
+    return ENOMEM;
+
+  *memptr = mem;
+
+  return 0;
+}
+
 #endif /* Not DJGPP v1 */
 /* Allocate memory on a page boundary.
    Copyright (C) 1991, 92, 93, 94, 96 Free Software Foundation, Inc.
