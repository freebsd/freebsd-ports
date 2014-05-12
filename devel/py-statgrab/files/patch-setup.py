--- ./setup.py.orig	2014-05-10 23:15:23.105771349 +0100
+++ ./setup.py	2014-05-10 23:16:18.509761277 +0100
@@ -39,12 +39,12 @@
 	sys.exit("Error, could not find pkg-config.")
 
 # test for libstatgrab presence using pkg-config
-if os.system("pkg-config --exists libstatgrab"):
-	sys.exit("Error, libstatgrab is not installed (according to pkg-config).")
+if os.system("pkg-config --exists libstatgrab0"):
+	sys.exit("Error, libstatgrab0 is not installed (according to pkg-config).")
 
 # test for libstatgrab version using pkg-config
-if os.system("pkg-config --atleast-version=%s libstatgrab" % LIBSTATGRAB):
-	sys.exit("Error, need at least libstatgrab version %s." % LIBSTATGRAB)
+if os.system("pkg-config --atleast-version=%s libstatgrab0" % LIBSTATGRAB):
+	sys.exit("Error, need at least libstatgrab0 version %s." % LIBSTATGRAB)
 
 # test for _statgrab.c, and try to generate if not found
 if not os.path.exists("_statgrab.c"):
@@ -56,8 +56,8 @@
 			sys.exit("Error, pyrexc failed to generate _statgrab.c")
 
 # get cflags and libs for libstatgrab
-cflags = getstatusoutput("pkg-config --cflags libstatgrab")
-libs = getstatusoutput("pkg-config --libs libstatgrab")
+cflags = getstatusoutput("pkg-config --cflags libstatgrab0")
+libs = getstatusoutput("pkg-config --libs libstatgrab0")
 
 if cflags[0] != 0:
 	sys.exit("Failed to get cflags: " + cflags[1])
