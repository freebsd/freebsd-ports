$FreeBSD$

--- ../../j2se/src/solaris/bin/java_md.c	15 Feb 2005 02:06:26 -0000	1.6
+++ ../../j2se/src/solaris/bin/java_md.c	20 Apr 2005 12:08:02 -0000
@@ -906,8 +904,7 @@
     if (execname != NULL)	/* Already determined */
 	return (execname);
 
-/* XXXBSD:  is it right for us ?*/
-#if defined(__sun) || defined(__FreeBSD__)
+#if defined(__sun)
     {
         Dl_info dlinfo;
         if (dladdr((void*)&SetExecname, &dlinfo)) {
@@ -928,12 +925,47 @@
 	    exec_path = strdup(buf);
 	}
     }
+#elif defined(__FreeBSD__)
+    /* Try /proc/curproc/file if exec_path hasn't been found */
+
+    if (exec_path == NULL) {
+	const char* self = "/proc/curproc/file";
+        char buf[PATH_MAX+1];
+        int len = readlink(self, buf, PATH_MAX);
+        if (len >= 0) {
+	    buf[len] = '\0';		/* readlink doesn't nul terminate */
+	    exec_path = strdup(buf);
+	}
+    }
+
+    /*
+     * Try the dladdr(3) method FreeBSD if exec_path hasn't been found.
+     * Requires a recent version of FreeBSD.
+     */
+
+    /*
+    if (exec_path == NULL) {
+        Dl_info dlinfo;
+        if (dladdr((void*)&SetExecname, &dlinfo)) {
+	    char *resolved = (char*)MemAlloc(PATH_MAX+1);
+	    if (resolved != NULL) {
+		exec_path = realpath(dlinfo.dli_fname, resolved);
+		if (exec_path == NULL) {
+		    free(resolved);
+		}
+	    }
+        }
+    }
+    */
+
 #else /* !__sun && !__linux */
     {
         /* Not implemented */
     }
 #endif 
 
+    /* Fall back to examining argv[0] and our path */
+
     if (exec_path == NULL) {
         exec_path = FindExecName(argv[0]);
     }
