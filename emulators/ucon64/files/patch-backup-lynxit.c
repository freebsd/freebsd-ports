--- backup/lynxit.c.orig 2013-02-24 18:40:11.525942823 -0800
+++ backup/lynxit.c	2013-02-24 18:46:25.101942911 -0800
@@ -561,7 +561,7 @@
       return FALSE;
     }
 
-  if (strcmp (header.magic, "LYNX") != 0)
+  if (memcmp (header.magic, "LYNX", sizeof(header.magic)) != 0)
     {
       MESSAGE (("ERROR    : %s is not a lynx image\n", filename));
       fclose (fp);
@@ -682,7 +682,7 @@
 #endif
 
   memset (&header, 0, sizeof (st_lnx_header_t));
-  strcpy (header.magic, MAGIC_STRING);
+  memcpy (header.magic, MAGIC_STRING, sizeof(header.magic));
   strcpy (header.cartname, cartname);
   strcpy (header.manufname, manufname);
   header.page_size_bank0 = cart_analyse (BANK0);
