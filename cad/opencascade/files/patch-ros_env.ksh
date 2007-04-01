--- ./ros/env.ksh.orig	Wed Mar 21 22:14:25 2007
+++ ./ros/env.ksh	Wed Mar 21 23:37:24 2007
@@ -1,17 +1,19 @@
 #!/bin/ksh -f
 
-export CASROOT=/usr/ports/cad/opencascade/work/opencascade-6.2/ros
+export CASROOT=%%CASROOT%%
 OS_NAME=`uname`
 if [ -z "PATH" ];
-then PATH=$CASROOT/../3rdparty/$OS_NAME/tcltk/bin:$CASROOT/$OS_NAME/bin;
-else PATH=$CASROOT/../3rdparty/$OS_NAME/tcltk/bin:$CASROOT/$OS_NAME/bin:$PATH;
+then PATH=%%LOCALBASE%%/bin:$CASROOT/$OS_NAME/bin;
+else PATH=%%LOCALBASE%%/bin:$CASROOT/$OS_NAME/bin:$PATH;
 fi
 export PATH
-if [ -z "LD_LIBRARY_PATH" ];
-then LD_LIBRARY_PATH=$CASROOT/../3rdparty/$OS_NAME/tcltk/lib:$CASROOT/$OS_NAME/lib;
-else LD_LIBRARY_PATH=$CASROOT/../3rdparty/$OS_NAME/tcltk/lib:$CASROOT/$OS_NAME/lib:$LD_LIBRARY_PATH;
+if [ $OS_NAME != "FreeBSD" ]; then
+  if [ -z "LD_LIBRARY_PATH" ];
+  then LD_LIBRARY_PATH $CASROOT/../3rdparty/$OS_NAME/tcltk/lib:$CASROOT/$OS_NAME/lib;
+  else LD_LIBRARY_PATH $CASROOT/../3rdparty/$OS_NAME/tcltk/lib:$CASROOT/$OS_NAME/lib:$LD_LIBRARY_PATH;
+  fi
+  export LD_LIBRARY_PATH
 fi
-export LD_LIBRARY_PATH
 export CSF_MDTVFontDirectory=$CASROOT/src/FontMFT
 export CSF_LANGUAGE=us
 export MMGT_CLEAR=1
@@ -30,7 +32,7 @@
 export CSF_STEPDefaults=$CASROOT/src/XSTEPResource
 export CSF_XmlOcafResource=$CASROOT/src/XmlOcafResource
 
-export TCLHOME=$CASROOT/../3rdparty/$OS_NAME/tcltk
+export TCLHOME=%%LOCALBASE%%
 export TCLLIBPATH=$TCLHOME/lib
 if [ $OS_NAME = "SunOS" ]; then
       export ITK_LIBRARY=$TCLLIBPATH/itk3.2
@@ -38,6 +40,12 @@
       export TIX_LIBRARY=$TCLLIBPATH/tix8.1
       export TK_LIBRARY=$TCLLIBPATH/tk8.4
       export TCL_LIBRARY=$TCLLIBPATH/tcl8.4;
+elif [ $OS_NAME = "FreeBSD" ]; then
+      export ITK_LIBRARY=$TCLLIBPATH/itk%%ITKMM%%
+      export ITCL_LIBRARY=$TCLLIBPATH/itcl%%ITCLMM%%
+      export TIX_LIBRARY=$TCLLIBPATH/tix%%TIX_MM%%
+      export TK_LIBRARY=%%TK_LIBDIR%%
+      export TCL_LIBRARY=%%TCL_LIBDIR%%
 elif [ $OS_NAME = "Linux" ]; then
       export ITK_LIBRARY=$TCLLIBPATH/itk3.2
       export ITCL_LIBRARY=$TCLLIBPATH/itcl3.2
