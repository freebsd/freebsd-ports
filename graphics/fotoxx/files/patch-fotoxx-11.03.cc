--- fotoxx-11.03.cc.orig	2011-02-28 16:04:24.000000000 +0000
+++ fotoxx-11.03.cc	2013-03-30 08:59:16.000000000 +0000
@@ -24,6 +24,13 @@
 #include <tiffio.h>
 #include "zfuncs.h"
 
+#ifdef __FreeBSD__
+      #include <unistd.h> /* for getcwd */
+      #include <sys/types.h> /* for getpwuid */
+      #include <pwd.h> /* for getpwuid */
+      #define WEXITSTATUS(w)((w)>>8)                                       // fixes WEXITSTATUS not declared on FreeBSD
+#endif
+
 #define fversion "Fotoxx v.11.03    2011.03.01"                            //  version and date
 #define fversioncc 16                                                      //  cc to use for window title bar
 #define flicense "Free software - GNU General Public License v.3"
@@ -200,7 +207,7 @@
 PXM         *Dpxm16 = 0;                                                   //  drawing window pixmap, 1x 16-bits
 PXM         *Dpxm8 = 0;                                                    //  drawing window pixmap, Mscale 8-bits
 
-mutex       Fpixmap_lock;                                                  //  lock for accessing PXM pixmaps
+mutex_tp       Fpixmap_lock;                                                  //  lock for accessing PXM pixmaps
 
 int         Fww, Fhh;                                                      //  input image dimensions
 int         E1ww, E1hh, E3ww, E3hh;                                        //  edit image dimensions
@@ -986,7 +993,7 @@
    }
    
    if (! curr_file) {                                                      //  set curr. directory anyway   v.11.01
-      ppv = get_current_dir_name();
+      ppv = getwd(null);
       curr_dirk = strdupz(ppv,0,"curr_dirk");
       free(ppv);
       err = chdir(curr_dirk);
@@ -2428,7 +2435,7 @@
    if (curr_file)
       image_gallery(curr_file,"paint1",0,m_gallery2,mWin);                 //  overlay main window    v.10.9
    else {
-      char *pp = get_current_dir_name();
+      char *pp = getwd(null);
       if (pp) {
          image_gallery(pp,"paint1",0,m_gallery2,mWin);                     //  use current directory   v.10.9
          free(pp);
@@ -5169,7 +5176,7 @@
    }
 
    *tempdir = 0;                                                           //  temp directory: /tmp/<user>/fotoxx/email
-   strncatv(tempdir,99,"/tmp/",cuserid(null),"/fotoxx/email",null);
+   strncatv(tempdir,99,"/tmp/",getpwuid(null),"/fotoxx/email",null);
 
    sprintf(command,"mkdir -p %s",tempdir);                                 //  (re)create directory
    err = system(command);
