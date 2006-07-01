--- xmain.c.orig	Mon Jun 19 22:40:14 2006
+++ xmain.c	Mon Jun 19 23:33:03 2006
@@ -38,7 +38,7 @@
 float total;
 }PIXINFO;
 
-
+int saved_euid=-1;
  
 int main(int argc, char **argv)
 {
@@ -58,6 +58,8 @@
 XTextProperty window_title_property;
 unsigned short int *ipalette;
 XColor xco;
+saved_euid=geteuid();
+setuid(getuid());	/* XXX drop perms! */
 if(UNINIT_MEMDATA != 0)
   {
   memptr=(void*)(&uninit_mem_begin);
