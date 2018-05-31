--- build/csprojtom4.py.orig	2018-05-31 02:58:48 UTC
+++ build/csprojtom4.py
@@ -1,5 +1,5 @@
 #!/usr/local/bin/python2.7
-#
+#i
 # csprojtom4.py
 #
 # This source file is part of the FoundationDB open source project
@@ -23,8 +23,8 @@
 import sys
 
 if len(sys.argv) != 2:
-    print """Usage:
-  %s [input]""" % sys.argv[0]
+    print("""Usage:
+  %s [input]""" % sys.argv[0])
     sys.exit()
 
 csproj = sys.argv[1]
@@ -34,20 +34,20 @@ from xml.dom.minidom import parse
 try:
     dom = parse(csproj)
 except:
-    print "ERROR: Unable to open CSProj file %s" % csproj
+    print("ERROR: Unable to open CSProj file %s" % csproj)
     sys.exit()
 
 outputType = dom.getElementsByTagName("OutputType")[0].childNodes[0].data
 assemblyName = dom.getElementsByTagName("AssemblyName")[0].childNodes[0].data
 
 if outputType == "Exe":
-    print "define(`GENTARGET', `bin/%s.exe')dnl" % assemblyName
-    print "define(`GENOUTPUTTYPE', `exe')dnl"
+    print("define(`GENTARGET', `bin/%s.exe')dnl" % assemblyName)
+    print("define(`GENOUTPUTTYPE', `exe')dnl")
 elif outputType == "Library":
-    print "define(`GENTARGET', `bin/%s.dll')dnl" % assemblyName
-    print "define(`GENOUTPUTTYPE', `library')dnl"
+    print("define(`GENTARGET', `bin/%s.dll')dnl" % assemblyName)
+    print("define(`GENOUTPUTTYPE', `library')dnl")
 else:
-    print "ERROR: Unable to determine output type"
+    print("ERROR: Unable to determine output type")
     sys.exit()
 
 sources = [node.getAttribute("Include").replace('\\', '/') for node in
@@ -55,5 +55,5 @@ sources = [node.getAttribute("Include").replace('\\', 
 assemblies = [node.getAttribute("Include") for node in
               dom.getElementsByTagName("Reference")]
 
-print "define(`GENSOURCES', `%s')dnl" % ' '.join(sources)
-print "define(`GENREFERENCES', `%s')dnl" % ','.join(assemblies)
+print("define(`GENSOURCES', `%s')dnl" % ' '.join(sources))
+print("define(`GENREFERENCES', `%s')dnl" % ','.join(assemblies))
