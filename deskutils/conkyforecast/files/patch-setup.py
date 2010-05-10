--- setup.py.orig	2010-01-07 05:02:45.000000000 +0700
+++ setup.py	2010-05-07 23:16:08.000000000 +0800
@@ -46,7 +46,6 @@
 			('/usr/share/conkyforecast/', [ 'conkyForecast.pot' ] ),
 			('/usr/share/conkyforecast/', [ 'conkyForecast.config' ] ),
 			('/usr/share/conkyforecast/example', listfiles( 'example', '*' ) ),
-			('/usr/share/fonts/truetype/conkyforecast', listfiles( 'fonts', '*' ) ),
 			('/usr/share/conkyforecast/images/bearingicons', listfiles( 'images/bearingicons', '*' ) ),
 			('/usr/share/conkyforecast/images/moonicons', listfiles( 'images/moonicons', '*' ) ),
 			('/usr/share/conkyforecast/images/weathericons', listfiles( 'images/weathericons', '*' ) ),
