--- global-tags/create_global_tags.sh.in.orig	Sun Jul  8 03:39:26 2007
+++ global-tags/create_global_tags.sh.in	Sun Jul  8 03:41:12 2007
@@ -68,9 +68,9 @@ if ( [ ! -z $PKG_CONFIG ] && [ -x $PKG_C
 	## the packages, which we don't like. We only want cflags relevent
 	## to the packages alone.
 	##
-    PKG_DEFAULT_CONFIG_PATH=`echo $PKG_CONFIG | sed -e 's/\/bin\/pkg-config/\/lib\/pkgconfig'/`
+    PKG_DEFAULT_CONFIG_PATH=`echo $PKG_CONFIG | sed -e 's/\/bin\/pkg-config/\/libdata\/pkgconfig'/`
     PKG_CONFIG_PATH="$PKG_CONFIG_PATH:$PKG_DEFAULT_CONFIG_PATH"
-    PKG_DEFAULT_CONFIG_PATH=`echo $PKG_CONFIG | sed -e 's/\/bin\/pkg-config/\/lib64\/pkgconfig'/`
+    PKG_DEFAULT_CONFIG_PATH=`echo $PKG_CONFIG | sed -e 's/\/bin\/pkg-config/\/lib\/pkgconfig'/`
     PKG_CONFIG_PATH="$PKG_CONFIG_PATH:$PKG_DEFAULT_CONFIG_PATH"
 	
     PKG_CONFIG_PATH_PROPER=`echo $PKG_CONFIG_PATH | sed -e 's/\:/ /g'`
@@ -88,7 +88,7 @@ if ( [ ! -z $PKG_CONFIG ] && [ -x $PKG_C
     for pkg_path in $PKG_CONFIG_PATH_PROPER; do
 	for pkg_file in `find "$pkg_path" -name '*.pc' 2>/dev/null`; do
 		# echo "Scanning package: $pkg_file"
-	    PKG_CFLAGS=`grep -e '^\(\w\+=\|\s*Cflags:\)' "$pkg_file"|sed -e 's/Cflags:\s*"\?\(.*\)"\?\s*/echo "\1"/' -e 's/^\(\w\+\)=\("\([^"]*\)"\|\(.*\)\)/\1="\3\4"/'|sh`
+	    PKG_CFLAGS=`grep -E -e '^([a-zA-Z0-9_]+=|[[:space:]]*Cflags:)' "$pkg_file"|sed -E -e 's/Cflags:[[:space:]]*"?(.*)"?[[:space:]]*/echo "\1"/' -e 's/^([a-zA-Z0-9_]+)=("([^"]*)"|(.*))/\1="\3\4"/'|sh`
 		# echo $PKG_CFLAGS
 	    package=`basename "$pkg_file" '.pc'`
 	    # if [ ! -e $BASEDIR/tags/$package.anjutatags.gz ] ; then
