--- GoodWeather/weather.py.orig	Thu Nov 20 16:29:11 2003
+++ GoodWeather/weather.py	Thu Nov 20 16:30:24 2003
@@ -321,8 +321,9 @@
         if m :
             #print m
             if m.upper() == 'AM':
-                if int(self._hour) > 11:
-                    raise ValueError ('AM hour can not be over 11 ['+ self._hour +']')
+                if int(self._hour) > 12:
+                    raise ValueError ('AM hour can not be over 12 ['+ self._hour +']')
+	        if int(self._hour) == 12: self._hour = str(0)
             if m.upper() == 'PM':
                 if int(self._hour) > 12:
                     raise ValueError ('PM hour can not be over 12 ['+ self._hour +']')
