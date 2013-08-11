--- pypy/module/_posixsubprocess/interp_subprocess.py~	2013-08-09 19:13:04.000000000 +0200
+++ pypy/module/_posixsubprocess/interp_subprocess.py	2013-08-09 19:20:31.000000000 +0200
@@ -12,8 +12,10 @@
 
 class CConfig:
     _compilation_info_ = ExternalCompilationInfo(
-        includes=['unistd.h', 'sys/syscall.h'])
+        includes=['unistd.h', 'sys/stat.h', 'sys/syscall.h', 'sys/types.h'])
+    HAVE_SYS_STAT_H = platform.Has('stat')
     HAVE_SYS_SYSCALL_H = platform.Has("syscall")
+    HAVE_SYS_TYPES_H = platform.Has('types')
     HAVE_SETSID = platform.Has("setsid")
 
 config = platform.configure(CConfig)
@@ -26,8 +28,12 @@
                     ])
 
 compile_extra = []
+if config['HAVE_SYS_STAT_H']:
+    compile_extra.append('-DHAVE_SYS_STAT_H')
 if config['HAVE_SYS_SYSCALL_H']:
     compile_extra.append("-DHAVE_SYS_SYSCALL_H")
+if config['HAVE_SYS_TYPES_H']:
+    compile_extra.append('-DHAVE_SYS_TYPES_H')
 if config['HAVE_SETSID']:
     compile_extra.append("-DHAVE_SETSID")
 
