--- ld/catimage.c.orig	2011-09-28 14:37:07.000000000 +0800
+++ ld/catimage.c	2011-09-28 14:37:59.000000000 +0800
@@ -30,6 +30,7 @@
 unsigned long text_offt[10];	/* Locations to patch (0=don't) */
 unsigned long data_offt[10];
 
+void patch_bin(long, int);
 char * input_file = "";
 FILE * ofd;
 FILE * ifd = 0;
@@ -139,6 +140,7 @@ long out_offset, in_offset, length;
    }
 }
 
+void
 patch_bin(file_off, value)
 long file_off;
 int value;
