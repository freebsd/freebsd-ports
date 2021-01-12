--- m4/ax_python.m4.orig	2018-04-16 02:40:31 UTC
+++ m4/ax_python.m4
@@ -18,10 +18,13 @@ AC_ARG_WITH(python2,
 has_python3=false
 AC_ARG_WITH(python3,
     [  --with-python3           will use $PYTHON to find python],
-    [
+    [if test $withval == "no"
+     then
+       has_python3=false
+     else
        has_python=true
        has_python3=true
-    ],
+    fi],
     has_python3=false
 )
 
@@ -54,10 +57,10 @@ fi
 
 if test $has_python3 = true
 then
-    PYTHON3_INCLUDE_PATH=[`python3 -c 'from distutils import sysconfig; print( sysconfig.get_python_inc(1) )'`]
+    PYTHON3_INCLUDE_PATH=[`python3.7 -c 'from distutils import sysconfig; print( sysconfig.get_python_inc(1) )'`]
     PYTHON3_CFLAGS="-I${PYTHON3_INCLUDE_PATH}"
     AC_SUBST(PYTHON3_CFLAGS)
-    PYTHON3_SITE_PACKAGES=[`python3 -c 'from distutils import sysconfig; print( sysconfig.get_python_lib(1) )'`]
+    PYTHON3_SITE_PACKAGES=[`python3.7 -c 'from distutils import sysconfig; print( sysconfig.get_python_lib(1) )'`]
     AC_SUBST(PYTHON3_SITE_PACKAGES)
     AC_DEFINE(HAVE_PYTHON3, 1, Define if you have python3)
 fi
