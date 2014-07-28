--- capture.h.orig	Thu Jul 27 02:15:05 2000
+++ capture.h	Thu Oct 16 10:58:38 2003
@@ -16,20 +16,37 @@
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 #define _XOPEN_SOURCE 500
+#define __BSD_VISIBLE 1
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
+#ifdef LINUX
 #include <sys/io.h>
+#endif
 #include <sys/mman.h>
 #include <dirent.h>
 #include <ctype.h>
+#ifdef LINUX
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <signal.h>
+#ifdef HAVE_GETOPT_H
 #include <getopt.h>
+#endif
+#ifdef LINUX
 #include <linux/pci.h>
+#else
+#include <sys/pciio.h>
+#include "pci.h" /*This is taken from Linux kernel*/
+#include <osreldate.h>
+#if __FreeBSD_version <= 500041
+#define O_SYNC O_FSYNC
+#endif
+#include <sys/stat.h>
+#endif
 #include <sys/time.h>
 #include "mchip.h"
 
