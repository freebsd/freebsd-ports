--- xmain.c.orig	Fri Jul 14 17:35:38 2006
+++ xmain.c	Fri Jul 28 12:45:20 2006
@@ -39,7 +39,7 @@
 float total;
 }PIXINFO;
 
-
+int saved_euid=-1;
  
 int main(int argc, char **argv)
 {
@@ -59,6 +59,8 @@
 XTextProperty window_title_property;
 unsigned short int *ipalette;
 XColor xco;
+saved_euid=geteuid();
+setuid(getuid());	/* XXX drop perms! */
 if(UNINIT_MEMDATA != 0)
   {
   memptr=(void*)(&uninit_mem_begin);
