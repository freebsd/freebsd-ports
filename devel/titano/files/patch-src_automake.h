--- src/automake.h.orig	Sat Dec 16 13:07:24 2000
+++ src/automake.h	Thu Apr  7 20:00:08 2005
@@ -65,6 +65,11 @@
 	{
 		return target.name != str;
 	};
+
+	friend bool operator==(const Target &target,const string &str)
+	{
+		return target.name == str;
+	};
 };
 
 class Makefile
