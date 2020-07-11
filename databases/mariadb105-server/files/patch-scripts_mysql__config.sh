--- scripts/mysql_config.sh.orig	2020-07-11 14:16:47 UTC
+++ scripts/mysql_config.sh
@@ -88,6 +88,7 @@ fi
 # Create options 
 libs="-L$pkglibdir @RPATH_OPTION@ @LIBS_FOR_CLIENTS@"
 embedded_libs="-L$pkglibdir @RPATH_OPTION@ @EMB_LIBS_FOR_CLIENTS@"
+embedded_libs="$embedded_libs -L%%LOCALBASE%%/lib "
 
 include="-I$pkgincludedir"
 if [ "$basedir" != "/usr" ]; then
