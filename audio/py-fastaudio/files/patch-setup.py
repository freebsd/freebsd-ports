--- setup.py.orig	Sat Mar  3 10:39:05 2007
+++ setup.py	Fri Mar  9 22:28:00 2007
@@ -4,6 +4,7 @@
 
 import sys
 
+libDir=[]
 if sys.platform == 'win32':
     faSources=['fastaudio.pyx', '../pa_common/pa_lib.c', '../pa_win_wmme/pa_win_wmme.c']
     defines = [('WIN32', 1)]
@@ -15,12 +16,22 @@
     libs = ['sndfile']
     extra_link_args = ['/usr/lib/libsndfile.a']
 #faSources=['fastaudio.pyx']
+elif sys.platform.find('freebsd') != -1:
+    faSources=['fastaudio.pyx', '../portaudio_v18_1/pa_common/pa_lib.c', '../portaudio_v18_1/pa_unix_oss/pa_unix_oss.c']
+    defines = []
+    libs = ['sndfile']
+    libDir = ['%%LOCALBASE%%/lib']
+    extra_link_args = ['-lportaudio']
+    #extra_link_args = ['-lsndfile']
+    include_dirs=['%%LOCALBASE%%/include', '../portaudio_v18_1/pa_common']
 
 ext_fastaudio = [Extension('fastaudio',
                           faSources,
-                          include_dirs=['../pa_common'],
+                          #include_dirs=,
+			  include_dirs,
                           define_macros=defines,
                           libraries=libs,
+			  library_dirs=libDir,
                           extra_link_args=extra_link_args
                           )]
                       
