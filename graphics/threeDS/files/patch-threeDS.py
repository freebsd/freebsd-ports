
$FreeBSD$

--- threeDS.py	2001/01/18 19:26:14	1.1
+++ threeDS.py	2001/01/18 19:26:19
@@ -82,7 +82,7 @@
         self.imgfile = readStr(f)
 #        print "texture: " + self.imgfile
         try: 
-          from Imaging import Image
+          from PIL import Image
         except: 
           print 'Can\'t load texture without PIL!!'
           continue
@@ -370,7 +370,8 @@
 
   def __init__(self, filename):
     (path, filename) = os.path.split(filename)
-    os.chdir(path)
+    if path != '':
+      os.chdir(path)
     f = open(filename, "rb")
     if f is None:
       print "error loading " + str(filename) + "."
