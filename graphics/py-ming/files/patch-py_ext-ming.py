--- py_ext/ming.py.orig	2015-05-15 09:43:14 UTC
+++ py_ext/ming.py
@@ -112,57 +112,57 @@ class SWFFilter(SWFBase):
         if type == SWFFILTER_TYPE_DROPSHADOW:
             #color, blur, shadow, flags
             if not isinstance(arg2, SWFBlur):
-                raise AttributeError, "3. parameter has to be SWFBlur"
+                raise AttributeError("3. parameter has to be SWFBlur")
             if not isinstance(arg3, SWFShadow):
-                raise AttributeError, "4. parameter has to be SWFShadow"
+                raise AttributeError("4. parameter has to be SWFShadow")
             self.this = mingc.newDropShadowFilter(arg1, arg2.this, arg3.this, arg4)
         elif type == SWFFILTER_TYPE_BLUR:
             #blur
             if not isinstance(arg1, SWFBlur):
-                raise AttributeError, "2. parameter has to be SWFBlur"
+                raise AttributeError("2. parameter has to be SWFBlur")
             self.this = mingc.newBlurFilter(arg1.this)
         elif type == SWFFILTER_TYPE_GLOW:
             #color, blur, strength, flags
             if not isinstance(arg2, SWFBlur):
-                raise AttributeError, "3. parameter has to be SWFBlur"
+                raise AttributeError("3. parameter has to be SWFBlur")
             self.this = mingc.newGlowFilter(arg1, arg2.this, arg3, arg4)
-	elif type == SWFFILTER_TYPE_BEVEL:
+        elif type == SWFFILTER_TYPE_BEVEL:
             #shadowColor, highlightColor, blur, shadow, flags
             if not isinstance(arg3, SWFBlur):
-                raise AttributeError, "4. parameter has to be SWFBlur"
+                raise AttributeError("4. parameter has to be SWFBlur")
             if not isinstance(arg4, SWFShadow):
-                raise AttributeError, "5. parameter has to be SWFShadow"
+                raise AttributeError("5. parameter has to be SWFShadow")
             self.this = mingc.newBevelFilte(arg1, arg2, arg3.this, arg4.this, arg5)
-	elif type == SWFFILTER_TYPE_GRADIENTGLOW:
+        elif type == SWFFILTER_TYPE_GRADIENTGLOW:
             #gradient, blur, shadow, flags
             if not isinstance(arg1, SWFGradient):
-                raise AttributeError, "2. parameter has to be SWFGradient"
+                raise AttributeError("2. parameter has to be SWFGradient")
             if not isinstance(arg2, SWFBlur):
-                raise AttributeError, "3. parameter has to be SWFBlur"
+                raise AttributeError("3. parameter has to be SWFBlur")
             if not isinstance(arg3, SWFShadow):
-                raise AttributeError, "4. parameter has to be SWFShadow"
+                raise AttributeError("4. parameter has to be SWFShadow")
             self.this = mingc.newGradienGlowFilter(arg1.this, arg2.this, arg3.this, arg4)
         elif type == SWFFILTER_TYPE_COLORMATRIX:
             #colormatrix
             if not isinstance(arg1, SWFFilterMatrix):
-                raise AttributeError, "2. parameter has to be SWFFilterMatrix"
+                raise AttributeError("2. parameter has to be SWFFilterMatrix")
             self.this = mingc.newColorMatrixFilter(arg1.this)
-	elif type == SWFFILTER_TYPE_CONVOLUTION:
+        elif type == SWFFILTER_TYPE_CONVOLUTION:
             #colormatrix, divisor, bias, color, flags
             if not isinstance(arg1, SWFFilterMatrix):
-                raise AttributeError, "2. parameter has to be SWFFilterMatrix"
+                raise AttributeError("2. parameter has to be SWFFilterMatrix")
             self.this = mingc.newConvolutionFilter(arg1.this, arg2, arg3, arg4, arg5)
         elif type == SWFFILTER_TYPE_GRADIENTBEVEL:
             #gradient, blur, shadow, flags
             if not isinstance(arg1, SWFGradient):
-                raise AttributeError, "2. parameter has to be SWFGradient"
+                raise AttributeError("2. parameter has to be SWFGradient")
             if not isinstance(arg2, SWFBlur):
-                raise AttributeError, "3. parameter has to be SWFBlur"
+                raise AttributeError("3. parameter has to be SWFBlur")
             if not isinstance(arg3, SWFShadow):
