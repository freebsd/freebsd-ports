--- Lib/distutils/spawn.py.orig	Tue Feb 24 16:55:44 2004
+++ Lib/distutils/spawn.py	Tue Feb 24 16:56:01 2004
@@ -144,7 +144,13 @@
         # Loop until the child either exits or is terminated by a signal
         # (ie. keep waiting if it's merely stopped)
         while 1:
-            (pid, status) = os.waitpid(pid, 0)
+            try:
+                (pid, status) = os.waitpid(pid, 0)
+            except OSError, exc:
+                import errno
+                if exc.errno == errno.EINTR:
+                    continue
+                raise exc
             if os.WIFSIGNALED(status):
                 raise DistutilsExecError, \
                       "command '%s' terminated by signal %d" % \
