--- pypy/module/_posixsubprocess/interp_subprocess.py.orig	2016-05-29 20:38:19 UTC
+++ pypy/module/_posixsubprocess/interp_subprocess.py
@@ -15,7 +15,8 @@ thisdir = py.path.local(__file__).dirpat
 
 class CConfig:
     _compilation_info_ = ExternalCompilationInfo(
-        includes=['unistd.h', 'sys/syscall.h'])
+        includes=['unistd.h', 'sys/stat.h', 'sys/syscall.h'])
+    HAVE_SYS_STAT_H = platform.Has("stat")
     HAVE_SYS_SYSCALL_H = platform.Has("syscall")
     HAVE_SETSID = platform.Has("setsid")
 
@@ -27,6 +28,8 @@ eci = ExternalCompilationInfo(
     separate_module_files=[thisdir.join('_posixsubprocess.c')])
 
 compile_extra = []
+if config['HAVE_SYS_STAT_H']:
+    compile_extra.append("-DHAVE_SYS_STAT_H")
 if config['HAVE_SYS_SYSCALL_H']:
     compile_extra.append("-DHAVE_SYS_SYSCALL_H")
 if config['HAVE_SETSID']:
