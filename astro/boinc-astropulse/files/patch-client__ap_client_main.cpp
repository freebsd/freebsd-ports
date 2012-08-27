--- ap_client_main.cpp.orig	2009-04-01 02:11:24.000000000 +0200
+++ ap_client_main.cpp	2012-06-23 00:27:10.000000000 +0200
@@ -19,6 +19,8 @@
 #include "ap_config.h"
 #ifdef _WIN32
 #include "boinc_win.h"
+#elif !defined(__EMX__)
+#include <sys/stat.h>
 #endif
 
 #ifdef HAVE_UNISTD_H
@@ -37,6 +39,7 @@
 #include "boinc_api.h"
 #include "util.h"
 #include "str_util.h"
+#include "shmem.h"
 
 #include "astropulse.h"
 #include "diagnostics.h"
@@ -276,6 +279,56 @@
 
 APP_INIT_DATA app_init_data;
 
+#ifndef BOINC_APP_GRAPHICS
+/* copy some code from boinc-client */
+
+#ifdef __EMX__
+static key_t get_shmem_name(const char* prog_name) {
+    char cwd[256], path[256];
+    boinc_getcwd(cwd);
+    sprintf(path, "%s/init_data.xml", cwd);
+    return ftok(path, 2);
+}
+#else
+// Unix/Linux/Mac applications always use mmap() for gfx communication
+//
+static void get_shmem_name(const char* prog_name, char* shmem_name) {
+    APP_INIT_DATA aid;
+    int retval = boinc_get_init_data(aid);
+    if (retval) aid.slot = 0;
+    sprintf(shmem_name, "boinc_%s_%d", prog_name, aid.slot);
+}
+#endif
+
+void* boinc_graphics_make_shmem(const char* prog_name, int size) {
+#ifdef _WIN32
+    HANDLE shmem_handle;
+    char shmem_name[256];
+    void* p;
+    get_shmem_name(prog_name, shmem_name);
+    shmem_handle = create_shmem(shmem_name, size, &p);
+    if (shmem_handle == NULL) return 0;
+    return p;
+#else
+    void* p;
+#ifdef __EMX__
+    key_t key = get_shmem_name(prog_name);
+    int retval = create_shmem(key, size, 0, &p);
+#else
+    // V6 Unix/Linux/Mac applications always use mmap() shared memory for graphics communication
+    char shmem_name[256];
+    get_shmem_name(prog_name, shmem_name);
+    int retval = create_shmem_mmap(shmem_name, size, &p);
+    // Graphics app may be run by a different user & group than worker app
+    // Although create_shmem passed 0666 to open(), it was modified by umask
+    if (retval == 0) chmod(shmem_name, 0666);
+#endif
+    if (retval) return 0;
+    return p;
+#endif
+}
+#endif /* !BOINC_APP_GRAPHICS */
+
 /* Main Program */
 int main(int argc, char *argv[]) {
 
@@ -315,7 +368,30 @@
   boinc_get_init_data(app_init_data);
   // We've moved the state variable into the graphics shmem segment,
   // so we always need to initialize graphics.
+#ifdef BOINC_APP_GRAPHICS
   ap_graphics_init(app_init_data);  
+#else /* BOINC_APP_GRAPHICS */
+   // Checking for blank statefile
+   AP_SHMEM* &ap_shmem=Astropulse::client.ap_shmem;
+    // ap_shmem is defined extern in ap_gfx_main.h XXX
+    ap_shmem = (AP_SHMEM *)(boinc_graphics_make_shmem("astropulse", sizeof(AP_SHMEM)));//XXX
+    if (!ap_shmem) {
+        fprintf(stderr, "boinc_graphics_make_shmem failed: %d\n", errno);
+        exit(ERR_SHMEM_NAME);
+    }
+
+    // initialize ap_shmem with placement new.
+	// VC++ doesn't support placement new in debug mode!?!?!  What the hell?
+#if !defined(_DEBUG) || !defined(_MSC_VER)
+    ap_shmem = new (ap_shmem) AP_SHMEM();
+#else
+    // VC++ doesn't support placement new in debug mode!?!?!  What the hell?
+	// Fortunately AP_SHMEM doesn't contain any self-referential pointers.
+    AP_SHMEM *tmp=new AP_SHMEM();
+	memcpy(ap_shmem,tmp,sizeof(AP_SHMEM));
+	delete tmp;
+#endif
+#endif /* BOINC_APP_GRAPHICS no case */
 
 
   /* Possible arguments:
