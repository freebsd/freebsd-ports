--- polyp/util.c.orig	Tue Oct 26 20:10:13 2004
+++ polyp/util.c	Sat Oct 30 01:22:54 2004
@@ -209,7 +209,13 @@
         if (!(p = getenv("LOGNAME")))
             if (!(p = getenv("USERNAME"))) {
                 
+#ifdef HAVE_GETPWUID_R
                 if (getpwuid_r(getuid(), &pw, buf, sizeof(buf), &r) != 0 || !r) {
+#else
+		/* XXX Not thread-safe, but needed on OSes (e.g. FreeBSD 4.X)
+		 * that do not support getpwuid_r. */
+		if ((r = getpwuid(getuid())) == NULL) {
+#endif
                     snprintf(s, l, "%lu", (unsigned long) getuid());
                     return s;
                 }
@@ -445,11 +451,17 @@
 
 static int is_group(gid_t gid, const char *name) {
     struct group group, *result = NULL;
-    long n = sysconf(_SC_GETGR_R_SIZE_MAX);
+    long n;
     void *data;
     int r = -1;
-    
-    assert(n > 0);
+
+#ifdef HAVE_GETGRGID_R
+#ifdef _SC_GETGR_R_SIZE_MAX
+    n = sysconf(_SC_GETGR_R_SIZE_MAX);
+#else
+    n = -1;
+#endif
+    if (n < 0) n = 512;
     data = pa_xmalloc(n);
 
     if (getgrgid_r(gid, &group, data, n, &result) < 0 || !result) {
@@ -462,6 +474,18 @@
     
 finish:
     pa_xfree(data);
+#else
+    /* XXX Not thread-safe, but needed on OSes (e.g. FreeBSD 4.X) that do not
+     * support getgrgid_r. */
+    if ((result = getgrgid(gid)) == NULL) {
+	pa_log(__FILE__ ": getgrgid(%u) failed: %s\n", gid, strerror(errno));
+	goto finish;
+    }
+
+    r = strcmp(name, result->gr_name) == 0;
+
+finish:
+#endif
     
     return r;
 }
