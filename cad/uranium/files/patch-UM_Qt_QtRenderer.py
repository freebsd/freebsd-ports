--- UM/Qt/QtRenderer.py.orig	2020-03-08 12:13:28 UTC
+++ UM/Qt/QtRenderer.py
@@ -129,7 +129,7 @@ class QtRenderer(Renderer):
         if not self._initialized:
             self._initialize()
 
-        self._gl.glViewport(0, 0, self._viewport_width, self._viewport_height)
+        self._gl.glViewport(0, 0, int(self._viewport_width), int(self._viewport_height))
         self._gl.glClearColor(self._background_color.redF(), self._background_color.greenF(), self._background_color.blueF(), self._background_color.alphaF())
         self._gl.glClear(self._gl.GL_COLOR_BUFFER_BIT | self._gl.GL_DEPTH_BUFFER_BIT)
         self._gl.glClearColor(0.0, 0.0, 0.0, 0.0)
@@ -157,7 +157,7 @@ class QtRenderer(Renderer):
 
         for render_pass in self.getRenderPasses():
             width, height = render_pass.getSize()
-            self._gl.glViewport(0, 0, width, height)
+            self._gl.glViewport(0, 0, int(width), int(height))
             render_pass.render()
 
     def reRenderLast(self):
