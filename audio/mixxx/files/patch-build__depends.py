--- build/depends.py.orig	2012-01-16 06:02:51.000000000 +0900
+++ build/depends.py	2012-01-16 06:04:08.000000000 +0900
@@ -99,7 +99,7 @@
 
 class Qt(Dependence):
     DEFAULT_QTDIRS = {'linux': '/usr/share/qt4',
-                      'bsd': '/usr/local/lib/qt4',
+                      'bsd': '%%LOCALBASE%%/lib/qt4',
                       'osx': '/Library/Frameworks',
                       'windows': 'C:\\qt\\4.6.0'}
 
@@ -145,6 +145,8 @@
         # Setup Qt library includes for non-OSX
         if build.platform_is_linux or build.platform_is_bsd:
             build.env.Append(LIBS = 'QtXml')
+            build.env.Append(LIBS = 'QtXmlPatterns')
+            build.env.Append(LIBS = 'QtSql')
             build.env.Append(LIBS = 'QtGui')
             build.env.Append(LIBS = 'QtCore')
             build.env.Append(LIBS = 'QtNetwork')
@@ -164,14 +166,14 @@
 
         # Set Qt include paths for non-OSX
         if not build.platform_is_osx:
-            build.env.Append(CPPPATH=['$QTDIR/include/QtCore',
-                                      '$QTDIR/include/QtGui',
-                                      '$QTDIR/include/QtXml',
-                                      '$QTDIR/include/QtNetwork',
-                                      '$QTDIR/include/QtSql',
-                                      '$QTDIR/include/QtOpenGL',
-                                      '$QTDIR/include/QtWebKit',
-                                      '$QTDIR/include/Qt'])
+            build.env.Append(CPPPATH=['$QTDIR/include/qt4/QtCore',
+                                      '$QTDIR/include/qt4/QtGui',
+                                      '$QTDIR/include/qt4/QtXml',
+                                      '$QTDIR/include/qt4/QtNetwork',
+                                      '$QTDIR/include/qt4/QtSql',
+                                      '$QTDIR/include/qt4/QtOpenGL',
+                                      '$QTDIR/include/qt4/QtWebKit',
+                                      '$QTDIR/include/qt4/Qt'])
 
         # Set the rpath for linux/bsd/osx.
         # This is not support on OS X before the 10.5 SDK.
@@ -179,8 +181,6 @@
         compiling_on_104 = False
         if build.platform_is_osx:
             compiling_on_104 = (os.popen('sw_vers').readlines()[1].find('10.4') >= 0)
-        if not build.platform_is_windows and not (using_104_sdk or compiling_on_104):
-            build.env.Append(LINKFLAGS = "-Wl,-rpath,$QTDIR/lib")
 
         #QtSQLite DLL
         if build.platform_is_windows:
@@ -298,7 +298,7 @@
         # the files correctly. Adding this folder ot the include path should fix
         # it, though might cause issues. This is safe to remove once we
         # deprecate Karmic support. rryan 2/2011
-        build.env.Append(CPPPATH='/usr/include/taglib/')
+        build.env.Append(CPPPATH='%%LOCALBASE%%/include/taglib/')
 class MixxxCore(Feature):
 
     def description(self):
@@ -623,10 +623,8 @@
         if build.toolchain_is_gnu:
             # Default GNU Options
             # TODO(XXX) always generate debugging info?
-            build.env.Append(CCFLAGS = '-pipe')
             build.env.Append(CCFLAGS = '-Wall')
             build.env.Append(CCFLAGS = '-Wextra')
-            build.env.Append(CCFLAGS = '-g')
 
             # Check that g++ is present (yeah, SCONS is a bit dumb here)
             if os.system("which g++ > /dev/null"): #Checks for non-zero return code
@@ -676,8 +674,8 @@
 
         elif build.platform_is_osx:
             #Stuff you may have compiled by hand
-            build.env.Append(LIBPATH = ['/usr/local/lib'])
-            build.env.Append(CPPPATH = ['/usr/local/include'])
+            build.env.Append(LIBPATH = ['%%LOCALBASE%%/lib'])
+            build.env.Append(CPPPATH = ['%%LOCALBASE%%/include'])
 
             #Non-standard libpaths for fink and certain (most?) darwin ports
             build.env.Append(LIBPATH = ['/sw/lib'])
@@ -689,13 +687,15 @@
 
         elif build.platform_is_bsd:
             build.env.Append(CPPDEFINES='__BSD__')
-            build.env.Append(CPPPATH=['/usr/include',
-                                      '/usr/local/include',
-                                      '/usr/X11R6/include/'])
-            build.env.Append(LIBPATH=['/usr/lib/',
-                                      '/usr/local/lib',
-                                      '/usr/X11R6/lib'])
-            build.env.Append(LIBS='pthread')
+            build.env.Append(CPPPATH=['%%LOCALBASE%%/include/portaudio2',
+                                      '%%LOCALBASE%%/include/qt4',
+                                      '%%LOCALBASE%%/include'])
+            build.env.Append(LIBPATH=['%%LOCALBASE%%/lib/portaudio2',
+                                      '%%LOCALBASE%%/lib/qt4',
+                                      '%%LOCALBASE%%/lib'])
+            build.env.Append(LINKFLAGS=['-Wl,-rpath,%%LOCALBASE%%/lib/portaudio2',
+                                        '-Wl,-rpath,%%LOCALBASE%%/lib/qt4',
+                                        '-Wl,-rpath,%%LOCALBASE%%/lib'])
             # why do we need to do this on OpenBSD and not on Linux?  if we
             # don't then CheckLib("vorbisfile") fails
             build.env.Append(LIBS=['ogg', 'vorbis'])
@@ -735,11 +735,11 @@
         # Say where to find resources on Unix. TODO(XXX) replace this with a
         # RESOURCE_PATH that covers Win and OSX too:
         if build.platform_is_linux or build.platform_is_bsd:
-            share_path = os.path.join(SCons.ARGUMENTS.get('prefix', '/usr/local'), 'share/mixxx')
+            share_path = os.path.join(SCons.ARGUMENTS.get('prefix', '%%PREFIX%%'), 'share/mixxx')
             build.env.Append(CPPDEFINES=('UNIX_SHARE_PATH', r'\"%s\"' % share_path))
 
     def depends(self, build):
-        return [SoundTouch, KissFFT, ReplayGain, PortAudio, PortMIDI, Qt,
+        return [SoundTouch, KissFFT, ReplayGain, PortAudio, Qt,
                 FidLib, SndFile, FLAC, OggVorbis, OpenGL, TagLib,]
 
     def post_dependency_check_configure(self, build, conf):
