--- setup.py.orig	2016-12-27 23:05:34 UTC
+++ setup.py
@@ -31,11 +31,11 @@ if system == 'Darwin':
         '-DLEVELDB_PLATFORM_POSIX',
         '-Wno-error=unused-command-line-argument-hard-error-in-future',
     ]
-elif system == 'Linux':
+elif system == 'FreeBSD':
     extra_compile_args = common_flags + [
         '-pthread',
         '-Wall',
-        '-DOS_LINUX',
+        '-DOS_FREEBSD',
         '-DLEVELDB_PLATFORM_POSIX',
     ]
 else:
