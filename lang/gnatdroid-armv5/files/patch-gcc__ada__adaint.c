--- gcc/ada/adaint.c.orig	2011-04-16 05:34:37.000000000 -0500
+++ gcc/ada/adaint.c	2011-08-19 23:28:10.000000000 -0500
@@ -1201,6 +1201,47 @@
     free (pname);
   }
 
+#elif defined (__ANDROID__)
+
+  /* 
+   * ext2 /ext3/ext4/fat16/fat32 have no path limits 
+   * /data/local/tmp normally requires rooted devices, if it even exists
+   * /sdcard is the standard location for external storage.  Nativeactivity
+   * manifest needs to authorize its use, otherwise it might not have the
+   * proper permissions.
+   */
+
+  int testfd;
+  char *datadir = getenv ("ANDROID_DATA");
+
+  if (datadir == NULL)
+    strcpy (tmp_filename, "/data/local/tmp/gnat-XXXXXX");
+  else 
+    sprintf (tmp_filename, "%s/local/tmp/gnat-XXXXXX", datadir);
+
+  testfd = mkstemp (tmp_filename);  
+  if (testfd != -1)
+    {
+      close (testfd);
+      return;
+    }
+
+  char *sdcard = getenv ("EXTERNAL_STORAGE");
+
+  if (sdcard == NULL)
+    strcpy (tmp_filename, "/sdcard/gnat-XXXXXX");      
+  else
+    sprintf (tmp_filename, "%s/gnat-XXXXXX", sdcard);
+    
+  testfd = mkstemp (tmp_filename);  
+  if (testfd != -1)
+    {
+      close (testfd);
+      return;
+    }
+       
+  tmpnam (tmp_filename);
+
 #elif defined (linux) || defined (__FreeBSD__) || defined (__NetBSD__) \
   || defined (__DragonFly__) \
   || defined (__OpenBSD__) || defined(__GLIBC__)
