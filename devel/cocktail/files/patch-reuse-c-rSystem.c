--- ../../work/cocktail-9309//./reuse/c/rSystem.c	Tue Feb 15 14:26:43 1994
+++ ./reuse/c/rSystem.c	Wed Mar 31 22:35:06 2004
@@ -17,9 +17,9 @@
 # include "rSystem.h"
 
 # ifdef m68000
-# define hz 50
+# define HZ 50
 # else
-# define hz 60
+# define HZ 60
 # endif
 
 # ifndef UNIX
@@ -156,7 +156,7 @@
 # else
    struct tms	buffer;
    (void) times (& buffer);
-   return (buffer.tms_utime + buffer.tms_stime) * 1000 / hz;
+   return (buffer.tms_utime + buffer.tms_stime) * 1000 / HZ;
 # endif
 }
 
