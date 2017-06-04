--- source/vc_dehacked.cpp.orig	2017-06-04 08:35:41.777968000 +0200
+++ source/vc_dehacked.cpp	2017-06-04 09:13:52.864992000 +0200
@@ -128,8 +128,8 @@
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
@@ -161,7 +161,7 @@
 	{ 1, "DORMANT", 0x10000000 },
 	{ 1, "ICEDAMAGE", 0x20000000 },
 	{ 1, "SEEKERMISSILE", 0x40000000 },
-	{ 1, "REFLECTIVE", 0x80000000 },
+	{ 1, "REFLECTIVE", (int)0x80000000 },
 	//	Ignored flags
 	{ 0, "SLIDE", 0 },
 	{ 0, "UNUSED2", 0 },
