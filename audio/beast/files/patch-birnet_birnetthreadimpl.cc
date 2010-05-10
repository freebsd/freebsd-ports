Description: Correct signature for the g_atomic_pointer_get() function.
Author: Jakub Wilk <ubanus@users.sf.net>
Bug-Debian: http://bugs.debian.org/540681

Index: beast-0.7.1/birnet/birnetthreadimpl.cc
===================================================================
--- birnet/birnetthreadimpl.cc.orig	2009-12-16 20:21:24.000000000 +0100
+++ birnet/birnetthreadimpl.cc	2009-12-16 20:26:16.000000000 +0100
@@ -1491,7 +1491,7 @@
 
 #ifdef g_atomic_pointer_get
 static void*
-(g_atomic_pointer_get) (volatile void **atomic)
+(g_atomic_pointer_get) (void * volatile *atomic)
 {
   return (void*) g_atomic_pointer_get (atomic);
 }
