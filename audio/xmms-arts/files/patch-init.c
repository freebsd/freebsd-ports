--- init.c.orig	Fri Sep  1 10:35:03 2000
+++ init.c	Thu Feb  5 02:53:58 2004
@@ -20,6 +20,7 @@
  */
 
 #include "artsout.h"
+#include <dlfcn.h>
 
 aRtsConfig arts_cfg;
 
@@ -39,4 +40,14 @@
 		xmms_cfg_read_int(cfgfile, "aRts", "prebuffer", &arts_cfg.prebuffer);
 		xmms_cfg_free(cfgfile);
 	}
+
+	/*
+	 * This is a hack to prevent unloading of libstdc++
+	 * (required by arts libraries) in arts_free() but before
+	 * this thread is terminated. libstdc++ registers thread cleanup
+	 * handler and xmms crashes when this cleanup function is called
+	 * on thread termination.
+	 */
+	if (dlopen("libstdc++.so", RTLD_NOW | RTLD_GLOBAL) == NULL)
+		fprintf(stderr, "Failed to preload libstdc++.so\n");
 }
