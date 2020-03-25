--- UM/View/GL/OpenGL.py.orig	2020-03-08 11:52:09 UTC
+++ UM/View/GL/OpenGL.py
@@ -19,6 +19,8 @@ from UM.View.GL.OpenGLContext import OpenGLContext
 from UM.i18n import i18nCatalog  # To make dialogs translatable.
 i18n_catalog = i18nCatalog("uranium")
 
+import OpenGL.GL as gl
+
 if TYPE_CHECKING:
     from UM.Mesh.MeshData import MeshData
 
@@ -59,7 +61,8 @@ class OpenGL:
             Logger.log("e", "Startup failed due to OpenGL context creation failing")
             QMessageBox.critical(None, i18n_catalog.i18nc("@message", "Failed to Initialize OpenGL", "Could not initialize an OpenGL context. This program requires OpenGL 2.0 or higher. Please check your video card drivers."))
             sys.exit(1)
-        self._gl = context.versionFunctions(profile) # type: Any #It's actually a protected class in PyQt that depends on the implementation of your graphics card.
+        self._gl = gl
+#        self._gl = context.versionFunctions(profile) # type: Any #It's actually a protected class in PyQt that depends on the implementation of your graphics card.
         if not self._gl:
             Logger.log("e", "Startup failed due to OpenGL initialization failing")
             QMessageBox.critical(None, i18n_catalog.i18nc("@message", "Failed to Initialize OpenGL", "Could not initialize OpenGL. This program requires OpenGL 2.0 or higher. Please check your video card drivers."))
@@ -75,14 +78,13 @@ class OpenGL:
             QMessageBox.critical(None, i18n_catalog.i18nc("Critical OpenGL Extensions Missing", "Critical OpenGL extensions are missing. This program requires support for Framebuffer Objects. Please check your video card drivers."))
             sys.exit(1)
 
-        self._gl.initializeOpenGLFunctions()
+#        self._gl.initializeOpenGLFunctions()
 
         self._gpu_vendor = OpenGL.Vendor.Other #type: int
-        vendor_string = self._gl.glGetString(self._gl.GL_VENDOR)
+        vendor_string = self._gl.glGetString(self._gl.GL_VENDOR).decode("utf-8")
         if vendor_string is None:
             vendor_string = "Unknown"
         vendor_string = vendor_string.lower()
-
         if "nvidia" in vendor_string:
             self._gpu_vendor = OpenGL.Vendor.NVidia
         elif "amd" in vendor_string or "ati" in vendor_string:
