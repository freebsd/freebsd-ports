--- src/wrapxerces.cpp.orig	2013-11-21 15:51:13.000000000 +0100
+++ src/wrapxerces.cpp	2013-11-21 16:01:41.000000000 +0100
@@ -201,12 +201,12 @@
 		return wxConvUTF8;
 	case 2:
 	{
-		const static wxMBConvUTF16 conv;
+		static wxMBConvUTF16 conv;
 		return conv;
 	}
 	case 4:
 	{
-		const static wxMBConvUTF32 conv;
+		static wxMBConvUTF32 conv;
 		return conv;
 	}
 	default:
