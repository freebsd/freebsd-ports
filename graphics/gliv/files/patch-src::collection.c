--- src/collection.c.orig	Thu Jul 29 06:40:56 2004
+++ src/collection.c	Thu Aug  5 01:05:38 2004
@@ -77,6 +77,7 @@
  * are '\0' terminated strings representing decimal numbers.
  */
 
+#include <sys/types.h>
 #include <sys/mman.h>           /* mmap(), PROT_READ, MAP_PRIVATE, ... */
 #include <stdio.h>              /* FILE, fopen(), fread(), fwrite(), ... */
 #include <string.h>             /* strlen(), strrchr() */
