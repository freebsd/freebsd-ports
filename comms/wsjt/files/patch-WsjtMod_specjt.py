--- WsjtMod/specjt.py.orig	2011-09-13 12:56:59.000000000 -0700
+++ WsjtMod/specjt.py	2015-01-09 04:04:37.000000000 -0800
@@ -11,13 +11,9 @@
 import cPickle
 import tkMessageBox
 
-try:
-    from numpy.oldnumeric import zeros, multiarray
-#    print "specjt importing from numpy"
-except:
-    from Numeric import zeros, multiarray
-#    print "specjt importing from Numeric"
-import Image, ImageTk, ImageDraw
+from numpy import zeros
+from numpy.core import multiarray
+from PIL import Image, ImageTk, ImageDraw
 from palettes import colormapblue, colormapgray0, colormapHot, \
      colormapAFMHot, colormapgray1, colormapLinrad, Colormap2Palette
 #import wsjt                         #Is this OK to do?
@@ -76,7 +72,7 @@
 ttot=0.0
 
 c=Canvas()
-a=zeros(225000,'s')
+a=zeros(225000,'uint16')
 im=Image.new('P',(750,300))
 line0=Image.new('P',(750,1))      #Image fragment for top line of waterfall
 draw=ImageDraw.Draw(im)
@@ -330,11 +326,14 @@
             except:
                 print "Images did not match, continuing anyway."
             for i in range(n):
-                line0.putdata(a[750*i:750*(i+1)])   #One row of pixels to line0
+                for j in range(0, 749):
+                    line0.putpixel((j,0), a[750*i+j])
                 im.paste(line0,(0,i))               #Paste in new top line
             nscroll=nscroll+n
         else:                                   #A scale factor has changed
-            im.putdata(a)                       #Compute whole new image
+            for i in range(0, 300):
+                for j in range(0, 749):
+                    im.putpixel((j,i), a[750*i+j])
             b0=brightness                       #Save scale values
             c0=contrast
             logm0=logm
