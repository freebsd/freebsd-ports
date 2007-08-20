--- detect.py.orig	Mon Aug  6 21:04:11 2007
+++ detect.py	Mon Aug 20 16:41:41 2007
@@ -104,35 +104,11 @@
 
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
 
 def check_need_gmp(libdata):
 	print "Checking if GMP is needed...",
@@ -152,7 +128,9 @@
 		print "Checking if GMP is available...",
 		res = check_cpp_compile(
 			"#include <gmp.h>\n" +
-			"int main() {return 0;}\n", "-lgmp");
+			"int main() {\n" +
+			"	return 0;\n" +
+			"}\n", "-I%%LOCALBASE%%/include -L%%LOCALBASE%%/lib -lgmp");
 		if(res == 0):
 			print "No."
 			print "\n\n**** CANNOT FIND GMP LIBRARY ****\n\n";
@@ -213,7 +191,7 @@
 		"int main() {\n" +
 		"	afNewFileSetup();\n" +
 		"	return 0;\n" +
-		"}\n", "-laudiofile -lm");
+		"}\n", "-I%%LOCALBASE%%/include -L%%LOCALBASE%%/lib -laudiofile -lm");
 	if(res == 0):
 		print " no. Access to lots of file formats is lost.";
 		libdata.have_libaudiofile=0;
@@ -401,6 +379,7 @@
 
 	#list of dirs I can test..
 	qt_unix_library_dirs = [\
+		"%%QT_PREFIX%%/lib",\
 		"",\
 		"/usr/lib",\
 		"/usr/X11R6/lib",\
@@ -411,6 +390,7 @@
 	];
 
 	qt_unix_bin_dirs = [\
+		"%%QT_PREFIX%%/bin",\
                 "",\
 		"/usr/bin",\
 		"/usr/X11R6/bin",\
@@ -421,6 +401,7 @@
 	];
 
 	qt_unix_include_dirs = [\
+		"%%QT_PREFIX%%/include",\
 		"/usr/include",\
 		"/usr/include/qt3",\
 		"/usr/X11R6/include",\
@@ -524,7 +505,10 @@
 
 	print "Looking for QT 3.x 'moc' Binary:";
 
-	qt_found=0;
+	qt_found=1;
+	libdata.qt_link_flags="-L%%QT_PREFIX%%/lib"
+	libdata.qt_libs=['qt-mt'];
+	libdata.moc_bin="%%QT_PREFIX%%/bin/moc"
 
         for x in qt_unix_bin_dirs:
 		if (not qt_lib_found):
