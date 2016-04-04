--- pefile.py.orig	2016-03-28 18:56:29 UTC
+++ pefile.py
@@ -5303,7 +5303,7 @@ class PE(object):
     # [ Microsoft Portable Executable and Common Object File Format Specification ]
     # "The alignment factor (in bytes) that is used to align the raw data of sections in
     #  the image file. The value should be a power of 2 between 512 and 64 K, inclusive.
-    #  The default is 512. If the SectionAlignment is less than the architecture’s page
+    #  The default is 512. If the SectionAlignment is less than the architecture's page
     #  size, then FileAlignment must match SectionAlignment."
     #
     # The following is a hard-coded constant if the Windows loader
