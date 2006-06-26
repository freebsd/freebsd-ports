--- installml.sh.orig	Sun Apr 30 08:48:53 2006
+++ installml.sh	Mon Jun 19 03:36:37 2006
@@ -55,12 +55,12 @@ if test $what = "install" -a \( -f $dest
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
 
@@ -121,10 +121,10 @@ if test $what = "uninstall"; then
 
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
