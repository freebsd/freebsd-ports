--- zfuncs.cc.orig	2011-02-28 17:04:24.000000000 +0100
+++ zfuncs.cc	2011-05-26 10:04:13.000000000 +0200
@@ -24,6 +24,15 @@
 
 #include "zfuncs.h"
 
+#ifdef __FreeBSD__
+   #include <sys/event.h>
+   #include <sys/types.h>
+   #include <sys/times.h>
+   #include <pwd.h>
+   #include <execinfo.h>
+
+   #define WEXITSTATUS(w)((w)>>8)  // fixes the WEXITSTATUS not declared on FreeBSD
+#endif
 
 /**************************************************************************
    system-level utility functions
@@ -778,23 +787,27 @@
       char        fname[200];       //  null-terminated file name within directory
    };
    
+   int f, kq, nev;
+   struct kevent change;
+   struct kevent event;
+   
    inotify_event     evbuff;
    struct timeval    waitime;
    fd_set            fids;
    int               wd, retval, cc, fcc;
-   int               evbcc = sizeof(evbuff);
+   int               evbcc = sizeof(event);
    static int        fid = -1;
    
    if (strEqu(action,"open"))                                              //  setup a monitored directory
    {
-      fid = inotify_init();
-      if (fid < 0) {
+      f = kqueue();
+      if (f < 0) {
          return -1;
       }
-      wd = inotify_add_watch(fid,dirk,IN_ALL_EVENTS);
+      wd = kevent(f, &change, 1, &event, 1, NULL);
       if (wd < 0) {
-         close(fid);
-         fid = -1;
+         close(f);
+         f = -1;
          return -1;
       }
       return 0;
@@ -802,7 +815,7 @@
    
    if (strEqu(action,"event"))                                             //  return pending event or zero
    {
-      if (fid < 0) return -1;
+      if (f < 0) return -1;
 
       if (file) {
          if (*file) zfree(*file);                                          //  free prior memory
@@ -816,12 +829,12 @@
          waitime.tv_sec = 0;
          waitime.tv_usec = 1;
 
-         retval = select(fid+1, &fids, null, null, &waitime);
+         retval = select(f+1, &fids, null, null, &waitime);
          if (retval == 0) return 0;                                        //  nothing pending
 
          if (retval == -1) {                                               //  error
             close(fid);
-            fid = -1;
+            f = -1;
             return -1;
          }
 
@@ -832,28 +845,21 @@
             return -1;
          }
 
-         fcc = evbuff.len;
-         if (fcc > 199) return -1;
-         if (fcc > 0 && file) 
-            *file = strdupz(evbuff.fname,0,"zmondirk_file");               //  return filename     v.3.5
-
-         if (evbuff.mask & (IN_CREATE | IN_MOVED_TO))                      //  file was added
+         if (event.fflags & (NOTE_WRITE | NOTE_RENAME))                    //  file was added
             return 1;
-         if (evbuff.mask & (IN_CLOSE_WRITE | IN_CLOSE_NOWRITE | IN_MODIFY))   //  file was possibly added
+         if (event.fflags & (NOTE_EXIT | NOTE_REVOKE | NOTE_ATTRIB))       //  file was possibly added
             return 1;
-         if (evbuff.mask & (IN_DELETE | IN_MOVED_FROM))                    //  file was deleted
+         if (event.fflags & (NOTE_DELETE))                                 //  file was deleted
             return 2;
-         if (evbuff.mask & (IN_DELETE_SELF | IN_MOVE_SELF))                //  monitored directory gone
-            return 3;
          return 9;                                                         //  other
       }
    }
    
    if (strEqu(action,"close"))                                             //  stop monitoring
    {
-      if (fid > -1) retval = close(fid);
+      if (f > -1) retval = close(f);
       else retval = -1;
-      fid = -1;
+      f = -1;
       return retval;
    }
    
@@ -2983,7 +2989,7 @@
    strcpy(zicondir,zdatadir);
    strcat(zicondir,"/icons");
 
-   pp = cuserid(0);
+   pp = getlogin();
    if (strEqu(pp,"root")) snprintf(zuserdir,199,"/root/.%s",zappname);     //  get /root/.appname
    else snprintf(zuserdir,199,"%s/.%s",getenv("HOME"),zappname);           //  or /home/user/.appname
 
