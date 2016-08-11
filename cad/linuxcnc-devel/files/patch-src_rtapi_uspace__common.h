--- src/rtapi/uspace_common.h.orig	2016-06-25 02:19:12 UTC
+++ src/rtapi/uspace_common.h
@@ -85,6 +85,7 @@ int rtapi_shmem_new(int key, int module_
     if(res < 0) perror("shmctl IPC_SET");
   }
 
+#ifdef __linux__
 #ifdef RTAPI
   if(rtapi_is_realtime())
   {
@@ -99,6 +100,7 @@ int rtapi_shmem_new(int key, int module_
           "shared memory segment not locked as requested\n");
   }
 #endif
+#endif
 
   /* and map it into process space */
   shmem->mem = shmat(shmem->id, 0, 0);
@@ -261,7 +263,7 @@ long long rtapi_get_time(void) {
     return ts.tv_sec * 1000000000LL + ts.tv_nsec;
 }
 
-#if defined(__i386) || defined(__amd64)
+#if defined(__linux__) && (defined(__i386) || defined(__amd64))
 #define rdtscll(val) ((val) = __builtin_ia32_rdtsc())
 #else
 #define rdtscll(val) ((val) = rtapi_get_time())
@@ -327,6 +329,7 @@ int rtapi_exit(int module_id)
 int rtapi_is_kernelspace() { return 0; }
 static int _rtapi_is_realtime = -1;
 static int detect_realtime() {
+#ifdef __linux__
     struct utsname u;
     int crit1, crit2 = 0, crit3 = 0;
     FILE *fd;
@@ -346,6 +349,9 @@ static int detect_realtime() {
         crit3 = 1;
 
     return crit1 && crit2 && crit3;
+#else
+    return 0;
+#endif
 }
 
 int rtapi_is_realtime() {
