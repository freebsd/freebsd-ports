--- makeversion.py.orig	2006-02-12 19:47:01 UTC
+++ makeversion.py
@@ -37,15 +37,13 @@
 # ouput:
 #   include/aboutmsg.h
 
-import sys, re, string, os
+import sys, re, string, os, platform
 
-import svn
-
 def get_version():
   # version
   f = open('include/version.default', 'r')
   buffer = f.read()
-  line = string.split(buffer, '\n')[0]
+  line = buffer.split('\n')[0]
   f.close()
   sys.stdout.write("version: %s\n" % line)
   exp = re.compile('^1\\.([^\\.]*)\\.([0-9]*)')
@@ -68,12 +66,9 @@ def radiant_makeversion(append_about):
   f = open('include/RADIANT_MAJOR', 'w')
   f.write(major)
   f.close()
-  f = open('include/version', 'w')
-  f.write(line)
-  f.close()
   # aboutmsg
   aboutfile = 'include/aboutmsg.default'
-  if ( os.environ.has_key('RADIANT_ABOUTMSG') ):
+  if ( 'RADIANT_ABOUTMSG' in os.environ ):
     aboutfile = os.environ['RADIANT_ABOUTMSG']
   line = None
   if os.path.isfile(aboutfile):
@@ -82,7 +77,7 @@ def radiant_makeversion(append_about):
     line = f.readline()
     f.close()
   else:
-    line = "Custom build based on revision " + str(svn.getRevision(os.getcwd()))
+    line = "Custom build for %s (%s)" % (platform.system(), platform.machine())
   # optional additional message
   if ( not append_about is None ):
     line += append_about
