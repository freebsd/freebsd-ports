--- xmain.c.orig	Tue Sep  4 18:14:34 2007
+++ xmain.c	Thu Sep 27 21:09:15 2007
@@ -39,6 +39,7 @@
 float total;
 }PIXINFO;
 
+int saved_euid=-1;
 
  
 int main(int argc, char **argv)
@@ -58,6 +59,8 @@
 XTextProperty window_title_property;
 unsigned short int *ipalette;
 XColor xco;
+saved_euid=geteuid();
+setuid(getuid());      /* XXX drop perms! */
 for(i=0; i<MAX_LIRSEM; i++)lirsem_flag[i]=0;
 XInitThreads();
 if(DUMPFILE)
