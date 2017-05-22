--- lib/CL/pocl_binary.c.orig	2017-04-05 14:15:40 UTC
+++ lib/CL/pocl_binary.c
@@ -36,7 +36,7 @@
 #include <libgen.h>
 
 #ifndef __APPLE__
-  #include <endian.h>
+  #include <sys/endian.h>
 #else
   #include <libkern/OSByteOrder.h>
   #define htole16(x) OSSwapHostToLittleInt16(x)
