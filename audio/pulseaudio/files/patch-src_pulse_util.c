--- src/pulse/util.c.orig	2008-01-01 17:29:31.000000000 -0500
+++ src/pulse/util.c	2008-01-01 17:29:00.000000000 -0500
@@ -184,6 +184,17 @@ char *pa_get_binary_name(char *s, size_t
     }
 
 #endif
+#ifdef __FreeBSD__
+    {
+        char *rp;
+
+	if ((rp = pa_readlink("/proc/curproc/file"))) {
+	    pa_strlcpy(s, pa_path_get_filename(rp), l);
+	    pa_xfree(rp);
+	    return s;
+	}
+    }
+#endif
 
 #if defined(HAVE_SYS_PRCTL_H) && defined(PR_GET_NAME)
     {
