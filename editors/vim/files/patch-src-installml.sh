--- src/installml.sh.orig	2015-05-14 03:56:21 UTC
+++ src/installml.sh
@@ -53,16 +53,16 @@ if test $what = "install" -a \( -f $dest
    fi
 
    # ex
-   if test ! -f $destdir/$exname.1 -a -f $destdir/$vimname.1; then
-      echo creating link $destdir/$exname.1
-      cd $destdir; ln -s $vimname.1 $exname.1
-   fi
+   #if test ! -f $destdir/$exname.1 -a -f $destdir/$vimname.1; then
+   #   echo creating link $destdir/$exname.1
+   #   cd $destdir; ln -s $vimname.1 $exname.1
+   #fi
 
    # view
-   if test ! -f $destdir/$viewname.1 -a -f $destdir/$vimname.1; then
-      echo creating link $destdir/$viewname.1
-      cd $destdir; ln -s $vimname.1 $viewname.1
-   fi
+   #if test ! -f $destdir/$viewname.1 -a -f $destdir/$vimname.1; then
+   #   echo creating link $destdir/$viewname.1
+   #   cd $destdir; ln -s $vimname.1 $viewname.1
+   #fi
 
    # rvim
    if test ! -f $destdir/$rvimname.1 -a -f $destdir/$vimname.1; then
@@ -119,14 +119,14 @@ fi
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
+   #if test -L $destdir/$exname.1; then
+   #   echo deleting $destdir/$exname.1
+   #   rm -f $destdir/$exname.1
+   #fi
+   #if test -L $destdir/$viewname.1; then
+   #   echo deleting $destdir/$viewname.1
+   #   rm -f $destdir/$viewname.1
+   #fi
    if test -L $destdir/$rvimname.1; then
       echo deleting $destdir/$rvimname.1
       rm -f $destdir/$rvimname.1
