--- xmain.c.orig	Tue Nov  7 13:45:33 2006
+++ xmain.c	Fri Nov 24 18:02:31 2006
@@ -40,7 +40,7 @@
 float total;
 }PIXINFO;
 
-
+int saved_euid=-1;
  
 int main(int argc, char **argv)
 {
@@ -60,6 +60,8 @@
 XTextProperty window_title_property;
 unsigned short int *ipalette;
 XColor xco;
+saved_euid=geteuid();
+setuid(getuid());	/* XXX drop perms! */
 if(UNINIT_MEMDATA != 0)
   {
   memptr=(void*)(&uninit_mem_begin);
