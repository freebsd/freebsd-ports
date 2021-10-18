--- src/tools/partedit.py.orig	2021-10-18 09:08:43 UTC
+++ src/tools/partedit.py
@@ -72,9 +72,7 @@ def getAttrs(numAttributesFunc, attributeInfoFunc, sor
     numAttr = numAttributesFunc()
 
     nameToIndex = {attributeInfoFunc(anum).name:anum for anum in range(numAttr)}
-    names = nameToIndex.keys()
-    if sort:
-        names.sort()
+    names = sorted(nameToIndex) if sort else nameToIndex.keys()
 
     id_offset = 0
     for name in names:
