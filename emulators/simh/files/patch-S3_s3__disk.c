--- S3/s3_disk.c.orig	2016-12-01 22:43:43 UTC
+++ S3/s3_disk.c
@@ -298,7 +298,7 @@ int32 dsk (int32 disk, int32 op, int32 m
                                     addr++;
                                 }
 
-                                if ((sect == 55) ) {    /* HJS MODS */
+                                if (sect == 55) {    /* HJS MODS */
                                     S = sect;
                                     N = nsects - i - 2;
                                     if (N > -1) diskerr[disk] |= 0x0020; /* end of cyl. */
@@ -349,7 +349,7 @@ int32 dsk (int32 disk, int32 op, int32 m
                                     diskerr[disk] |= 0x0800;
                                     break;
                                 }   
-                                if ((sect == 55) ) {    /* HJS MODS */
+                                if (sect == 55) {    /* HJS MODS */
                                     S = sect;
                                     N = nsects - i - 2;
                                     if (N > -1) diskerr[disk] |= 0x0020; /* end of cyl. */
@@ -392,7 +392,7 @@ int32 dsk (int32 disk, int32 op, int32 m
                                     diskerr[disk] |= 0x0400;
                                     break;
                                 }   
-                                if ((sect == 55) ) {    /* HJS MODS */
+                                if (sect == 55) {    /* HJS MODS */
                                     S = sect;
                                     N = nsects - i - 2;
                                     if (N > -1) diskerr[disk] |= 0x0020; /* end of cyl. */
@@ -434,7 +434,7 @@ int32 dsk (int32 disk, int32 op, int32 m
                                     diskerr[disk] |= 0x0400;
                                     break;
                                 }   
-                                if ((sect == 55) ) {
+                                if (sect == 55) {
                                     S = sect;
                                     N = nsects - i - 2;
                                     if (N > 0) diskerr[disk] |= 0x0020;
@@ -486,7 +486,7 @@ int32 dsk (int32 disk, int32 op, int32 m
                             found[disk] = 1;
                         if (res == data)
                             break;
-                        if ((sect == 55) ) {            /* HJS MODS */
+                        if (sect == 55) {               /* HJS MODS */
                             S = sect;
                             N = nsects - i - 2;
                             if (N > -1) diskerr[disk] |= 0x0020; /* end of cyl. */
