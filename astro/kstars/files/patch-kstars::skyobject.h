--- kstars/skyobject.h.orig	Mon Dec 17 18:06:52 2001
+++ kstars/skyobject.h	Mon Dec 17 18:07:06 2001
@@ -101,7 +101,7 @@
 /**
 	*Return translated name
 	*/
-	QString translatedName() { return i18n(name.utf8().data());}
+	QString translatedName() { return i18n(name.local8Bit().data());}
 /**
   *Return the local time that the object will rise
   *@param jd  current Julian date
