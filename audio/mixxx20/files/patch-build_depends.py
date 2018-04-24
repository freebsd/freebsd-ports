--- build/depends.py.orig	2015-12-29 16:10:41 UTC
+++ build/depends.py
@@ -262,7 +262,7 @@ class Qt(Dependence):
 
         elif build.platform_is_bsd:
             build.env.Append(LIBS=qt_modules)
-            include_paths = ['$QTDIR/include/%s' % module
+            include_paths = ['%%LOCALBASE%%/include/qt4/%s' % module
                              for module in qt_modules]
             build.env.Append(CPPPATH=include_paths)
         elif build.platform_is_osx:
@@ -358,7 +358,7 @@ class Qt(Dependence):
         if not build.platform_is_windows and not (using_104_sdk or compiling_on_104):
             qtdir = build.env['QTDIR']
             framework_path = Qt.find_framework_libdir(qtdir, qt5)
-            if os.path.isdir(framework_path):
+            if framework_path and os.path.isdir(framework_path):
                 build.env.Append(LINKFLAGS="-Wl,-rpath," + framework_path)
                 build.env.Append(LINKFLAGS="-L" + framework_path)
 
@@ -1045,7 +1045,6 @@ class MixxxCore(Feature):
 
         if build.toolchain_is_gnu:
             # Default GNU Options
-            build.env.Append(CCFLAGS='-pipe')
             build.env.Append(CCFLAGS='-Wall')
             build.env.Append(CCFLAGS='-Wextra')
 
@@ -1146,11 +1145,13 @@ class MixxxCore(Feature):
 
         elif build.platform_is_bsd:
             build.env.Append(CPPDEFINES='__BSD__')
-            build.env.Append(CPPPATH=['/usr/include',
-                                      '/usr/local/include',
+            build.env.Append(CPPPATH=['%%LOCALBASE%%/include/portaudio2',
+                                      '%%LOCALBASE%%/include/qt4',
+                                      '%%LOCALBASE%%/include',
                                       '/usr/X11R6/include/'])
-            build.env.Append(LIBPATH=['/usr/lib/',
-                                      '/usr/local/lib',
+            build.env.Append(LIBPATH=['%%LOCALBASE%%/lib/portaudio2',
+                                      '%%LOCALBASE%%/lib/qt4',
+                                      '%%LOCALBASE%%/lib',
                                       '/usr/X11R6/lib'])
             build.env.Append(LIBS='pthread')
             # why do we need to do this on OpenBSD and not on Linux?  if we
@@ -1188,7 +1189,7 @@ class MixxxCore(Feature):
         # Say where to find resources on Unix. TODO(XXX) replace this with a
         # RESOURCE_PATH that covers Win and OSX too:
         if build.platform_is_linux or build.platform_is_bsd:
-            prefix = SCons.ARGUMENTS.get('prefix', '/usr/local')
+            prefix = SCons.ARGUMENTS.get('prefix', '%%PREFIX%%')
             share_path = os.path.join (prefix, build.env.get(
                 'SHAREDIR', default='share'), 'mixxx')
             build.env.Append(
@@ -1199,7 +1200,7 @@ class MixxxCore(Feature):
                 CPPDEFINES=('UNIX_LIB_PATH', r'\"%s\"' % lib_path))
 
     def depends(self, build):
-        return [SoundTouch, ReplayGain, PortAudio, PortMIDI, Qt, TestHeaders,
+        return [SoundTouch, ReplayGain, PortAudio, Qt, TestHeaders,
                 FidLib, SndFile, FLAC, OggVorbis, OpenGL, TagLib, ProtoBuf,
                 Chromaprint, RubberBand, SecurityFramework, CoreServices, FpClassify]
 
