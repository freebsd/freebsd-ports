--- build/depends.py	2018-09-05 15:20:52.000000000 -0500
+++ build/depends.py	2018-10-30 14:47:39.928944000 -0500
@@ -12,7 +12,7 @@
         if not conf.CheckLib('portaudio'):
             raise Exception(
                 'Did not find libportaudio.a, portaudio.lib, or the PortAudio-v19 development header files.')
-        elif build.platform_is_linux:
+        elif build.platform_is_linux or build.platform_is_bsd:
             build.env.ParseConfig('pkg-config portaudio-2.0 --silence-errors --cflags --libs')
 
         # Turn on PortAudio support in Mixxx
@@ -74,7 +74,8 @@
 
         if (not conf.CheckLib('GLU') and
                 not conf.CheckLib('glu32') and
-                not conf.CheckCHeader('OpenGL/glu.h')):
+                not conf.CheckCHeader('OpenGL/glu.h') and
+                not conf.CheckCHeader('GL/glu.h')):
             raise Exception('Did not find GLU development files')
 
 
@@ -106,7 +107,7 @@
 class UPower(Dependence):
     """UPower is used to get battery measurements on Linux."""
     def configure(self, build, conf):
-        if not build.platform_is_linux:
+        if not build.platform_is_linux or not build.platform_is_bsd:
             return
         build.env.ParseConfig(
                 'pkg-config upower-glib --silence-errors --cflags --libs')
@@ -185,15 +186,17 @@
 
 class Qt(Dependence):
     DEFAULT_QT4DIRS = {'linux': '/usr/share/qt4',
-                       'bsd': '/usr/local/lib/qt4',
+                       'bsd': '%%LOCALBASE%%/share/qt4',
                        'osx': '/Library/Frameworks',
                        'windows': 'C:\\qt\\4.6.0'}
 
     DEFAULT_QT5DIRS64 = {'linux': '/usr/lib/x86_64-linux-gnu/qt5',
+                         'bsd': '%%LOCALBASE%%/lib/qt5',
                          'osx': '/Library/Frameworks',
                          'windows': 'C:\\qt\\5.0.1'}
 
     DEFAULT_QT5DIRS32 = {'linux': '/usr/lib/i386-linux-gnu/qt5',
+                         'bsd': '%%LOCALBASE%%/lib/qt5',
                          'osx': '/Library/Frameworks',
                          'windows': 'C:\\qt\\5.0.1'}
 
@@ -319,9 +322,17 @@
                 build.env.Append(CCFLAGS='-fPIC')
 
         elif build.platform_is_bsd:
-            build.env.Append(LIBS=qt_modules)
-            include_paths = ['$QTDIR/include/%s' % module
-                             for module in qt_modules]
+	    qt_modules.extend(['QtDBus'])
+	    if qt5:
+		qt5_modules = [w.replace('Qt', 'Qt5') for w in qt_modules]
+		build.env.Append(LIBS = qt5_modules)
+		build.env.Append(CCFLAGS='-fPIC')
+                include_paths = ['%%LOCALBASE%%/include/qt5/%s' % module
+                                for module in qt_modules]
+            else:
+		build.env.Append(LIBS = qt_modules)
+                include_paths = ['%%LOCALBASE%%/include/qt4/%s' % module
+                                for module in qt_modules]
             build.env.Append(CPPPATH=include_paths)
         elif build.platform_is_osx:
             qtdir = build.env['QTDIR']
@@ -487,7 +498,7 @@
         if not build.platform_is_windows and not (using_104_sdk or compiling_on_104):
             qtdir = build.env['QTDIR']
             framework_path = Qt.find_framework_libdir(qtdir, qt5)
-            if os.path.isdir(framework_path):
+	    if framework_path and os.path.isdir(framework_path):
                 build.env.Append(LINKFLAGS="-L" + framework_path)
 
         # Mixxx requires C++11 support. Windows enables C++11 features by
@@ -581,7 +592,7 @@
         if env is None:
             env = build.env
 
-        if build.platform_is_linux:
+        if build.platform_is_linux or build.platform_is_bsd:
             # Try using system lib
             if conf.CheckForPKG('soundtouch', '2.0.0'):
                 # System Lib found
