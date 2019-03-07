--- runtime/druntime/src/core/sys/freebsd/sys/event.d	2019-02-15 17:20:40.000000000 +0000
+++ runtime/druntime/src/core/sys/freebsd/sys/event.d	2019-03-05 17:57:03.552667000 +0000
@@ -49,8 +49,9 @@
     short       filter; /* filter for event */
     ushort       flags;
     uint        fflags;
-    intptr_t      data;
-    void        *udata; /* opaque user data identifier */
+    long          data;
+    void*        udata; /* opaque user data identifier */
+    ulong[4]        ext;
 }
 
 enum
