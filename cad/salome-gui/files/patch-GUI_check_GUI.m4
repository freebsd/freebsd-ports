--- adm_local/unix/config_files/check_GUI.m4.orig	2009-08-15 21:44:17.000000000 +0700
+++ adm_local/unix/config_files/check_GUI.m4	2009-08-15 21:44:37.000000000 +0700
@@ -59,7 +59,7 @@
   SalomeGUI_ok=yes
   AC_MSG_RESULT(Using SALOME GUI distribution in ${SALOME_GUI_DIR})
 
-  if test "x${GUI_ROOT_DIR}" == "x" ; then
+  if test "x${GUI_ROOT_DIR}" = "x" ; then
     GUI_ROOT_DIR=${SALOME_GUI_DIR}
   fi
 
