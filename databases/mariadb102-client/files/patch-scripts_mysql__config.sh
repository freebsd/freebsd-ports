--- scripts/mysql_config.sh.orig	2017-05-21 07:34:41 UTC
+++ scripts/mysql_config.sh
@@ -106,7 +106,9 @@ fi
 
 # Create options 
 libs="-L$pkglibdir @RPATH_OPTION@ @LIBS_FOR_CLIENTS@"
+libs="$libs -L/usr/local/lib "
 embedded_libs="-L$pkglibdir @RPATH_OPTION@ @EMB_LIBS_FOR_CLIENTS@"
+embedded_libs="$embedded_libs -L/usr/local/lib "
 
 include="-I$pkgincludedir"
 if [ "$basedir" != "/usr" ]; then
