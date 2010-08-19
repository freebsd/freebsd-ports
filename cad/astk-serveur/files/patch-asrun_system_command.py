--- ./asrun/system_command.py.orig	2010-07-07 18:18:08.000000000 +0200
+++ ./asrun/system_command.py	2010-08-16 21:09:31.000000000 +0200
@@ -21,9 +21,9 @@
 This module defines syntaxes to run command lines.
 """
 
-from asrun.common.sysutils import on_linux
+from asrun.common.sysutils import on_windows
 
-if on_linux():
+if not on_windows():
     COMMAND = {
         'background' : '( %(cmd)s ) > %(output)s 2>&1 &',
         'follow_with_stderr' : '( %(cmd)s ; echo %(var)s=$? ) 2>&1 | tee %(output)s',
@@ -32,7 +32,7 @@
         'not_follow_separ_stderr' : '( %(cmd)s ) > %(output)s 2> %(error)s',
         'rm_file' : '\\rm -f %(args)s',
         'rm_dirs' : '\\rm -rf %(args)s',
-        'copy' : 'cp -L -r %(args)s',
+        'copy' : 'cp -L -R %(args)s',
         'ping' : 'ping -c 1 -W %(timeout)s %(host)s',
         'shell_cmd' : "bash -c",
     }
