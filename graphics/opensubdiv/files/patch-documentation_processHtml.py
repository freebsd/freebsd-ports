--- documentation/processHtml.py.orig	2018-07-18 02:17:49 UTC
+++ documentation/processHtml.py
@@ -25,9 +25,11 @@
 
 import os
 import sys
-import string
 import re
-import HTMLParser
+try:
+    import HTMLParser
+except:
+    import html.parser as HTMLParser
 
 class HtmlToTextParser(HTMLParser.HTMLParser):
     def __init__(self):
@@ -89,10 +91,10 @@ def ReadNavigationTemplate( filePath ):
     try:
         navFile = open( filePath, "r")
     except IOError:
-        print "Could not open file \'"+filePath+"\'"
+        print("Could not open file \'"+filePath+"\'")
     
     with navFile:
-        print "Navigation template: \'"+filePath+"\'"
+        print("Navigation template: \'"+filePath+"\'")
         navHtml = navFile.read()
         navHtml = StripHTMLComments(navHtml)
         navFile.close()
@@ -109,7 +111,7 @@ def WriteIndexFile( outputFile, content ):
     except:
         pass
 
-    print "Creating Search-Index File : \""+outputFile+"\""
+    print("Creating Search-Index File : \""+outputFile+"\"")
 
     f = open(outputFile, "w")
     f.write(content)
@@ -117,7 +119,7 @@ def WriteIndexFile( outputFile, content ):
 
 #-------------------------------------------------------------------------------
 def Usage():
-    print str(sys.argv[0])+" <input directory> <output directory> <html template>"
+    print(str(sys.argv[0])+" <input directory> <output directory> <html template>")
     exit(1);
 
 
@@ -132,7 +134,7 @@ navTemplate = str(sys.argv[2])
     
 navHtml = ReadNavigationTemplate( navTemplate )
 
-print "Scanning : \'"+rootDir+"\'"
+print("Scanning : \'"+rootDir+"\'")
 
 searchIndex = 'var tipuesearch = { "pages": [ '
 
@@ -172,22 +174,22 @@ for root, dirs, files in os.walk(rootDir):
 
             # if necessary, insert navigation html
             if (not parser.HasNavigationSection()):
-                loc = string.find(html,"<body>")
+                loc = html.find("<body>")
                 html = html[:loc+6] + navHtml + html[loc+6:]
 
                 msg += "added navigation"
 
             # replace the article title placeholder with the real title
             if title:
-                html = string.replace(html,"OSD_ARTICLE_TITLE", title)
+                html = html.replace("OSD_ARTICLE_TITLE", title)
             else:
-                html = string.replace(html,"OSD_ARTICLE_TITLE", "")
+                html = html.replace("OSD_ARTICLE_TITLE", "")
 
             f.seek(0)
             f.write(html)
             f.close()
 
-            print msg
+            print(msg)
 
 searchIndex = searchIndex + "]};"
 
