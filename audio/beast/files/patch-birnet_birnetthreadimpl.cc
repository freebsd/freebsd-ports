--- birnet/birnetthreadimpl.cc.orig	2010-05-11 15:06:34.000000000 +0200
+++ birnet/birnetthreadimpl.cc	2010-05-11 15:07:34.000000000 +0200
@@ -1483,18 +1483,22 @@ fallback_thread_exit (gpointer retval)
 
 #ifdef g_atomic_int_get
 static int
-(g_atomic_int_get) (volatile int *atomic)
+birnet_g_atomic_int_get (volatile int *atomic)
 {
   return g_atomic_int_get (atomic);
 }
+#undef  g_atomic_int_get
+#define g_atomic_int_get birnet_g_atomic_int_get
 #endif
 
 #ifdef g_atomic_pointer_get
 static void*
-(g_atomic_pointer_get) (volatile void **atomic)
+birnet_g_atomic_pointer_get (volatile void **atomic)
 {
   return (void*) g_atomic_pointer_get (atomic);
 }
+#undef  g_atomic_pointer_get
+#define g_atomic_pointer_get birnet_g_atomic_pointer_get
 #endif
 
 
