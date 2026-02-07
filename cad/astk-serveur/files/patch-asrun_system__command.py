--- asrun/system_command.py.orig	2017-07-13 07:40:52 UTC
+++ asrun/system_command.py
@@ -21,9 +21,9 @@
 This module defines syntaxes to run command lines.
 """
 
-from asrun.common.sysutils import on_linux
+from asrun.common.sysutils import on_windows
 
-if on_linux():
+if not on_windows():
     COMMAND = {
         'foreground' : '( %(cmd)s ) > /dev/null 2>&1',
         'background' : '( %(cmd)s ) > /dev/null 2>&1 &',
@@ -33,7 +33,7 @@ if on_linux():
         'not_follow_separ_stderr' : '( %(cmd)s ) > %(output)s 2> %(error)s',
         'rm_file' : '\\rm -f %(args)s',
         'rm_dirs' : '\\rm -rf %(args)s',
-        'copy' : 'cp -L -r %(args)s',
+        'copy' : 'cp -L -R %(args)s',
         'ping' : 'ping -c 1 -W %(timeout)s %(host)s',
         'shell_cmd' : "bash -c",
         'file' : "file %(args)s",
