--- acinclude.m4.orig	2008-05-03 05:22:57 UTC
+++ acinclude.m4
@@ -45,7 +45,7 @@ AC_ARG_ENABLE(openexr-threads,[  --enable-openexr-thre
   if test "x$enable_static_openexr" == "xyes"; then
     OPENEXR_LIBS="$X_LIBS $openexr_static_libs"
   else
-    OPENEXR_LIBS="$X_LIBS -lIlmImf -lImath -lIex -lHalf -lz"
+    OPENEXR_LIBS="$X_LIBS -lOpenEXR -lIex -lImath -lz"
   fi
 
   AC_MSG_CHECKING(for OpenEXR)
@@ -142,10 +142,10 @@ AC_ARG_ENABLE(static-fltk,[  --enable-static-fltk Spec
   if test x$FLTK_CONFIG != xno ; then
   	if test x$STATIC_FLTK != xtrue ; then
   	    FLTK_CXXFLAGS="`$FLTK_CONFIG --use-gl --cxxflags`"
-    	FLTK_LDFLAGS="`$FLTK_CONFIG --use-gl --ldstaticflags`"
+    	FLTK_LDFLAGS="`$FLTK_CONFIG --use-gl --ldstaticflags | sed 's/ -R.* / /g'`"
   	else
 	    FLTK_CXXFLAGS="`$FLTK_CONFIG --use-gl --cxxflags`"
-    	FLTK_LDFLAGS="`$FLTK_CONFIG --use-gl --ldflags`"
+    	FLTK_LDFLAGS="`$FLTK_CONFIG --use-gl --ldflags | sed 's/ -R.* / /g'`"
     fi
   else
     FLTK_CXXFLAGS=""
