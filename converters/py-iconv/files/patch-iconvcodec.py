--- iconvcodec.py.orig	Sat Dec 22 08:04:10 2001
+++ iconvcodec.py	Sat Dec 22 08:04:31 2001
@@ -3,11 +3,7 @@
 # First we need to find out what the Unicode code set name is
 # in this iconv implementation
 
-if sys.platform.startswith("linux"):
-    unicodename = "unicode"+sys.byteorder
-else:
-    # may need to try UCS-2, UCS-2-LE/BE, Unicode, ...
-    raise ImportError,"cannot establish name of 2-byte Unicode"
+unicodename = "ucs-2-internal"
 
 class Codec(codecs.Codec):
     def __init__(self):
