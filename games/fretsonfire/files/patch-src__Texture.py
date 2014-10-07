--- src/Texture.py.orig	2014-10-07 12:30:12 UTC
+++ src/Texture.py
@@ -24,10 +24,10 @@
 
 import Log
 import Config
-import Image
+from PIL import Image
 import pygame
 import StringIO
-import PngImagePlugin
+from PIL import PngImagePlugin
 from OpenGL.GL import *
 from OpenGL.GLU import *
 from Queue import Queue, Empty
