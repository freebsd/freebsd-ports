--- src/installml.sh.orig	2019-08-03 17:29:51 UTC
+++ src/installml.sh
@@ -52,18 +52,6 @@ if test $what = "install" -a \( -f $destdir/$vimname.1
       /bin/sh install-sh -c -d $destdir
    fi
 
-   # ex
-   if test ! -f $destdir/$exname.1 -a -f $destdir/$vimname.1; then
-      echo creating link $destdir/$exname.1
-      cd $destdir; ln -s $vimname.1 $exname.1
-   fi
-
-   # view
-   if test ! -f $destdir/$viewname.1 -a -f $destdir/$vimname.1; then
-      echo creating link $destdir/$viewname.1
-      cd $destdir; ln -s $vimname.1 $viewname.1
-   fi
-
    # rvim
    if test ! -f $destdir/$rvimname.1 -a -f $destdir/$vimname.1; then
       echo creating link $destdir/$rvimname.1
@@ -119,14 +107,6 @@ fi
 if test $what = "uninstall"; then
    echo Checking for Vim manual page links in $destdir...
 
-   if test -L $destdir/$exname.1; then
-      echo deleting $destdir/$exname.1
-      rm -f $destdir/$exname.1
-   fi
-   if test -L $destdir/$viewname.1; then
-      echo deleting $destdir/$viewname.1
-      rm -f $destdir/$viewname.1
-   fi
    if test -L $destdir/$rvimname.1; then
       echo deleting $destdir/$rvimname.1
       rm -f $destdir/$rvimname.1
