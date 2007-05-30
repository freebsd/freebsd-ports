--- setup.py.orig	Sat Mar 17 13:21:04 2007
+++ setup.py	Mon May 28 17:01:45 2007
@@ -112,7 +112,7 @@
         
     
     # Compile KDTree ? Not compiled by default
-    print "\n*** Bio.KDTree *** NOT built by default "
+#    print "\n*** Bio.KDTree *** NOT built by default "
     kdtree_msg = """
 The Bio.PDB.NeighborSearch module depends on the Bio.KDTree module,
 which in turn, depends on C++ code that does not compile cleanly on
@@ -120,14 +120,14 @@
 
 Would you like to build Bio.KDTree ?"""
 
-    if get_yes_or_no (kdtree_msg, 0):
-        NUMPY_PACKAGES.append("Bio.KDTree")
-        NUMPY_EXTENSIONS.append(
-            CplusplusExtension('Bio.KDTree._CKDTree', 
-                               ["Bio/KDTree/KDTree.cpp",
-                                "Bio/KDTree/KDTree.swig.cpp"],
-                               libraries=["stdc++"],
-                               language="c++"))
+#    if get_yes_or_no (kdtree_msg, 0):
+    NUMPY_PACKAGES.append("Bio.KDTree")
+    NUMPY_EXTENSIONS.append(
+        CplusplusExtension('Bio.KDTree._CKDTree', 
+                           ["Bio/KDTree/KDTree.cpp",
+                            "Bio/KDTree/KDTree.swig.cpp"],
+                           libraries=["stdc++"],
+                           language="c++"))
     
     
     return 1
