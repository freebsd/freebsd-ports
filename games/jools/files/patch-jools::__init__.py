--- jools/__init__.py.orig	Sat Aug 30 20:04:03 2003
+++ jools/__init__.py	Sat Aug 30 20:04:32 2003
@@ -24,6 +24,7 @@
 # Primary game control loop.
 #
 
+import os, random, sys
 
 try:
    import pygame
@@ -31,7 +32,6 @@
    sys.exit("Jools requires Pygame, which does not appear to be installed.")
 
 
-import os, random, sys
 from pygame.locals import *
 
 from globals import *
