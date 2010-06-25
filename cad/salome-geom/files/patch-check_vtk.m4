--- adm_local/unix/config_files/check_vtk.m4.orig	2009-12-01 20:59:03.000000000 +0600
+++ adm_local/unix/config_files/check_vtk.m4	2010-06-18 14:18:42.000000000 +0700
@@ -94,18 +94,18 @@
 if test -z $vtk_suffix ; then
   vtk_suffix="yes"
 fi
-if test "x$vtk_suffix" == "xno" ; then
+if test "x$vtk_suffix" = "xno" ; then
   dnl in case user wrote --with-vtk-version=no, use empty suffix
   vtk_suffix=""
 fi
-if test "x$vtk_suffix" != "xyes" ; then
-  VTKSUFFIX="$vtk_suffix"
-else
-  dnl in case user wrote --with-vtk-version=yes, get the suffix from env
-  if test -z $VTKSUFFIX ; then
-    VTKSUFFIX="-5.0"
-  fi
-fi
+#if test "x$vtk_suffix" != "xyes" ; then
+#  VTKSUFFIX="$vtk_suffix"
+#else
+#  dnl in case user wrote --with-vtk-version=yes, get the suffix from env
+#  if test -z $VTKSUFFIX ; then
+#    VTKSUFFIX="-5.0"
+#  fi
+#fi
 
 dnl VTK install dir
 if test -z $with_vtk ; then
@@ -121,9 +121,9 @@
   AC_MSG_WARN(Value "no", specified for option --with-vtk, is not supported)
 fi
 
-if test "x$with_vtk" != "x" ; then
-  VTKHOME="$with_vtk"
-else
+#if test "x$with_vtk" != "x" ; then
+#  VTKHOME="$with_vtk"
+#else
   if test -z $VTKHOME ; then
     AC_MSG_WARN(undefined VTKHOME variable which specify where vtk was compiled)
     for d in /usr/local /usr ; do
@@ -144,6 +144,18 @@
         VTKSUFFIX="-5.2"
         break
       fi
+      if test -f ${d}/include/vtk-5.4/vtkPlane.h ; then
+        AC_MSG_RESULT(trying ${d})
+        VTKHOME="${d}"
+        VTKSUFFIX="-5.4"
+        break
+      fi
+      if test -f ${d}/include/vtk-5.6/vtkPlane.h ; then
+        AC_MSG_RESULT(trying ${d})
+        VTKHOME="${d}"
+        VTKSUFFIX="-5.6"
+        break
+      fi
       if test -f ${d}/include/vtk/vtkPlane.h ; then
         AC_MSG_RESULT(trying ${d})
         VTKHOME="${d}"
@@ -152,7 +164,7 @@
       fi
     done
   fi
-fi
+#fi
 
 # Using regular VTK installation
 if test "x$with_paraview" = "x" ; then
