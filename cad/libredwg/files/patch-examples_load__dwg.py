--- examples/load_dwg.py.orig	2020-01-16 22:20:43 UTC
+++ examples/load_dwg.py
@@ -1,7 +1,7 @@
 #! /usr/bin/python
 
 #import libredwg
-from libredwg import *
+from LibreDWG import *
 
 import sys
 
@@ -15,7 +15,7 @@ a.object = new_Dwg_Object_Array(1000)
 error = dwg_read_file(filename, a)
 
 if (error > 0): # critical errors
-    print "Error: ", error
+    print("Error: ", error)
     if (error > 127):
         exit()
 
