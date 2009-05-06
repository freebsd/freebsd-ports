--- OpenGL/__init__.py.orig	2008-12-07 06:58:16.000000000 +0300
+++ OpenGL/__init__.py	2009-04-12 07:52:27.000000000 +0400
@@ -102,7 +102,7 @@
 # Declarations of plugins provided by PyOpenGL itself
 from OpenGL.plugins import PlatformPlugin, FormatHandler
 PlatformPlugin( 'nt', 'OpenGL.platform.win32.Win32Platform' )
-PlatformPlugin( 'posix ', 'OpenGL.platform.glx.GLXPlatform' )
+PlatformPlugin( 'posix', 'OpenGL.platform.glx.GLXPlatform' )
 PlatformPlugin( 'linux2', 'OpenGL.platform.glx.GLXPlatform' )
 PlatformPlugin( 'darwin', 'OpenGL.platform.darwin.DarwinPlatform' )
 
