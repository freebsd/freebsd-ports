--- coregrind/vg_preloaded.c.orig	2023-09-19 20:30:09.413386000 +0200
+++ coregrind/vg_preloaded.c	2023-09-19 20:32:14.366333000 +0200
@@ -228,7 +228,27 @@
 
 #elif defined(VGO_freebsd)
 
-// nothing specific currently
+#if (FREEBSD_VERS >= FREEBSD_14)
+
+void * VG_NOTIFY_ON_LOAD(ifunc_wrapper) (void);
+void * VG_NOTIFY_ON_LOAD(ifunc_wrapper) (void)
+{
+    OrigFn fn;
+    Addr result = 0;
+    Addr fnentry;
+
+    /* Call the original indirect function and get it's result */
+    VALGRIND_GET_ORIG_FN(fn);
+    CALL_FN_W_v(result, fn);
+
+    fnentry = result;
+
+    VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__ADD_IFUNC_TARGET,
+                                    fn.nraddr, fnentry, 0, 0, 0);
+    return (void*)result;
+}
+
+#endif
 
 #elif defined(VGO_solaris)
 
