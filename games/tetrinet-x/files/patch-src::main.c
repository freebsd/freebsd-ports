--- src/main.c.orig	Thu Dec 24 06:24:50 1998
+++ src/main.c	Thu Jun 17 10:06:39 2004
@@ -319,12 +319,10 @@
 
 /* lvprintf( priority, same as printf ) - Logs to the log IF priority is smaller */
 /*                                        or equal to game.verbose */
-void lvprintf(va_alist)
-va_dcl
+void lvprintf(int priority, char *format, ...)
 { /* No bounds checking. Be very careful what you log */
-  char *format; va_list va; static char SBUF2[768];int priority;
-  va_start(va);
-  priority=va_arg(va,int);format=va_arg(va,char *);
+  va_list va; static char SBUF2[768];
+  va_start(va, format);
   vsprintf(SBUF2,format,va);
   if (strlen(SBUF2)>512)
     {
@@ -338,15 +336,14 @@
 }
 
 /* lprintf( same as printf ) - Logs to the log. */
-void lprintf(va_alist)
-va_dcl
+void lprintf(char *format, ...)
 { /* No bounds checking. Be very careful what you log */
-  char *format; va_list va; static char SBUF2[768];
+  va_list va; static char SBUF2[768];
   FILE *file_out;
   char *mytime;
   char *P;
   time_t cur_time;
-  va_start(va);
+  va_start(va, format);
   format=va_arg(va,char *);
   vsprintf(SBUF2,format,va);
   if (strlen(SBUF2)>512)
@@ -2462,7 +2459,7 @@
     /* Winlist - Returns Winlist */
     if (!strcasecmp(buf,"getwinlist"))
       {
-        lvprintf("%s: GetWinlist request\n",n->host);
+        lprintf("%s: GetWinlist request\n",n->host);
         for(i=0;i<MAXWINLIST;i++)
           {
             if(winlist[i].inuse)
@@ -3071,4 +3068,4 @@
           
         
       }
-  }
\ No newline at end of file
+  }
