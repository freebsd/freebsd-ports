--- ltsmaster/runtime/druntime/src/core/sys/freebsd/sys/event.d	2018-08-21 18:55:47.000000000 +0000
+++ ltsmaster/runtime/druntime/src/core/sys/freebsd/sys/event.d	2019-03-06 04:06:16.750660000 +0000
@@ -46,8 +46,9 @@
     short       filter; /* filter for event */
     ushort       flags;
     uint        fflags;
-    intptr_t      data;
-    void        *udata; /* opaque user data identifier */
+    long      data;
+    void*        udata; /* opaque user data identifier */
+    ulong[4]        ext;
 }
 
 enum
