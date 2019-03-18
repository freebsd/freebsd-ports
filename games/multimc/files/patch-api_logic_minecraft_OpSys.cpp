--- api/logic/minecraft/OpSys.cpp.orig	2019-03-09 16:23:18 UTC
+++ api/logic/minecraft/OpSys.cpp
@@ -17,6 +17,8 @@
 
 OpSys OpSys_fromString(QString name)
 {
+	if (name == "freebsd")
+		return Os_FreeBSD;
     if (name == "linux")
         return Os_Linux;
     if (name == "windows")
@@ -30,6 +32,8 @@ QString OpSys_toString(OpSys name)
 {
     switch (name)
     {
+	case Os_FreeBSD:
+		return "freebsd";
     case Os_Linux:
         return "linux";
     case Os_OSX:
@@ -39,4 +43,4 @@ QString OpSys_toString(OpSys name)
     default:
         return "other";
     }
-}
\ No newline at end of file
+}
