--- pokerth_game.pro.orig	2013-12-22 17:58:01.933816000 +0100
+++ pokerth_game.pro	2013-12-23 12:19:53.142695431 +0100
@@ -406,9 +406,7 @@
 	QMAKE_LIBDIR += lib
 	!android{
 		LIBPATH += $${PREFIX}/lib /opt/gsasl/lib
-		LIB_DIRS = $${PREFIX}/lib \
-			$${PREFIX}/lib64 \
-			$$system(qmake -query QT_INSTALL_LIBS)
+		LIB_DIRS = $${PREFIX}/lib
 	}
 	android{
 		LIBPATH += $${PREFIX}/lib/armv7
@@ -427,7 +425,7 @@
 	BOOST_RANDOM = boost_random \
 		boost_random-mt
 
-	# searching in $PREFIX/lib, $PREFIX/lib64 and $$system(qmake -query QT_INSTALL_LIBS)
+	# searching in $PREFIX/lib
 	# to override the default '/usr' pass PREFIX
 	# variable to qmake.
 	for(dir, LIB_DIRS):exists($$dir) {
@@ -501,7 +499,7 @@
 		LIBS += -lSDL \
 				-lSDL_mixer \
 			-lgsasl
-		!isEmpty( BSD ):isEmpty( kFreeBSD ):LIBS += -lcrypto
+		!isEmpty( BSD ):isEmpty( kFreeBSD ):LIBS += -lcrypto -lssl
 		else:LIBS += -lgcrypt
 	}
 	android{
