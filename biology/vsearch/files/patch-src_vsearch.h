--- src/vsearch.h.orig	2023-10-27 12:44:35 UTC
+++ src/vsearch.h
@@ -161,7 +161,6 @@
 #elif __FreeBSD__
 
 #define PROG_OS "freebsd"
-#include <sys/sysinfo.h>
 #include <sys/resource.h>
 #include <sys/endian.h>
 #define bswap_16(x) bswap16(x)
