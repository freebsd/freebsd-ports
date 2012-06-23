--- pokerth_game.pro.orig	2012-06-21 22:54:48.000000000 +0200
+++ pokerth_game.pro	2012-06-22 11:47:32.047160533 +0200
@@ -392,8 +392,7 @@
 	LIBPATH += lib
 	!android{
 		LIBPATH += $${PREFIX}/lib /opt/gsasl/lib
-		LIB_DIRS = $${PREFIX}/lib \
-			$${PREFIX}/lib64
+		LIB_DIRS = $${PREFIX}/lib
 	}
 	android{
 		LIBPATH += $${PREFIX}/lib/armv5
@@ -412,7 +411,7 @@
 	BOOST_RANDOM = boost_random \
 		boost_random-mt
 
-	# searching in $PREFIX/lib and $PREFIX/lib64
+	# searching in $PREFIX/lib
 	# to override the default '/usr' pass PREFIX
 	# variable to qmake.
 	for(dir, LIB_DIRS):exists($$dir) {
