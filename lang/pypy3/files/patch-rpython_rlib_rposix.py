--- rpython/rlib/rposix.py.orig	2016-10-08 20:52:00 UTC
+++ rpython/rlib/rposix.py
@@ -233,7 +233,7 @@ else:
     else:
         _ptyh = 'pty.h'
     includes = ['unistd.h',  'sys/types.h', 'sys/wait.h',
-                'utime.h', 'sys/time.h', 'sys/times.h',
+                'utime.h', 'sys/time.h', 'sys/times.h', 'sys/ttycom.h',
                 'grp.h', 'dirent.h', 'sys/stat.h', 'fcntl.h',
                 'signal.h', 'sys/utsname.h', _ptyh]
     libraries = ['util']
