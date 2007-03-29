--- detect.py.orig	Fri Apr 23 05:21:08 2004
+++ detect.py	Wed Mar 28 22:49:07 2007
@@ -49,35 +49,11 @@
 
 def check_libdl(libdata):
 
-	print "Checking for libdl...";
-	dl_search_dirs=[ \
-		"/sw", \
-		"/usr", \
-		"/usr/local", \
-	];
-
-	# search for extra include dirs to add
-	for x in dl_search_dirs:
-		if (os.path.isfile(x + "/include/dlfcn.h")):
-			print "Found dlfcn.h in " + x + "/include";
-			libdata.dl_flags=["-I" + x + "/include"];
-			break;
-
-	f=open("test.cpp","w");
-	f.write("#include <dlfcn.h>\n#include <stdio.h>\nint main() { printf(\"Testing dlfcn.\"); return 0; }\n");
-	f.close();
-
-	for x in dl_search_dirs:
-		execline="c++ -L" + x + "/lib " + libdata.dl_flags[0] + " test.cpp -o test -ldl 2>>config_errors.log";
-		res=os.system(execline);
+	libdata.dl_libs=[''];
+	libdata.dl_flags=[''];
+	libdata.dl_link_flags=[''];
 
-		if (res == 0):
-			libdata.dl_libs=['dl'];
-			libdata.dl_link_flags=["-L" + x + "/lib"];
-			os.system("rm test.cpp");
-			os.system("rm test");
-			return 0;
-	return 1;
+	return 0;
 
 def check_alsa(libdata):
 
@@ -148,6 +124,7 @@
 
 	#list of dirs I can test..
 	qt_unix_library_dirs = [\
+		"%%QT_PREFIX%%/lib",\
 		"",\
 		"/usr/lib",\
 		"/usr/X11R6/lib",\
@@ -158,6 +135,7 @@
 	];
 
 	qt_unix_bin_dirs = [\
+		"%%QT_PREFIX%%/bin",\
                 "",\
 		"/usr/bin",\
 		"/usr/X11R6/bin",\
@@ -168,6 +146,7 @@
 	];
 
 	qt_unix_include_dirs = [\
+		"%%QT_PREFIX%%/include",\
 		"/usr/include",\
 		"/usr/include/qt3",\
 		"/usr/X11R6/include",\
@@ -271,7 +250,10 @@
 
 	print "Looking for QT 3.x 'moc' Binary:";
 
-	qt_found=0;
+	qt_found=1;
+	libdata.qt_link_flags="-L%%QT_PREFIX%%/lib"
+	libdata.qt_libs=['qt-mt'];
+	libdata.moc_bin="%%QT_PREFIX%%/bin/moc"
 
         for x in qt_unix_bin_dirs:
 		if (not qt_lib_found):
@@ -299,7 +281,6 @@
        		libdata.moc_bin=command;
 		break;
 
-
         if (not qt_found):
 		print("I Couldnt find QT in your system :(\n");
 		print("If you think it is actually installed, you could try the following:\n");
@@ -312,7 +293,6 @@
 	else:
 		print("QT was found!\n");
 		return 0;
-
 
 
 def check_system(libdata):
