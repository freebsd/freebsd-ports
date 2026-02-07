--- setup.py.orig	2011-04-29 09:12:29 UTC
+++ setup.py
@@ -46,7 +46,6 @@ setup(
 			('/usr/share/conkyforecast/', [ 'conkyForecast.config' ] ),
 			('/usr/share/conkyforecast/', [ 'conkyForecast-SunsetSunriseCountdown.py' ] ),
 			('/usr/share/conkyforecast/example', listfiles( 'example', '*' ) ),
-			('/usr/share/fonts/truetype/conkyforecast', listfiles( 'fonts', '*' ) ),
 			('/usr/share/conkyforecast/images/bearingicons', listfiles( 'images/bearingicons', '*' ) ),
 			('/usr/share/conkyforecast/images/moonicons', listfiles( 'images/moonicons', '*' ) ),
 			('/usr/share/conkyforecast/images/weathericons', listfiles( 'images/weathericons', '*' ) ),
@@ -68,5 +67,7 @@ setup(
 			('/usr/share/conkyforecast/locale/zh/LC_MESSAGES', listfiles( 'locale/zh/LC_MESSAGES', '*' ) ),
 			('/usr/share/conkyforecast/test', listfiles( 'test', '*' ) )
 		],
+        # Declare packages explicitly so that setuptools does not attempt auto discovery
+        packages=[],
 	)
 
