--- m4/build.m4.orig	2021-07-01 21:41:53 UTC
+++ m4/build.m4
@@ -94,7 +94,7 @@ $BFD_CFLAGS -pipe -Wall -fexceptions $OPT_CFLAGS $DEBU
   else if test "x$target_mingw32" = "xyes"; then
       FLDIGI_BUILD_LDADD="$FLDIGI_BUILD_LDADD -lsetupapi -lhid"
     else
-      FLDIGI_BUILD_LDADD="$FLDIGI_BUILD_LDADD -ludev"
+      FLDIGI_BUILD_LDADD="$FLDIGI_BUILD_LDADD"
     fi
   fi
 
