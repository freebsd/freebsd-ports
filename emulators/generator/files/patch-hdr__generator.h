--- hdr/generator.h.orig	Mon May  5 03:50:43 2003
+++ hdr/generator.h	Sun Nov 23 04:46:22 2003
@@ -13,6 +13,10 @@
 void gen_softreset(void);
 void gen_loadmemrom(const char *rom, int romlen);
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #if defined(linux)
   #include <byteswap.h>
   #define SWAP16(x) bswap_16((x))
@@ -21,6 +25,10 @@
   #include <machine/endian.h>
   #define SWAP16(x) bswap_16((x))
   #define SWAP32(x) bswap_32((x))
+#elif defined(__FreeBSD__) && __FreeBSD_version >= 470000
+  #include <sys/endian.h>
+  #define SWAP16(x) (be16toh(x))
+  #define SWAP32(x) (be32toh(x))
 #else
   #define SWAP16(y) (( ((y)>>8) & 0x00ff) | (( ((y)<<8) & 0xff00)))
   #define SWAP32(y) (( ((y)>>24) & 0x000000ff) | \
@@ -221,11 +229,11 @@
 #  define LOG_DEBUG3(x)   /* ui_log_debug3 ## x */
 #  define LOG_DEBUG2(x)   /* ui_log_debug2 ## x */
 #  define LOG_DEBUG1(x)   /* ui_log_debug1 ## x */
-#  define LOG_USER(x)     ui_log_user ## x
-#  define LOG_VERBOSE(x)  ui_log_verbose ## x
-#  define LOG_NORMAL(x)   ui_log_normal ## x
-#  define LOG_CRITICAL(x) ui_log_critical ## x
-#  define LOG_REQUEST(x)  ui_log_request ## x
+#  define LOG_USER(x)     ui_log_user x
+#  define LOG_VERBOSE(x)  ui_log_verbose x
+#  define LOG_NORMAL(x)   ui_log_normal x
+#  define LOG_CRITICAL(x) ui_log_critical x
+#  define LOG_REQUEST(x)  ui_log_request x
 #endif
 
 typedef struct {
