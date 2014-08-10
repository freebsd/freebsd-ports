--- build/depends.py.orig	2012-01-16 06:02:51.000000000 +0900
+++ build/depends.py	2012-01-16 06:04:08.000000000 +0900
@@ -150,7 +150,7 @@
 
 class Qt(Dependence):
     DEFAULT_QTDIRS = {'linux': '/usr/share/qt4',
-                      'bsd': '/usr/local/lib/qt4',
+                      'bsd': '%%LOCALBASE%%/lib/qt4',
                       'osx': '/Library/Frameworks',
                       'windows': 'C:\\qt\\4.6.0'}
 
@@ -219,6 +219,7 @@
             build.env.Append(LIBS = 'QtOpenGL')
             build.env.Append(LIBS = 'QtXml')
             build.env.Append(LIBS = 'QtNetwork')
+            build.env.Append(LIBS = 'QtSql')
             build.env.Append(LIBS = 'QtScript')
             if use_qtwebkit:
                 build.env.Append(LIBS = 'QtWebKit')
@@ -264,16 +265,16 @@
 
         # Set Qt include paths for non-OSX
         if not build.platform_is_osx:
-            include_paths = ['$QTDIR/include/QtCore',
-                             '$QTDIR/include/QtGui',
-                             '$QTDIR/include/QtOpenGL',
-                             '$QTDIR/include/QtXml',
-                             '$QTDIR/include/QtNetwork',
-                             '$QTDIR/include/QtSql',
-                             '$QTDIR/include/QtScript',
-                             '$QTDIR/include/Qt']
+            include_paths = ['$QTDIR/include/qt4/QtCore',
+                             '$QTDIR/include/qt4/QtGui',
+                             '$QTDIR/include/qt4/QtOpenGL',
+                             '$QTDIR/include/qt4/QtXml',
+                             '$QTDIR/include/qt4/QtNetwork',
+                             '$QTDIR/include/qt4/QtSql',
+                             '$QTDIR/include/qt4/QtScript',
+                             '$QTDIR/include/qt4/Qt']
             if use_qtwebkit:
-                include_paths.append('$QTDIR/include/QtWebKit')
+                include_paths.append('$QTDIR/include/qt4/QtWebKit')
             build.env.Append(CPPPATH=include_paths)
 
         # Set the rpath for linux/bsd/osx.
@@ -387,7 +388,7 @@
         # the files correctly. Adding this folder ot the include path should fix
         # it, though might cause issues. This is safe to remove once we
         # deprecate Karmic support. rryan 2/2011
-        build.env.Append(CPPPATH='/usr/include/taglib/')
+        build.env.Append(CPPPATH='%%LOCALBASE%%/include/taglib/')
 
         if build.platform_is_windows and build.static_dependencies:
             build.env.Append(CPPDEFINES = 'TAGLIB_STATIC')
@@ -782,14 +783,9 @@
         if build.toolchain_is_gnu:
             # Default GNU Options
             # TODO(XXX) always generate debugging info?
-            build.env.Append(CCFLAGS = '-pipe')
             build.env.Append(CCFLAGS = '-Wall')
             build.env.Append(CCFLAGS = '-Wextra')
-            build.env.Append(CCFLAGS = '-g')
 
-            # Check that g++ is present (yeah, SCONS is a bit dumb here)
-            if os.system("which g++ > /dev/null"): #Checks for non-zero return code
-                raise Exception("Did not find g++.")
         elif build.toolchain_is_msvs:
             # Validate the specified winlib directory exists
             mixxx_lib_path = SCons.ARGUMENTS.get('winlib', '..\\..\\..\\mixxx-win32lib-msvc100-release')
@@ -851,16 +847,20 @@
 
         elif build.platform_is_bsd:
             build.env.Append(CPPDEFINES='__BSD__')
-            build.env.Append(CPPPATH=['/usr/include',
-                                      '/usr/local/include',
-                                      '/usr/X11R6/include/'])
-            build.env.Append(LIBPATH=['/usr/lib/',
-                                      '/usr/local/lib',
-                                      '/usr/X11R6/lib'])
             build.env.Append(LIBS='pthread')
+            build.env.Append(CPPPATH=['%%LOCALBASE%%/include/portaudio2',
+                                      '%%LOCALBASE%%/include/qt4',
+                                      '%%LOCALBASE%%/include'])
+            build.env.Append(LIBPATH=['%%LOCALBASE%%/lib/portaudio2',
+                                      '%%LOCALBASE%%/lib/qt4',
+                                      '%%LOCALBASE%%/lib'])
+            build.env.Append(LINKFLAGS=['%%LOCALBASE%%/lib/portaudio2/libportaudio.so',
+                                        '-Wl,-rpath,%%LOCALBASE%%/lib/portaudio2',
+                                        '-Wl,-rpath,%%LOCALBASE%%/lib/qt4',
+                                        '-Wl,-rpath,%%LOCALBASE%%/lib'])
             # why do we need to do this on OpenBSD and not on Linux?  if we
             # don't then CheckLib("vorbisfile") fails
-            build.env.Append(LIBS=['ogg', 'vorbis'])
+            # build.env.Append(LIBS=['ogg', 'vorbis'])
 
         # Define for things that would like to special case UNIX (Linux or BSD)
         if build.platform_is_bsd or build.platform_is_linux:
@@ -897,14 +896,14 @@
         # Say where to find resources on Unix. TODO(XXX) replace this with a
         # RESOURCE_PATH that covers Win and OSX too:
         if build.platform_is_linux or build.platform_is_bsd:
-            prefix = SCons.ARGUMENTS.get('prefix', '/usr/local')
+            prefix = SCons.ARGUMENTS.get('prefix', '%%PREFIX%%')
             share_path = os.path.join(prefix, 'share/mixxx')
             build.env.Append(CPPDEFINES=('UNIX_SHARE_PATH', r'\"%s\"' % share_path))
             lib_path = os.path.join(prefix, 'lib/mixxx')
             build.env.Append(CPPDEFINES=('UNIX_LIB_PATH', r'\"%s\"' % lib_path))
 
     def depends(self, build):
-        return [SoundTouch, ReplayGain, PortAudio, PortMIDI, Qt,
+        return [SoundTouch, ReplayGain, PortAudio, Qt,
                 FidLib, SndFile, FLAC, OggVorbis, OpenGL, TagLib, ProtoBuf]
 
     def post_dependency_check_configure(self, build, conf):
