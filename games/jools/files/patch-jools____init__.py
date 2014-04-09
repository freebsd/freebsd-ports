--- ./jools/__init__.py.orig	2003-08-26 20:17:01.000000000 +0200
+++ ./jools/__init__.py	2014-04-09 02:36:46.095493715 +0200
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
