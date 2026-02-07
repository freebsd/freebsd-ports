--- gputest_gui.py.orig	2014-03-04 02:16:44 UTC
+++ gputest_gui.py
@@ -7,7 +7,7 @@
 
 import os
 #from subprocess import call
-import Tkinter as tk
+import tkinter as tk
 
 
 root = tk.Tk()
@@ -90,7 +90,7 @@ def prepare_command_line():
     index = cs[0]
     seltext = listbox1.get(index)
   else:
-    print "\nPlease select a test (FurMark is the default test)."
+    print("\nPlease select a test (FurMark is the default test).")
     index = 0
     seltext = listbox1.get(index)
   
@@ -98,7 +98,7 @@ def prepare_command_line():
   for demo in allDemos:
     if demo.demo_name == seltext:
       demo_code = demo.demo_code
-  g_command_line = "./GpuTest /test='%s' /width=%d /height=%d /gpumon_terminal" % (demo_code, g_width, g_height)
+  g_command_line = "gputest /test='%s' /width=%d /height=%d /gpumon_terminal" % (demo_code, g_width, g_height)
   if (fullscreen.get() == 1):
     g_command_line += " /fullscreen"
     
