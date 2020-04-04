--- pokerth_game.pro.orig	2017-08-16 12:24:03 UTC
+++ pokerth_game.pro
@@ -409,10 +409,7 @@ unix:!mac { 
 	QMAKE_LIBDIR += lib
 	!android{
 		LIBPATH += $${PREFIX}/lib /opt/gsasl/lib
-		LIB_DIRS = $${PREFIX}/lib \
-			$${PREFIX}/lib64 \
-                        $${PREFIX}/lib/x86_64-linux-gnu \
-			$$system(qmake -query QT_INSTALL_LIBS)
+		LIB_DIRS = $${PREFIX}/lib
 	}
 	android{
 		LIBPATH += $${PREFIX}/lib/armv7
@@ -433,7 +430,7 @@ unix:!mac { 
 	BOOST_CHRONO = boost_chrono \
 		boost_chrono-mt
 
-	# searching in $PREFIX/lib, $PREFIX/lib64 and $$system(qmake -query QT_INSTALL_LIBS)
+	# searching in $PREFIX/lib
 	# to override the default '/usr' pass PREFIX
 	# variable to qmake.
 	for(dir, LIB_DIRS):exists($$dir) {
@@ -529,7 +526,7 @@ unix:!mac { 
 		LIBS += -lSDL \
 				-lSDL_mixer \
 			-lgsasl
-		!isEmpty( BSD ):isEmpty( kFreeBSD ):LIBS += -lcrypto
+		!isEmpty( BSD ):isEmpty( kFreeBSD ):LIBS += -lcrypto -lssl
 		else:LIBS += -lgcrypt
 	}
 	android{
