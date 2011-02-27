--- pokerth_game.pro.orig	2011-01-16 20:37:12.000000000 +0100
+++ pokerth_game.pro	2011-02-15 17:46:10.218078631 +0100
@@ -379,8 +379,7 @@
 	# QMAKE_LFLAGS += -Wl,--gc-sections
 	LIBPATH += lib $${PREFIX}/lib /opt/gsasl/lib
 	INCLUDEPATH += $${PREFIX}/include
-	LIB_DIRS = $${PREFIX}/lib \
-		$${PREFIX}/lib64
+	LIB_DIRS = $${PREFIX}/lib
 	BOOST_FS = boost_filesystem \
 		boost_filesystem-mt
 	BOOST_THREAD = boost_thread \
@@ -392,7 +391,7 @@
 	BOOST_SYS = boost_system \
 		boost_system-mt
 
-	# searching in $PREFIX/lib and $PREFIX/lib64
+	# searching in $PREFIX/lib
 	# to override the default '/usr' pass PREFIX
 	# variable to qmake.
 	for(dir, LIB_DIRS):exists($$dir) {
