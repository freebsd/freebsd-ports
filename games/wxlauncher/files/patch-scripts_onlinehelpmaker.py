--- scripts/onlinehelpmaker.py.orig	2015-08-26 04:54:06 UTC
+++ scripts/onlinehelpmaker.py
@@ -9,14 +9,14 @@ import string
 from optparse import OptionParser
 import logging
 NOTICE = 25 # added level for app
-import HTMLParser
+import html.parser
 
 try:
   import markdown
 except ImportError:
-  print "ERROR: Unable to import markdown the markup parser."
-  print " Make sure that markdown has been installed"
-  print "  see the ReadMe.txt for more information"
+  print("ERROR: Unable to import markdown the markup parser.")
+  print(" Make sure that markdown has been installed")
+  print("  see the ReadMe.txt for more information")
   raise
 
 from helpparsers import Stage2Parser, Stage3Parser, Stage4Parser, Stage5Parser
@@ -203,7 +203,7 @@ def generate_paths(options):
   for i in range(1, 7):
     paths['stage%d'%(i)] = os.path.join(options.temp, 'stage%d'%(i))
 
-  for path in paths.values():
+  for path in list(paths.values()):
     if not os.path.exists(path):
       logging.debug(" Making %s", path)
       os.makedirs(path)
@@ -304,9 +304,9 @@ def process_input_stage3(file, options, files, extrafi
   outfile = open(outname, mode="w")
 
   #figure out what subdirectory of the onlinehelp I am in
-  subdir = string.replace(os.path.dirname(outname), os.path.normpath(files['stage3']), "")
+  subdir = os.path.dirname(outname).replace(os.path.normpath(files['stage3']), "")
   if subdir.startswith(os.path.sep):
-    subdir = string.replace(subdir, os.path.sep, "", 1) # I only want to remove the leading sep
+    subdir = subdir.replace(os.path.sep, "", 1) # I only want to remove the leading sep
     
   parser = Stage3Parser(options, files, file=outfile, extrafiles=extrafiles, subdir=subdir)
   parser.feed(input)
@@ -325,9 +325,9 @@ def process_input_stage4(file, options, files):
   outfile = open(outname, mode="w")
   
   #figure out what subdirectory of the onlinehelp I am in
-  subdir = string.replace(os.path.dirname(outname), os.path.normpath(files['stage4']), "")
+  subdir = os.path.dirname(outname).replace(os.path.normpath(files['stage4']), "")
   if subdir.startswith(os.path.sep):
-    subdir = string.replace(subdir, os.path.sep, "", 1) # I only want to remove the leading sep
+    subdir = subdir.replace(os.path.sep, "", 1) # I only want to remove the leading sep
 
   parser = Stage4Parser(files=files, file=outfile, options=options,
                         subdir=subdir)
