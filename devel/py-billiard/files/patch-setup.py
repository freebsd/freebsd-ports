diff --git setup.py setup.py
index 41dc3ec..078ce12 100644
--- setup.py
+++ setup.py
@@ -6,6 +6,7 @@ try:
     from setuptools import setup, Extension, find_packages
 except ImportError:
     from distutils.core import setup, Extension, find_packages  # noqa
+from distutils import sysconfig
 from distutils.errors import (
     CCompilerError,
     DistutilsExecError,
@@ -119,7 +120,7 @@ elif sys.platform in ('freebsd4', 'freebsd5', 'freebsd6'):
     libraries = []
 elif sys.platform in ('freebsd7', 'freebsd8', 'freebsd9', 'freebsd10'):
     macros = dict(                  # FreeBSD 7+
-            HAVE_SEM_OPEN=1,
+            HAVE_SEM_OPEN=int(sysconfig.get_config_var('HAVE_SEM_OPEN') and not bool(sysconfig.get_config_var('POSIX_SEMAPHORES_NOT_ENABLED'))),
             HAVE_SEM_TIMEDWAIT=1,
             HAVE_FD_TRANSFER=1,
         )
@@ -221,7 +222,7 @@ def run_setup(with_extensions=True):
 
 try:
     run_setup(not (is_jython or is_pypy or is_py3k))
-except (Exception, SystemExit):
+except (Exception):
     import traceback
     sys.stderr.write(BUILD_WARNING % '\n'.join(traceback.format_stack(), ))
     run_setup(False)
