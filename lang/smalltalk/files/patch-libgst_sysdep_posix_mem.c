--- libgst/sysdep/posix/mem.c.orig
+++ libgst/sysdep/posix/mem.c
@@ -92,20 +92,27 @@
 #if defined MAP_AUTORESRV && !defined MAP_NORESERVE
 # define MAP_NORESERVE MAP_AUTORESRV
 #endif
+#if !defined(MAP_NORESERVE) && defined(__FreeBSD__)
+#define	MAP_NORESERVE	0	/* always true */
+#endif
 #ifdef MAP_NORESERVE
 static PTR noreserve_reserve (PTR, size_t);
 static void noreserve_decommit (PTR, size_t);
 #endif
+#ifndef __FreeBSD__
 static mst_Boolean anon_mmap_check (void);
 static PTR anon_mmap_reserve (PTR, size_t);
 static void anon_mmap_release (PTR, size_t);
+#endif
 static PTR anon_mmap_commit (PTR, size_t);
 
 struct heap_implementation heap_impl_tab[] = {
 #ifdef MAP_NORESERVE
   { NULL, noreserve_reserve, _gst_osmem_free, anon_mmap_commit, noreserve_decommit },
 #endif
+#ifndef __FreeBSD__
   { anon_mmap_check, anon_mmap_reserve, anon_mmap_release, anon_mmap_commit, _gst_osmem_free },
+#endif
   { NULL, NULL, NULL, NULL, NULL }
 };
 
@@ -195,6 +202,7 @@
 
 static char *baseaddr;
 
+#ifndef __FreeBSD__
 PTR
 anon_mmap_reserve (PTR address, size_t size)
 {
@@ -220,6 +228,7 @@
   if ((char *) baseaddr == (char *) base + size)
     baseaddr = base;
 }
+#endif
 
 PTR
 anon_mmap_commit (PTR base, size_t size)
@@ -231,6 +240,7 @@
   return UNCOMMON (result == MAP_FAILED) ? NULL : result;
 }
 
+#ifndef __FreeBSD__
 /* This is hairy and a hack.  We have to find a place for our heaps...  */
 
 /* This signal handler is used if it is the only means to decide if
@@ -360,3 +370,4 @@
       return (true);
     }
 }
+#endif
