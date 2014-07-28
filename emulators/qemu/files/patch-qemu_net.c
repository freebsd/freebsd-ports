Index: qemu/net.c
@@ -76,6 +76,11 @@
 #endif
 #endif
 #endif
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/module.h>
+#include <sys/linker.h>
+#endif
 
 #if defined(CONFIG_SLIRP)
 #include "libslirp.h"
@@ -3407,6 +3410,34 @@
 
 #endif /* CONFIG_SLIRP */
 
+#ifdef __FreeBSD__
+#define LOAD_QUIETLY	1
+#define LOAD_VERBOSLY	2
+
+static int
+loadmodules(int how, const char *module, ...)
+{
+  int loaded = 0;
+  va_list ap;
+
+  va_start(ap, module);
+#ifndef NO_MODULES
+  while (module != NULL) {
+    if (modfind(module) == -1) {
+      if (kldload(module) == -1) {
+        if (how == LOAD_VERBOSLY)
+          fprintf(stderr, "%s: Cannot load module\n", module);
+      } else
+        loaded++;
+    }
+    module = va_arg(ap, const char *);
+  }
+  va_end(ap);
+#endif
+  return loaded;
+}
+#endif
+
 #if !defined(_WIN32)
 
 typedef struct TAPState {
@@ -3470,11 +3501,59 @@
     char *dev;
     struct stat s;
 
+#ifdef __FreeBSD__
+    int i, kldtried = 0, enoentcount = 0, err = 0;
+    char dname[100];
+#ifdef USE_DEVTAP
+    /*
+     * 5.x has /dev/tap, but that seems to just blindly increase its
+     * couter on every open() for some people(??), i.e. on every qemu run.
+     */
+    i = -1;
+#else
+    i = 0;
+#endif
+    for (; i < 10; i++) {
+        if (*ifname)
+            snprintf(dname, sizeof dname, "/dev/%s", ifname);
+        else if (i == -1)
+            strcpy(dname, "/dev/tap");
+        else
+            snprintf(dname, sizeof dname, "%s%d",
+        	     "/dev/tap", i);
+        TFR(fd = open(dname, O_RDWR));
+        if (fd >= 0)
+            break;
+        else if (errno == ENXIO || errno == ENOENT) {
+            if (i == 0 && !kldtried++) {
+                /*
+                 * Attempt to load the tunnel interface KLD if it isn't loaded
+                 * already.
+                 */
+                if (loadmodules(LOAD_VERBOSLY, "if_tap", NULL))
+                    i = -1;
+                continue;
+            }
+            if (errno != ENOENT || ++enoentcount > 3) {
+                err = errno;
+                break;
+            }
+        } else
+            err = errno;
+        if (*ifname)
+            break;
+    }
+    if (fd < 0) {
+        fprintf(stderr, "warning: could not open %s (%s): no virtual network emulation\n", dname, strerror(err));
+        return -1;
+    }
+#else
     TFR(fd = open("/dev/tap", O_RDWR));
     if (fd < 0) {
-        fprintf(stderr, "warning: could not open /dev/tap: no virtual network emulation\n");
+        fprintf(stderr, "warning: could not open /dev/tap (%s): no virtual network emulation\n", strerror(errno));
         return -1;
     }
+#endif
 
     fstat(fd, &s);
     dev = devname(s.st_rdev, S_IFCHR);
