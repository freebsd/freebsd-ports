--- aclocal.m4.orig	Wed Apr 28 21:47:24 2004
+++ aclocal.m4	Sat Jul 31 16:24:17 2004
@@ -2773,7 +2773,7 @@
         CFLAGS="-g -O2 $CFLAGS"
       fi
     else
-      CFLAGS="-O2 $CFLAGS"
+      CFLAGS="$CFLAGS"
     fi
   fi
 
@@ -2815,7 +2815,7 @@
       if test "$CXX" = "KCC"; then
         CXXFLAGS="+K3 $CXXFLAGS"
       else
-        CXXFLAGS="-O2 $CXXFLAGS"
+        CXXFLAGS="$CXXFLAGS"
       fi  
     fi
   fi
