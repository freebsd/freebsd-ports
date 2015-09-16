--- hotspot/src/os/bsd/vm/os_bsd.cpp.orig	2014-10-06 17:10:00.000000000 -0400
+++ hotspot/src/os/bsd/vm/os_bsd.cpp	2014-10-08 10:23:14.000000000 -0400
@@ -458,7 +458,7 @@
  *        7: The default directories, normally /lib and /usr/lib.
  */
 #ifndef DEFAULT_LIBPATH
-#define DEFAULT_LIBPATH "/lib:/usr/lib"
+#define DEFAULT_LIBPATH "/lib:/usr/lib:%%LOCALBASE%%/lib"
 #endif
 
 #define EXTENSIONS_DIR  "/lib/ext"
@@ -2947,7 +2947,7 @@
       if (::write(fd, "", 1) == 1) {
         mmap(base, size,
              PROT_READ|PROT_WRITE|PROT_EXEC,
-             MAP_PRIVATE|MAP_FIXED|MAP_NORESERVE, fd, 0);
+             MAP_PRIVATE|MAP_FIXED, fd, 0);
       }
     }
     ::close(fd);
@@ -3196,7 +3196,7 @@
   return ::mprotect(addr, size, PROT_NONE) == 0;
 #else
   uintptr_t res = (uintptr_t) ::mmap(addr, size, PROT_NONE,
-                MAP_PRIVATE|MAP_FIXED|MAP_NORESERVE|MAP_ANONYMOUS, -1, 0);
+                MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0);
   return res  != (uintptr_t) MAP_FAILED;
 #endif
 }
@@ -3223,7 +3223,7 @@
   char * addr;
   int flags;
 
-  flags = MAP_PRIVATE | MAP_NORESERVE | MAP_ANONYMOUS;
+  flags = MAP_PRIVATE | MAP_ANONYMOUS;
   if (fixed) {
     assert((uintptr_t)requested_addr % os::Bsd::page_size() == 0, "unaligned address");
     flags |= MAP_FIXED;
