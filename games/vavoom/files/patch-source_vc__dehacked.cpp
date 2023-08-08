--- source/vc_dehacked.cpp.orig	2022-12-31 03:37:54 UTC
+++ source/vc_dehacked.cpp
@@ -128,8 +128,8 @@ static const VDehFlag DehFlags[] =
 	{ 0, "TRANSLUC75", 0x20000000 },
 	{ 0, "STEALTH", 0x40000000 },
 	{ 0, "UNUSED4", 0x40000000 },
-	{ 0, "TRANSLUCENT", 0x80000000 },
-	{ 0, "TRANSLUC50", 0x80000000 },
+	{ 0, "TRANSLUCENT", (int)0x80000000 },
+	{ 0, "TRANSLUC50", (int)0x80000000 },
 	{ 1, "LOGRAV", 0x00000001 },
 	{ 1, "WINDTHRUST", 0x00000002 },
 	{ 1, "FLOORBOUNCE", 0x00000004 },
@@ -161,7 +161,7 @@ static const VDehFlag DehFlags[] =
 	{ 1, "DORMANT", 0x10000000 },
 	{ 1, "ICEDAMAGE", 0x20000000 },
 	{ 1, "SEEKERMISSILE", 0x40000000 },
-	{ 1, "REFLECTIVE", 0x80000000 },
+	{ 1, "REFLECTIVE", (int)0x80000000 },
 	//	Ignored flags
 	{ 0, "SLIDE", 0 },
 	{ 0, "UNUSED2", 0 },
