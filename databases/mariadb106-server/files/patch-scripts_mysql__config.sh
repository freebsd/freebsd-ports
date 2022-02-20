--- scripts/mysql_config.sh.orig	2021-07-07 20:25:20 UTC
+++ scripts/mysql_config.sh
@@ -88,6 +88,7 @@ fi
 # Create options 
 libs="-L$pkglibdir @RPATH_OPTION@ @LIBS_FOR_CLIENTS@"
 embedded_libs="-L$pkglibdir @RPATH_OPTION@ @EMB_LIBS_FOR_CLIENTS@"
+embedded_libs="$embedded_libs -L/usr/local/lib "
 
 include="-I$pkgincludedir"
 if [ "$basedir" != "/usr" ]; then
