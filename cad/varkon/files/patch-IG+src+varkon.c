--- IG/src/varkon.c	2008/02/29 11:24:13	93
+++ IG/src/varkon.c	2008/04/29 06:04:18	100
@@ -205,29 +205,32 @@
 /********************************************************/
 
 #ifdef UNIX
-        int main(ac,av)
-        int   ac;     /* arg. count */
-        char *av[];   /* argument vector */
+        int   main(
+        int   ac,     /* arg. count */
+        char *av[])   /* argument vector */
 #endif
 
 #ifdef WIN32
         int WINAPI WinMain(
-        HINSTANCE inst,
-        HINSTANCE prev_instr,
-        LPSTR     args,
-        int       wmode)
+        HINSTANCE  inst,
+        HINSTANCE  prev_instr,
+        LPSTR      args,
+        int        wmode)
 #endif
 
 /*      Main program for xvarkon/VARKON.EXE. Inits the
  *      graphical environment, processes command line
  *      parameters and inits various sub packages like
  *      memory allocation, geometry, debug etc. then
- *      calls the main loop.
+ *      calls the main loop. A logfile is created during
+ *      startup and deleted when the system exits.
  *
  *      (C)microform ab 31/10/95 J. Kjellander
  *
  *      2007-01-05 Major rewrite, J.Kjellander
  *      2007-11-18 2.0, J.Kjellander
+ *      2008-04-28 Logfile to VARKON_TMP, J.Kjellander
+ *      2008-04-28 Default jobdir = $HOME, J.Kjellander
  *
  ******************************************************!*/
 
@@ -255,10 +258,17 @@
      exit(-1);
      }
 /*
-***Open startup_logfile.
+***Open startup_logfile Varkon.LOG. Use VARKON_TMP
+***which should be writable for all users.
 */
-   strcpy(lfname,getenv("VARKON_ROOT"));
-   strcat(lfname,"/varkon.LOG");
+   if ( getenv("VARKON_TMP") == NULL )
+     {
+     printf("VARKON_TMP is not defined !\n");
+     exit(-1);
+     }
+
+   strncpy(lfname,getenv("VARKON_TMP"),V3PTHLEN);
+   strncat(lfname,"/Varkon.LOG",V3STRLEN);
    if ( (startup_logfile=fopen(lfname,"w")) == NULL )
      {
      printf("Can't open startup_logfile %s\n",lfname);
@@ -391,11 +401,11 @@
    fflush(startup_logfile);
 /*
 ***job directory. If a job directory was not specified
-***on the command line use VARKON_ROOT.
+***on the command line use $HOME.
 */
    if ( jobdir[0] == '\0' )
      {
-     strcpy(jobdir,getenv("VARKON_ROOT"));
+     strcpy(jobdir,getenv("HOME"));
      }
 
    if ( jobdir[strlen(jobdir)-1] != '/' ) strcat(jobdir,"/");
@@ -504,8 +514,8 @@
        }
      WPalla("",2);
      WPalla("Something is wrong with your Varkon installation.",1);
-     WPalla("This startup log is stored as varkon.LOG on your Varkon",1);
-     WPalla("installation root directory and can be a good help to",1);
+     WPalla("This startup log is stored as Varkon.LOG in your Varkon",1);
+     WPalla("temp directory and can be a good help to",1);
      WPalla("understand what the problem is.",2);
      WPalla("If you need help, you can contact the Varkon developers",1);
      WPalla("through the development site:",2);
@@ -530,7 +540,7 @@
   }
 
 /********************************************************/
-/*!******************************************************/
+/********************************************************/
 
  static short process_cmdline(
         int   argc,
@@ -741,7 +751,7 @@
 }
 
 /********************************************************/
-/*!******************************************************/
+/********************************************************/
 
         short IGcheck_jobname(char jobnam[])
 
