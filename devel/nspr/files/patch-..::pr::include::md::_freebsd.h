--- ../pr/include/md/_freebsd.h	Thu Jan 16 08:16:27 2003
+++ ../pr/include/md/_freebsd.h	Sat Dec 13 13:22:20 2003
@@ -40,14 +40,21 @@
 #if __FreeBSD__ >= 2
 #include <osreldate.h>  /* for __FreeBSD_version */
 #endif
+#include <sys/param.h>
 #include <sys/syscall.h>
 
 #define PR_LINKER_ARCH	"freebsd"
 #define _PR_SI_SYSNAME  "FREEBSD"
 #if defined(__i386__)
 #define _PR_SI_ARCHITECTURE "x86"
-#elif defined(__alpha)
+#elif defined(__alpha__)
 #define _PR_SI_ARCHITECTURE "alpha"
+#elif defined(__sparc64__)
+#define _PR_SI_ARCHITECTURE "sparc"
+#elif defined(__ia64__)
+#define _PR_SI_ARCHITECTURE "ia64"
+#elif defined(__amd64__)
+#define _PR_SI_ARCHITECTURE "amd64"
 #else
 #error "Unknown CPU architecture"
 #endif
