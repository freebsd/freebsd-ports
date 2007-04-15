--- language/modula3/m3compiler/m3cc/gcc/include/obstack.h.orig	Sat Jan 11 15:58:43 2003
+++ language/modula3/m3compiler/m3cc/gcc/include/obstack.h	Thu Jul 29 00:07:12 2004
@@ -343,7 +343,7 @@
 
 #endif
 
-#define obstack_1grow_fast(h,achar) (*((h)->next_free)++ = achar)
+#define obstack_1grow_fast(h,achar) (*((h)->next_free)++ = (achar))
 
 #define obstack_blank_fast(h,n) ((h)->next_free += (n))
 
@@ -411,7 +411,7 @@
 ({ struct obstack *__o = (OBSTACK);					\
    if (__o->next_free + 1 > __o->chunk_limit)				\
      _obstack_newchunk (__o, 1);					\
-   *(__o->next_free)++ = (datum);					\
+   obstack_1grow_fast (__o, datum);					\
    (void) 0; })
 
 /* These assume that the obstack alignment is good enough for pointers or ints,
@@ -423,19 +423,28 @@
 ({ struct obstack *__o = (OBSTACK);					\
    if (__o->next_free + sizeof (void *) > __o->chunk_limit)		\
      _obstack_newchunk (__o, sizeof (void *));				\
-   *((void **)__o->next_free)++ = ((void *)datum);			\
-   (void) 0; })
+   obstack_ptr_grow_fast (__o, datum); })
 
 # define obstack_int_grow(OBSTACK,datum)				\
 __extension__								\
 ({ struct obstack *__o = (OBSTACK);					\
    if (__o->next_free + sizeof (int) > __o->chunk_limit)		\
      _obstack_newchunk (__o, sizeof (int));				\
-   *((int *)__o->next_free)++ = ((int)datum);				\
+   obstack_int_grow_fast (__o, datum); })
+
+# define obstack_ptr_grow_fast(OBSTACK,aptr)				\
+__extension__								\
+({ struct obstack *__o1 = (OBSTACK);					\
+   *(const void **) __o1->next_free = (aptr);				\
+   __o1->next_free += sizeof (const void *);				\
    (void) 0; })
 
-# define obstack_ptr_grow_fast(h,aptr) (*((void **) (h)->next_free)++ = (void *)aptr)
-# define obstack_int_grow_fast(h,aint) (*((int *) (h)->next_free)++ = (int) aint)
+# define obstack_int_grow_fast(OBSTACK,aint)				\
+__extension__								\
+({ struct obstack *__o1 = (OBSTACK);					\
+   *(int *) __o1->next_free = (aint);					\
+   __o1->next_free += sizeof (int);					\
+   (void) 0; })
 
 # define obstack_blank(OBSTACK,length)					\
 __extension__								\
@@ -443,7 +452,7 @@
    int __len = (length);						\
    if (__o->chunk_limit - __o->next_free < __len)			\
      _obstack_newchunk (__o, __len);					\
-   __o->next_free += __len;						\
+   obstack_blank_fast (__o, __len);					\
    (void) 0; })
 
 # define obstack_alloc(OBSTACK,length)					\
@@ -530,26 +539,29 @@
 # define obstack_1grow(h,datum)						\
 ( (((h)->next_free + 1 > (h)->chunk_limit)				\
    ? (_obstack_newchunk ((h), 1), 0) : 0),				\
-  (*((h)->next_free)++ = (datum)))
+  obstack_1grow_fast (h, datum))
 
 # define obstack_ptr_grow(h,datum)					\
 ( (((h)->next_free + sizeof (char *) > (h)->chunk_limit)		\
    ? (_obstack_newchunk ((h), sizeof (char *)), 0) : 0),		\
-  (*((char **) (((h)->next_free+=sizeof(char *))-sizeof(char *))) = ((char *) datum)))
+  obstack_ptr_grow_fast (h, datum))
 
 # define obstack_int_grow(h,datum)					\
 ( (((h)->next_free + sizeof (int) > (h)->chunk_limit)			\
    ? (_obstack_newchunk ((h), sizeof (int)), 0) : 0),			\
-  (*((int *) (((h)->next_free+=sizeof(int))-sizeof(int))) = ((int) datum)))
+  obstack_int_grow_fast (h, datum))
+
+# define obstack_ptr_grow_fast(h,aptr)					\
+  (((const void **) ((h)->next_free += sizeof (void *)))[-1] = (aptr))
 
-# define obstack_ptr_grow_fast(h,aptr) (*((char **) (h)->next_free)++ = (char *) aptr)
-# define obstack_int_grow_fast(h,aint) (*((int *) (h)->next_free)++ = (int) aint)
+# define obstack_int_grow_fast(h,aint)					\
+  (((int *) ((h)->next_free += sizeof (int)))[-1] = (aptr))
 
 # define obstack_blank(h,length)					\
 ( (h)->temp = (length),							\
   (((h)->chunk_limit - (h)->next_free < (h)->temp)			\
    ? (_obstack_newchunk ((h), (h)->temp), 0) : 0),			\
-  ((h)->next_free += (h)->temp))
+  obstack_blank_fast (h, (h)->temp))
 
 # define obstack_alloc(h,length)					\
  (obstack_blank ((h), (length)), obstack_finish ((h)))
