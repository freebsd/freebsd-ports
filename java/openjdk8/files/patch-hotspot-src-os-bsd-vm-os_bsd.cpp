--- hotspot/src/os/bsd/vm/os_bsd.cpp
+++ hotspot/src/os/bsd/vm/os_bsd.cpp
@@ -441,7 +441,7 @@
         ld_library_path = (char *) malloc(sizeof(REG_DIR) + sizeof("/lib/") +
             strlen(cpu_arch) + sizeof(DEFAULT_LIBPATH));
 #ifdef __FreeBSD__
-        sprintf(ld_library_path, DEFAULT_LIBPATH ":/usr/local/lib");
+        sprintf(ld_library_path, DEFAULT_LIBPATH ":%%LOCALBASE%%/lib");
 #else
         sprintf(ld_library_path, REG_DIR "/lib/%s:" DEFAULT_LIBPATH, cpu_arch);
 #endif
