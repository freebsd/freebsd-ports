--- ../../work/cocktail-9309//./reuse/m2c/rSystem.c	Tue Feb 15 14:26:46 1994
+++ ./reuse/m2c/rSystem.c	Wed Mar 31 22:35:06 2004
@@ -22,9 +22,9 @@
 # define tFile int
 
 # ifdef m68000
-# define hz 50
+# define HZ 50
 # else
-# define hz 60
+# define HZ 60
 # endif
 
 /* binary IO */
@@ -229,7 +229,7 @@
 # else
    struct tms	buffer;
    (void) times (& buffer);
-   return (buffer.tms_utime + buffer.tms_stime) * 1000 / hz;
+   return (buffer.tms_utime + buffer.tms_stime) * 1000 / HZ;
 # endif
 }
 