@@ -625,7 +636,7 @@
         # the files correctly. Adding this folder ot the include path should fix
         # it, though might cause issues. This is safe to remove once we
         # deprecate Karmic support. rryan 2/2011
-        build.env.Append(CPPPATH='/usr/include/taglib/')
+        build.env.Append(CPPPATH='%%LOCALBASE%%/include/taglib/')
 
         if build.platform_is_windows and build.static_dependencies:
             build.env.Append(CPPDEFINES='TAGLIB_STATIC')
@@ -1337,7 +1348,6 @@
 
         if build.toolchain_is_gnu:
             # Default GNU Options
-            build.env.Append(CCFLAGS='-pipe')
             build.env.Append(CCFLAGS='-Wall')
             if build.compiler_is_clang:
                 # Quiet down Clang warnings about inconsistent use of override
@@ -1445,9 +1455,9 @@
 
         elif build.platform_is_osx:
             # Stuff you may have compiled by hand
-            if os.path.isdir('/usr/local/include'):
-                build.env.Append(LIBPATH=['/usr/local/lib'])
-                build.env.Append(CPPPATH=['/usr/local/include'])
+            if os.path.isdir('%%LOCALBASE%%/include'):
+                build.env.Append(LIBPATH=['%%LOCALBASE%%/lib'])
+                build.env.Append(CPPPATH=['%%LOCALBASE%%/include'])
 
             # Non-standard libpaths for fink and certain (most?) darwin ports
             if os.path.isdir('/sw/include'):
@@ -1460,17 +1470,24 @@
                 build.env.Append(CPPPATH=['/opt/local/include'])
 
         elif build.platform_is_bsd:
+	    qt5 = Qt.qt5_enabled(build)
+
+	    if qt5:
+	      qtdirectory = 'qt5'
+            else:
+	      qtdirectory = 'qt4'
+
             build.env.Append(CPPDEFINES='__BSD__')
             build.env.Append(CPPPATH=['/usr/include',
-                                      '/usr/local/include',
-                                      '/usr/X11R6/include/'])
+                                      '%%LOCALBASE%%/include',
+                                      '%%LOCALBASE%%/include/'+ qtdirectory])
             build.env.Append(LIBPATH=['/usr/lib/',
-                                      '/usr/local/lib',
-                                      '/usr/X11R6/lib'])
+                                      '%%LOCALBASE%%/lib',
+                                      '%%LOCALBASE%%/lib/'+ qtdirectory])
             build.env.Append(LIBS='pthread')
             # why do we need to do this on OpenBSD and not on Linux?  if we
             # don't then CheckLib("vorbisfile") fails
-            build.env.Append(LIBS=['ogg', 'vorbis'])
+            build.env.Append(LIBS=['ogg', 'vorbis','X11'])
 
         # Define for things that would like to special case UNIX (Linux or BSD)
         if build.platform_is_bsd or build.platform_is_linux:
@@ -1503,7 +1520,7 @@
         # Say where to find resources on Unix. TODO(XXX) replace this with a
         # RESOURCE_PATH that covers Win and OSX too:
         if build.platform_is_linux or build.platform_is_bsd:
-            prefix = SCons.ARGUMENTS.get('prefix', '/usr/local')
+            prefix = SCons.ARGUMENTS.get('prefix', '%%PREFIX%%')
             share_path = os.path.join (prefix, build.env.get(
                 'SHAREDIR', default='share'), 'mixxx')
             build.env.Append(
@@ -1514,7 +1531,7 @@
                 CPPDEFINES=('UNIX_LIB_PATH', r'\"%s\"' % lib_path))
 
     def depends(self, build):
-        return [SoundTouch, ReplayGain, Ebur128Mit, PortAudio, PortMIDI, Qt, TestHeaders,
+        return [SoundTouch, ReplayGain, Ebur128Mit, PortAudio, Qt, TestHeaders,
                 FidLib, SndFile, FLAC, OggVorbis, OpenGL, TagLib, ProtoBuf,
                 Chromaprint, RubberBand, SecurityFramework, CoreServices, IOKit,
                 QtScriptByteArray, Reverb, FpClassify, PortAudioRingBuffer]
