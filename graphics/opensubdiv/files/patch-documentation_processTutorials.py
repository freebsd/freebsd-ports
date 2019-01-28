--- documentation/processTutorials.py.orig	2019-01-13 21:35:49 UTC
+++ documentation/processTutorials.py
@@ -33,7 +33,7 @@ def ReadFile(inputfile):
     try:
         f = open( inputfile, "r")
     except IOError:
-        print "Could not read file \'"+inputfile+"\'"
+        print("Could not read file \'"+inputfile+"\'")
     content = f.read()
     f.close()
     return content
@@ -48,7 +48,7 @@ def WriteToFile(outputfile, content):
     try:
         f = open(outputfile, "w")
     except IOError:
-        print "Could not write file \'"+outputfile+"\'"
+        print("Could not write file \'"+outputfile+"\'")
     f.write(content)
     f.close()
 
@@ -85,7 +85,7 @@ def Process(srcfile, title):
 
 #-------------------------------------------------------------------------------
 def Usage():
-    print str(sys.argv[0])+" <input file> <output file> <title>"
+    print(str(sys.argv[0])+" <input file> <output file> <title>")
     exit(1);
 
 
