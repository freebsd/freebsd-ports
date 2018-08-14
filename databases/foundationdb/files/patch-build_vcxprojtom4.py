--- build/vcxprojtom4.py.orig	2018-08-14 14:24:41 UTC
+++ build/vcxprojtom4.py
@@ -23,8 +23,8 @@
 import sys
 
 if len(sys.argv) != 2:
-    print """Usage:
-  %s [input]""" % sys.argv[0]
+    print("""Usage:
+  %s [input]""" % sys.argv[0])
     sys.exit()
 
 vcxproj = sys.argv[1]
@@ -34,7 +34,7 @@ from xml.dom.minidom import parse
 try:
     dom = parse(vcxproj)
 except:
-    print "ERROR: Unable to open VCXProj file %s" % vcxproj
+    print("ERROR: Unable to open VCXProj file %s" % vcxproj)
     sys.exit()
 
 # We need to find out what kind of project/configuration we're going
@@ -49,19 +49,19 @@ for group in groups:
         configType = ctnodes[0].childNodes[0].data
         break
 
-print "define(`GENCONFIGTYPE', `%s')dnl" % configType
+print("define(`GENCONFIGTYPE', `%s')dnl" % configType)
 
 if configType == "StaticLibrary":
-    print "define(`GENTARGET', `lib/lib`'GENNAME.a')dnl"
-    print "define(`GENOUTDIR', `lib')dnl"
+    print("define(`GENTARGET', `lib/lib`'GENNAME.a')dnl")
+    print("define(`GENOUTDIR', `lib')dnl")
 elif configType == "DynamicLibrary":
-    print "define(`GENTARGET', `lib/lib`'GENNAME.$(DLEXT)')dnl"
-    print "define(`GENOUTDIR', `lib')dnl"
+    print("define(`GENTARGET', `lib/lib`'GENNAME.$(DLEXT)')dnl")
+    print("define(`GENOUTDIR', `lib')dnl")
 elif configType == "Application":
-    print "define(`GENTARGET', `bin/'`GENNAME')dnl"
-    print "define(`GENOUTDIR', `bin')dnl"
+    print("define(`GENTARGET', `bin/'`GENNAME')dnl")
+    print("define(`GENOUTDIR', `bin')dnl")
 else:
-    print "ERROR: Unable to determine configuration type"
+    print("ERROR: Unable to determine configuration type")
     sys.exit()
 
 sources = [node.getAttribute("Include").replace('\\', '/') for node in
@@ -70,4 +70,4 @@ sources = [node.getAttribute("Include").
            dom.getElementsByTagName("ClInclude")
            if not node.getElementsByTagName("ExcludedFromBuild") and node.hasAttribute("Include")]
 
-print "define(`GENSOURCES', `%s')dnl" % ' '.join(sorted(sources))
+print("define(`GENSOURCES', `%s')dnl" % ' '.join(sorted(sources)))
