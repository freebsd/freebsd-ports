--- macros/python.m4.orig	2015-05-15 09:43:14 UTC
+++ macros/python.m4
@@ -94,8 +94,8 @@ AC_DEFUN([AC_PYTHON_DEVEL],[
 	#
 	AC_MSG_CHECKING([for a version of Python >= '2.1.0'])
 	ac_supports_python_ver=`$PYTHON -c "import sys, string; \
-		ver = string.split(sys.version)[[0]]; \
-		print ver >= '2.1.0'"`
+		ver = sys.version.split(); \
+		print(ver[[0]] >= '2.1.0')"`
 	if test "$ac_supports_python_ver" != "True"; then
 		if test -z "$PYTHON_NOVERSIONCHECK"; then
 			AC_MSG_RESULT([no])
@@ -121,8 +121,8 @@ to something else than an empty string.
 	if test -n "$1"; then
 		AC_MSG_CHECKING([for a version of Python $1])
 		ac_supports_python_ver=`$PYTHON -c "import sys, string; \
-			ver = string.split(sys.version)[[0]]; \
-			print ver $1"`
+			ver = sys.version.split(); \
+			print(ver[[0]], $1)"`
 		if test "$ac_supports_python_ver" = "True"; then
 	   	   AC_MSG_RESULT([yes])
 		else
@@ -157,7 +157,7 @@ $ac_distutils_result])
 	AC_MSG_CHECKING([for Python include path])
 	if test -z "$PYTHON_CPPFLAGS"; then
 		python_path=`$PYTHON -c "import distutils.sysconfig; \
-           		print distutils.sysconfig.get_python_inc();"`
+           		print(distutils.sysconfig.get_python_inc());"`
 		if test -n "${python_path}"; then
 		   	python_path="-I$python_path"
 		fi
@@ -174,21 +174,19 @@ $ac_distutils_result])
 		# (makes two attempts to ensure we've got a version number
 		# from the interpreter)
 		py_version=`$PYTHON -c "from distutils.sysconfig import *; \
-			from string import join; \
-			print join(get_config_vars('VERSION'))"`
+			print(' '.join(get_config_vars('VERSION')))"`
 		if test "$py_version" = "[None]"; then
 			if test -n "$PYTHON_VERSION"; then
 				py_version=$PYTHON_VERSION
 			else
 				py_version=`$PYTHON -c "import sys; \
-					print sys.version[[:3]]"`
+					print(sys.version[[:3]])"`
 			fi
 		fi
 
 		PYTHON_LDFLAGS=`$PYTHON -c "from distutils.sysconfig import *; \
-			from string import join; \
-			print '-L' + get_python_lib(0,1), \
-		      	'-lpython';"`$py_version
+			print('-L', get_python_lib(0,1), \
+		      	'-lpython');"`$py_version
 	fi
 	AC_MSG_RESULT([$PYTHON_LDFLAGS])
 	AC_SUBST([PYTHON_LDFLAGS])
@@ -199,7 +197,7 @@ $ac_distutils_result])
 	AC_MSG_CHECKING([for Python site-packages path])
 	if test -z "$PYTHON_SITE_PKG"; then
 		PYTHON_SITE_PKG=`$PYTHON -c "import distutils.sysconfig; \
-		        print distutils.sysconfig.get_python_lib(0,0);"`
+		        print(distutils.sysconfig.get_python_lib(0,0));"`
 	fi
 	AC_MSG_RESULT([$PYTHON_SITE_PKG])
 	AC_SUBST([PYTHON_SITE_PKG])
@@ -211,7 +209,7 @@ $ac_distutils_result])
 	if test -z "$PYTHON_EXTRA_LIBS"; then
 	   PYTHON_EXTRA_LIBS=`$PYTHON -c "import distutils.sysconfig; \
                 conf = distutils.sysconfig.get_config_var; \
-                print conf('LOCALMODLIBS'), conf('LIBS')"`
+                print(conf('LOCALMODLIBS'), conf('LIBS'))"`
 	fi
 	AC_MSG_RESULT([$PYTHON_EXTRA_LIBS])
 	AC_SUBST(PYTHON_EXTRA_LIBS)
@@ -223,7 +221,7 @@ $ac_distutils_result])
 	if test -z "$PYTHON_EXTRA_LDFLAGS"; then
 		PYTHON_EXTRA_LDFLAGS=`$PYTHON -c "import distutils.sysconfig; \
 			conf = distutils.sysconfig.get_config_var; \
-			print conf('LINKFORSHARED')"`
+			print(conf('LINKFORSHARED'))"`
 	fi
 	AC_MSG_RESULT([$PYTHON_EXTRA_LDFLAGS])
 	AC_SUBST(PYTHON_EXTRA_LDFLAGS)
