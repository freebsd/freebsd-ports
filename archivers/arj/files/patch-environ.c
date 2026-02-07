--- environ.c.orig	2004-06-18 16:19:36 UTC
+++ environ.c
@@ -2058,7 +2058,7 @@ FILE *file_open(char *name, char *mode)
       /* ASR fix 01/10/2003 -- re-fix to handle umask 022 correctly */
       if((handle=open(name, oflag, 0644))==-1)
        return(NULL);
-      if(fcntl(handle, F_SETLK, &flk)==-1&&errno!=EINVAL)
+      if(fcntl(handle, F_SETLK, &flk)==-1&&errno!=EINVAL&&errno!=ENOTSUP)
       {
        close(handle);
        return(NULL);
