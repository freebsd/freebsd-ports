--- src/net/MakeLand.h.orig	2010-12-20 21:12:31 UTC
+++ src/net/MakeLand.h
@@ -31,13 +31,13 @@
  //regardless of mask. 021102
 
 #define ML_SHIFT 10
-int *MakeLand_bmpHeights;
-int *MakeLand_bmpColors;
-int MakeLand_Width;
-int MakeLand_Height;
-int MakeLand_InternallyGeneratedBitapsFlag;
+extern int *MakeLand_bmpHeights;
+extern int *MakeLand_bmpColors;
+extern int MakeLand_Width;
+extern int MakeLand_Height;
+extern int MakeLand_InternallyGeneratedBitapsFlag;
 typedef int (*MAKELAND_USER_CALLBACK) (int message);    //declaration usage: USER_CALLBACK pUserCallback;
-MAKELAND_USER_CALLBACK MakeLand_UserCallback;
+extern MAKELAND_USER_CALLBACK MakeLand_UserCallback;
 
  /////////////////////////////
  //creates the color and heights bitmap:
