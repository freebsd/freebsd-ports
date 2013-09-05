--- pokerth_game.pro.orig	2013-04-07 14:04:26.923209000 +0200
+++ pokerth_game.pro	2013-09-05 12:07:44.416793690 +0200
@@ -407,8 +407,7 @@
 	LIBPATH += lib
 	!android{
 		LIBPATH += $${PREFIX}/lib /opt/gsasl/lib
-		LIB_DIRS = $${PREFIX}/lib \
-			$${PREFIX}/lib64
+		LIB_DIRS = $${PREFIX}/lib
 	}
 	android{
 		LIBPATH += $${PREFIX}/lib/armv5
@@ -427,7 +426,7 @@
 	BOOST_RANDOM = boost_random \
 		boost_random-mt
 
-	# searching in $PREFIX/lib and $PREFIX/lib64
+	# searching in $PREFIX/lib
 	# to override the default '/usr' pass PREFIX
 	# variable to qmake.
 	for(dir, LIB_DIRS):exists($$dir) {
@@ -501,7 +500,7 @@
 		LIBS += -lSDL \
 				-lSDL_mixer \
 			-lgsasl
-		!isEmpty( BSD ):isEmpty( kFreeBSD ):LIBS += -lcrypto
+		!isEmpty( BSD ):isEmpty( kFreeBSD ):LIBS += -lcrypto -lssl
 		else:LIBS += -lgcrypt
 	}
 	android{
