# Many thanks to Franz Klammer <klammer@webonaut.com> for help
# and create this patch.

--- GoodWeather/__init__.py.orig	Tue Nov 18 16:38:53 2003
+++ GoodWeather/__init__.py	Tue Nov 18 16:40:14 2003
@@ -151,7 +151,14 @@
                 fh = urllib.urlopen(self.WEATHER_SOURCE % vars())
                 data = fh.read()
    
-                weather = parseGoodWeatherData(data) 
+                #weather = parseGoodWeatherData(data)
+                data_error = re.search(r'''(<error>)''', data)
+                if not data_error:
+                   weather = parseGoodWeatherData(data)
+                else:
+                   time.sleep(1)
+                   continue
+
                 metric = 0
                 if (units == self.CELSIUS): 
                    metric = 1 
