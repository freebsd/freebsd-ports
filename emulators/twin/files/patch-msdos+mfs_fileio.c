--- msdos/mfs_fileio.c.orig	Sat Aug  2 16:02:08 2003
+++ msdos/mfs_fileio.c	Sat Aug  2 16:03:20 2003
@@ -213,8 +213,7 @@
            (strcmp(filename, xdos.fileio[slot].filename) == 0) ) {
           /* Get the handle */
           if ((handle = gethandle()) < 0) {
-              ERRSTR((LF_ERROR,"mfs_delete cannot get handle for file %s %d
- %d\n", filename, errno, slot));
+              ERRSTR((LF_ERROR,"mfs_delete cannot get handle for file %s %d %d\n", filename, errno, slot));
               return MAKELONG(NO_HANDLES & 0xffff,0xffff);
           }
           xdos.fileptr[handle] = &xdos.fileio[slot];
@@ -232,8 +231,7 @@
      	       return unlink(filename);
               }
           }
-          else ERRSTR((LF_ERROR,"mfs_delete : invalid handle %d for file
-%s\n",handle, filename));
+          else ERRSTR((LF_ERROR,"mfs_delete : invalid handle %d for file %s\n",handle, filename));
          }
      }
      /* At this point, either the file was fclosed by us, or it was
