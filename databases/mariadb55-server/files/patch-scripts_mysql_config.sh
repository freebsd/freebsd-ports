--- scripts/mysql_config.sh.orig	2014-04-15 14:02:39.000000000 +0300
+++ scripts/mysql_config.sh	2014-05-16 19:08:41.000000000 +0300
@@ -108,8 +108,11 @@
 # We intentionally add a space to the beginning and end of lib strings, simplifies replace later
 libs=" $ldflags -L$pkglibdir @RPATH_OPTION@ -lmysqlclient @ZLIB_DEPS@ @NON_THREADED_LIBS@"
 libs="$libs @openssl_libs@ @STATIC_NSS_FLAGS@ "
+libs="$libs -L%%LOCALBASE%%/lib "
 libs_r=" $ldflags -L$pkglibdir  @RPATH_OPTION@ -lmysqlclient_r @ZLIB_DEPS@ @CLIENT_LIBS@ @openssl_libs@ "
+libs_r="$libs_r -L%%LOCALBASE%%/lib "
 embedded_libs=" $ldflags -L$pkglibdir @RPATH_OPTION@ -lmysqld @LIBDL@ @ZLIB_DEPS@ @LIBS@ @WRAPLIBS@ @openssl_libs@ "
+embedded_libs="$embedded_libs -L%%LOCALBASE%%/lib "
 
 if [ -r "$pkglibdir/libmygcc.a" ]; then
   # When linking against the static library with a different version of GCC
