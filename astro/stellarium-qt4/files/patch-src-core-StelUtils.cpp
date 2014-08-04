--- src/core/StelUtils.cpp.orig	2013-08-04 14:20:27.000000000 +0800
+++ src/core/StelUtils.cpp	2013-10-19 19:37:56.000000000 +0800
@@ -1065,8 +1065,8 @@ double calculateSiderealPeriod(const dou
 QString hoursToHmsStr(const double hours)
 {
 	int h = (int)hours;
-	int m = (int)((std::abs(hours)-std::abs(h))*60);
-	float s = (((std::abs(hours)-std::abs(h))*60)-m)*60;
+	int m = (int)((std::abs(hours)-std::abs(double(h)))*60);
+	float s = (((std::abs(hours)-std::abs(double(h)))*60)-m)*60;
 
 	return QString("%1h%2m%3s").arg(h).arg(m).arg(QString::number(s, 'f', 1));
 }
