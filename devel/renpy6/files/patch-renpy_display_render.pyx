https://github.com/renpy/renpy/commit/ba832e5e3d52

--- renpy/display/render.pyx.orig	2014-10-03 01:16:12 UTC
+++ renpy/display/render.pyx
@@ -448,7 +448,7 @@ PIXELLATE = 3
 
 cdef class Render:
 
-    def __init__(Render self, float width, float height, draw_func=None, layer_name=None, bint opaque=None): #@DuplicatedSignature
+    def __init__(Render self, float width, float height, draw_func=None, layer_name=None, bint opaque=False): #@DuplicatedSignature
         """
         Creates a new render corresponding to the given widget with
         the specified width and height.