-                raise AttributeError, "4. parameter has to be SWFShadow"
+                raise AttributeError("4. parameter has to be SWFShadow")
             self.this = mingc.newGradientBevelFilter(arg1.this, arg2.this, arg3.this, arg4)
-	else:
-            raise AttributeError, "bad filter type to SWFFilter::new"
+        else:
+            raise AttributeError("bad filter type to SWFFilter::new")
 
 class SWFMatrix(SWFBase):
     
@@ -230,7 +230,7 @@ class SWFShape(SWFBase):
             return SWFFill(mingc.SWFShape_addBitmapFill(self.this, arg1.this, arg2))
 
         else:
-            raise AttributeError, "bad argument to SWFShape::addFill"
+            raise AttributeError("bad argument to SWFShape::addFill")
 
     def setLeftFill(self, fill):
         mingc.SWFShape_setLeftFill(self.this, fill)
@@ -455,29 +455,29 @@ class SWFDisplayItem(SWFBase):
         mingc.SWFDisplayItem_setMaskLevel(self.this, level)
 
     def getPositionX(self):
-	x = mingc.new_floatp()
-	y = mingc.new_floatp()
-	mingc.SWFDisplayItem_getPosition(self.this, x, y)
-	ret = mingc.floatp_value(x)
-	mingc.delete_floatp(x)
-	mingc.delete_floatp(y)
-	return ret
+        x = mingc.new_floatp()
+        y = mingc.new_floatp()
+        mingc.SWFDisplayItem_getPosition(self.this, x, y)
+        ret = mingc.floatp_value(x)
+        mingc.delete_floatp(x)
+        mingc.delete_floatp(y)
+        return ret
 
     def getPositionY(self):
-	x = mingc.new_floatp()
-	y = mingc.new_floatp()
-	mingc.SWFDisplayItem_getPosition(self.this, x, y)
-	ret = mingc.floatp_value(y)
-	mingc.delete_floatp(x)
-	mingc.delete_floatp(y)
-	return ret
+        x = mingc.new_floatp()
+        y = mingc.new_floatp()
+        mingc.SWFDisplayItem_getPosition(self.this, x, y)
+        ret = mingc.floatp_value(y)
+        mingc.delete_floatp(x)
+        mingc.delete_floatp(y)
+        return ret
 
     def getRotation(self):
         rot = mingc.new_floatp()
-	mingc.SWFDisplayItem_getRotation(self.this, rot)
-	ret = mingc.floatp_value(rot)
-	mingc.delete_floatp(rot)
-	return ret
+        mingc.SWFDisplayItem_getRotation(self.this, rot)
+        ret = mingc.floatp_value(rot)
+        mingc.delete_floatp(rot)
+        return ret
 
     def getScaleX(self):
         sx = mingc.new_floatp()
@@ -525,7 +525,7 @@ class SWFDisplayItem(SWFBase):
         return SWFMatrix(mingc.SWFDisplayItem_getMatrix(self.this))
 
     def setCXform(self, cx):
-	mingc.SWFDisplayItem_setCXform(self.this, cx.this);
+        mingc.SWFDisplayItem_setCXform(self.this, cx.this);
          
     def addFilter(self, filter):
         mingc.SWFDisplayItem_addFilter(self.this, filter.this)
@@ -644,8 +644,8 @@ class SWFMovie(SWFBase):
         mingc.SWFMovie_writeExports(self.this)
 
     def assignSymbol(self, character, name):
-	mingc.SWFMovie_assignSymbol(self.this, character.this, name)
-	
+        mingc.SWFMovie_assignSymbol(self.this, character.this, name)
+
     def setNetworkAccess(self, flag):
         mingc.SWFMovie_setNetworkAccess(self.this, flag)
 
@@ -1205,12 +1205,12 @@ SWFVIDEOSTREAM_MODE_MANUAL = mingc.SWFVI
 
 class SWFVideoStream(SWFBase):
     def __init__(self, filename=None):
-	if filename is None:
-		self.file = 0;
-        	self.this = mingc.newSWFVideoStream()
-	else:
-		self.file = open(filename, "rb");
-        	self.this = mingc.newSWFVideoStream_fromFile(self.file)
+        if filename is None:
+            self.file = 0;
+            self.this = mingc.newSWFVideoStream()
+        else:
+            self.file = open(filename, "rb");
+            self.this = mingc.newSWFVideoStream_fromFile(self.file)
     def setDimension(self, w, h):
         return mingc.SWFVideoStream_setDimension(self.this, w, h)
     def getNumFrames(self):
