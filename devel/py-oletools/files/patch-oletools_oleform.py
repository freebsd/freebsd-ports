--- oletools/oleform.py.orig	2018-02-19 16:28:01 UTC
+++ oletools/oleform.py
@@ -118,7 +118,7 @@ def consume_TextProps(stream):
 def consume_GuidAndFont(stream):
     # GuidAndFont: [MS-OFORMS] 2.4.7
     UUIDS = stream.unpacks('<LHH', 8) + stream.unpacks('>Q', 8)
-    if UUIDS == (199447043, 36753, 4558, 11376937813817407569L):
+    if UUIDS == (199447043, 36753, 4558, 11376937813817407569):
         # UUID == {0BE35203-8F91-11CE-9DE300AA004BB851}
         # StdFont: [MS-OFORMS] 2.4.12
         stream.check_value('StdFont (version)', '<B', 1, 1)
@@ -126,7 +126,7 @@ def consume_GuidAndFont(stream):
         stream.read(9)
         bFaceLen = stream.unpack('<B', 1)
         stream.read(bFaceLen)
-    elif UUIDS == (2948729120, 55886, 4558, 13349514450607572916L):
+    elif UUIDS == (2948729120, 55886, 4558, 13349514450607572916):
         # UUID == {AFC20920-DA4E-11CE-B94300AA006887B4}
         consume_TextProps(stream)
     else:
@@ -136,7 +136,7 @@ def consume_GuidAndPicture(stream):
     # GuidAndPicture: [MS-OFORMS] 2.4.8
     # UUID == {0BE35204-8F91-11CE-9DE3-00AA004BB851}
     stream.check_values('GuidAndPicture (UUID part 1)', '<LHH', 8, (199447044, 36753, 4558))
-    stream.check_value('GuidAndPicture (UUID part 1)', '>Q', 8, 11376937813817407569L)
+    stream.check_value('GuidAndPicture (UUID part 1)', '>Q', 8, 11376937813817407569)
     # StdPicture: [MS-OFORMS] 2.4.13
     stream.check_value('StdPicture (Preamble)', '<L', 4, 0x0000746C)
     size = stream.unpack('<L', 4)
