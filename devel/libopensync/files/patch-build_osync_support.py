Significant whitespace considered harmful...
--- build/osync_support.py.orig	2007-06-21 14:38:39.000000000 +0200
+++ build/osync_support.py	2008-03-09 19:32:41.000000000 +0100
@@ -54,7 +54,7 @@
 			else:
 				# bad, nothing is available, tell the user
 				print "No build directories found for your platform '%s'" % platform
-			return None
+				return None
 
 	print "Found directory %s, will build there" % target_dir
 	return target_dir
