--- scripts/release.pl.orig	2019-12-06 12:02:59 UTC
+++ scripts/release.pl
@@ -182,8 +182,8 @@ run( "cp debian/changelog /tmp", "backup changelog fai
 unless( $dopoint ) {
 	run( "perl -i -pe 's/qgis-dev-deps/qgis-ltr-deps/;' doc/msvc.t2t", "could not update osgeo4w deps package" ) if $doltr;
 	run( "perl -i -pe 's/qgis-dev-deps/qgis-rel-deps/;' doc/msvc.t2t", "could not update osgeo4w deps package" ) unless $doltr;
-	run( "txt2tags --encoding=utf-8 -odoc/INSTALL.html -t html doc/INSTALL.t2t", "could not update INSTALL.html" );
-	run( "txt2tags --encoding=utf-8 -oINSTALL -t txt doc/INSTALL.t2t", "could not update INSTALL" );
+	run( "txt2tags -odoc/INSTALL.html -t html doc/INSTALL.t2t", "could not update INSTALL.html" );
+	run( "txt2tags -oINSTALL -t txt doc/INSTALL.t2t", "could not update INSTALL" );
 
 	run( "cp -v images/splash/splash-$newmajor.$newminor.png images/splash/splash.png", "splash png switch failed" );
 	run( "convert -resize 164x314 ms-windows/Installer-Files/WelcomeFinishPage-$newmajor.$newminor.png BMP3:ms-windows/Installer-Files/WelcomeFinishPage.bmp", "installer bitmap switch failed" );
