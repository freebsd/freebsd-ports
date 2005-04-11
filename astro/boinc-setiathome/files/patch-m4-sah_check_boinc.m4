--- m4/sah_check_boinc.m4.orig	Fri Dec 24 17:40:58 2004
+++ m4/sah_check_boinc.m4	Tue Mar  1 11:27:23 2005
@@ -18,29 +18,6 @@
   fi
   thisdir=`pwd`
   AC_MSG_CHECKING([for BOINC])
-  boinc_search_path="$BOINCDIR boinc ../boinc $HOME/boinc /usr/local/boinc /usr/local/lib/boinc /opt/misc/boinc /opt/misc/lib/boinc $2"
-  for boinc_dir in $boinc_search_path
-  do
-    if test -d $boinc_dir 
-    then
-      if test -f $boinc_dir/Makefile.am 
-      then
-        cd $boinc_dir
-        BOINCDIR=`pwd`
-	cd $thisdir
-	break
-      else
-        if $FIND $boinc_dir -name "Makefile.am" >& /dev/null
-	then
-	  BOINCDIR=`$FIND $boinc_dir -name "Makefile.am" -print | $HEAD -1 | sed 's/\/Makefile.am//'`         
-          cd $BOINCDIR
-          BOINCDIR=`pwd`
-	  cd $thisdir
-	  break
-	fi
-      fi
-    fi
-  done
   if test -n "$BOINCDIR" 
   then
     AC_MSG_RESULT($BOINCDIR)
@@ -56,13 +33,13 @@
   AC_SUBST([PROJECTDIR])
   AC_SUBST([BOINCDIR])
   save_libs="$LIBS"
-  RSADIR="$BOINCDIR/RSAEuro"
-  LIBS="$LIBS -L$RSADIR/source"
-  AC_CHECK_LIB([rsaeuro],[RSAPublicEncrypt],[RSALIBS="-L$RSADIR/source -lrsaeuro"])
+  RSADIR="$BOINCDIR"
+  LIBS="$LIBS -L$RSADIR"
+  AC_CHECK_LIB([rsaeuro],[RSAPublicEncrypt],[RSALIBS="-L$RSADIR -lrsaeuro"])
   LIBS="$save_libs"
-  BOINC_CFLAGS="-I$BOINCDIR/api -I$BOINCDIR/lib"
+  BOINC_CFLAGS="-I$BOINCDIR/include/BOINC"
   AC_SUBST([BOINC_CFLAGS])
-  RSA_CFLAGS="-I$RSADIR/source"
+  RSA_CFLAGS="-I$BOINCDIR/include/BOINC"
   AC_SUBST([RSA_CFLAGS])
   AC_SUBST([RSADIR])
   AC_SUBST([RSALIBS])
