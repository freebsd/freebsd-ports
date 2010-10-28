--- environ.c.orig	2010-10-28 13:11:54.000000000 -0200
+++ environ.c	2010-10-28 13:13:10.000000000 -0200
@@ -2058,7 +2058,7 @@
       /* ASR fix 01/10/2003 -- re-fix to handle umask 022 correctly */
       if((handle=open(name, oflag, 0644))==-1)
        return(NULL);
-      if(fcntl(handle, F_SETLK, &flk)==-1&&errno!=EINVAL)
+      if(fcntl(handle, F_SETLK, &flk)==-1&&errno!=EINVAL&&errno!=ENOTSUP)
       {
        close(handle);
        return(NULL);
