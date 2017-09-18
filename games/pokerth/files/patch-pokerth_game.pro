--- pokerth_game.pro.orig	2014-01-10 21:18:20 UTC
+++ pokerth_game.pro
@@ -406,9 +406,7 @@ unix:!mac { 
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
@@ -427,7 +425,7 @@ unix:!mac { 
 	BOOST_RANDOM = boost_random \
 		boost_random-mt
 
-	# searching in $PREFIX/lib, $PREFIX/lib64 and $$system(qmake -query QT_INSTALL_LIBS)
+	# searching in $PREFIX/lib
 	# to override the default '/usr' pass PREFIX
 	# variable to qmake.
 	for(dir, LIB_DIRS):exists($$dir) {
@@ -501,7 +499,7 @@ unix:!mac { 
 		LIBS += -lSDL \
 				-lSDL_mixer \
 			-lgsasl
-		!isEmpty( BSD ):isEmpty( kFreeBSD ):LIBS += -lcrypto
+		!isEmpty( BSD ):isEmpty( kFreeBSD ):LIBS += -lcrypto -lssl
 		else:LIBS += -lgcrypt
 	}
 	android{
