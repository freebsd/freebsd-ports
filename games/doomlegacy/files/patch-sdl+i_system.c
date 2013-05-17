--- sdl/i_system.c.orig
+++ sdl/i_system.c
@@ -84,10 +84,7 @@
 #  include <sys/mount.h>
 /*For meminfo*/
 #  include <sys/types.h>
-#  include <kvm.h>
-#  include <nlist.h>
-#  include <sys/vmmeter.h>
-#  include <fcntl.h>
+#  include <sys/sysctl.h>
 # endif
 #endif
 
@@ -516,6 +513,8 @@ void I_SysInit()
 
   // Enable unicode key conversion
   SDL_EnableUNICODE(1);
+  // Enable key auto repeat
+  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
 
   // Initialize the joystick subsystem.
   I_JoystickInit();
@@ -906,33 +905,19 @@ uint64_t I_GetFreeMem(uint64_t *total)
   // LINUX covers all the unix-type OS's.
 
 #ifdef FREEBSD
-    struct  vmmeter sum;
-    kvm_t *kd;
-    struct nlist namelist[]= {
-#define X_SUM   0
-	{"_cnt"},
-	{ NULL }
-    };
-    if ((kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "kvm_open")) == NULL)
+    unsigned page_count, free_count, pagesize;
+    size_t len = sizeof(unsigned);
+    if (sysctlbyname("vm.stats.vm.v_page_count", &page_count, &len, NULL, 0))
       goto guess;
-
-    if (kvm_nlist(kd, namelist) != 0)
-    {
-	kvm_close (kd);
-	goto guess;
-    }
-    if (kvm_read(kd,namelist[X_SUM].n_value ,&sum, sizeof(sum)) != sizeof(sum))
-    {
-	kvm_close (kd);
-	goto guess;
-    }
-    kvm_close (kd);
-
-    *total = sum.v_page_count * sum.v_page_size;
-    return sum.v_free_count * sum.v_page_size;
+    if (sysctlbyname("vm.stats.vm.v_free_count", &free_count, &len, NULL, 0))
+      goto guess;
+    if (sysctlbyname("hw.pagesize", &pagesize, &len, NULL, 0))
+      goto guess;
+    *total = (uint64_t)page_count * pagesize;
+    return (uint64_t)free_count * pagesize;
 #elif defined(SOLARIS)
     goto guess;
-#else
+#endif
     // Actual Linux
 
 #define MEMINFO_FILE "/proc/meminfo"
@@ -970,7 +955,6 @@ uint64_t I_GetFreeMem(uint64_t *total)
   // make a conservative guess
   *total = 32 << 20;
   return   32 << 20;
-#endif // Unix flavors
 #elif defined(WIN32)
   // windows
 #if defined(WIN_LARGE_MEM) && defined( _WIN32_WINNT ) && (_WIN32_WINNT >= 0x0500)
