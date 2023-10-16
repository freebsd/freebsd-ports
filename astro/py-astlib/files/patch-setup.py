Reference:	https://github.com/mattyowl/astLib/pull/9
		https://github.com/mattyowl/astLib/commit/6844b308fb9ff1a71486dff98793bfec1ed13349

--- setup.py.orig	2023-10-12 15:29:16 UTC
+++ setup.py
@@ -36,7 +36,7 @@ class build_PyWCSTools_ext(build_ext):
 
         os.chdir(sourceDir)
         cc=setuptools._distutils.ccompiler.new_compiler(setuptools._distutils.ccompiler.get_default_compiler())
-        cc.compiler_so=[sysconfig.get_config_var('CC')]+sysconfig.get_config_var('CFLAGS').split()+sysconfig.get_config_var('CFLAGSFORSHARED').split()
+        cc.compiler_so=sysconfig.get_config_var('CC').split()+sysconfig.get_config_var('CFLAGS').split()+sysconfig.get_config_var('CFLAGSFORSHARED').split()
 
         # Suppress warnings from compiling WCSTools wcssubs-3.9.5
         if "-Wstrict-prototypes" in cc.compiler_so:
@@ -55,7 +55,7 @@ class build_PyWCSTools_ext(build_ext):
 
         build_ext.build_extensions(self)
 
-setup(name='astLib',
+setup(name='astlib',
     version='0.11.9',
     url='https://astlib.readthedocs.io',
     author='Matt Hilton & Steven Boada',
