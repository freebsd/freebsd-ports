--- xmain.c.orig	2009-03-09 17:29:28.000000000 -0400
+++ xmain.c	2009-03-22 15:38:09.000000000 -0400
@@ -29,6 +29,7 @@
 extern Window xwin;
 extern Colormap lir_colormap;
 
+int saved_euid=-1;
 
 typedef struct {
 unsigned short int red;
@@ -54,6 +55,8 @@
 Cursor cross_cursor;
 unsigned short int *ipalette;
 XColor xco;
+saved_euid=geteuid();
+setuid(getuid());      /* XXX drop perms! */
 for(i=0; i<MAX_LIRSEM; i++)lirsem_flag[i]=0;
 XInitThreads();
 if(DUMPFILE)
