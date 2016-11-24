https://github.com/renpy/renpy/commit/ecadc55616f3
https://github.com/renpy/renpy/commit/e680702e87b8

--- renpy/gl/gltexture.pyx.orig	2014-10-05 01:47:19 UTC
+++ renpy/gl/gltexture.pyx
@@ -255,7 +255,7 @@ cdef class TextureCore:
         # The number of the OpenGL texture this texture object
         # represents.
         self.generation = 0
-        self.number = -1
+        self.number = 0
 
         # The format of this texture in the GPU (or 0 if not known).
         self.format = 0
@@ -447,7 +447,7 @@ cdef class TextureCore:
 
         cdef unsigned int texnums[1]
 
-        if self.number != -1:
+        if self.number != 0:
             return 0
 
         glGenTextures(1, texnums)
@@ -468,17 +468,19 @@ cdef class TextureCore:
 
         global total_texture_size
 
-        if self.number == -1:
+        if self.number == 0:
             return
 
         cdef GLuint texnums[1]
 
         texnums[0] = self.number
         glDeleteTextures(1, texnums)
+        self.number = 0
 
-        texture_numbers.remove(self.number)
+        texture_numbers.discard(self.number)
         total_texture_size -= self.width * self.height * 4
 
+
 class Texture(TextureCore):
     """
     We need to be a real python class, not a C extension, to ensure that
