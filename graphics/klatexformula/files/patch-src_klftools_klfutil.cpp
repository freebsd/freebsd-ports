--- src/klftools/klfutil.cpp.orig	2014-07-28 22:23:49 UTC
+++ src/klftools/klfutil.cpp
@@ -853,7 +853,7 @@ KLF_EXPORT QVariant klfLoadVariantFromTe
 		 //                       3
 		 "(?:" RX_COORD_SEP "|\\s*([+])\\s*)"
 		 //4                                5         6
-		 "(" RX_INT ")(?:"RX_COORD_SEP"|\\s*([x])\\s*)(" RX_INT ")\\s*\\)?");
+		 "(" RX_INT ")(?:" RX_COORD_SEP "|\\s*([x])\\s*)(" RX_INT ")\\s*\\)?");
   static const int RECTRX_X1 = 1, RECTRX_Y1 = 2, RECTRX_MIDDLESEP_PLUS = 3,
     RECTRX_X2orW = 4, RECTRX_LASTSEP_X = 5, RECTRX_Y2orH = 6;
 
@@ -866,7 +866,7 @@ KLF_EXPORT QVariant klfLoadVariantFromTe
   //                                       1                                2                     3
   QRegExp brushrx("^(?:q?brush)?\\(?\\s*(?:([A-Za-z_]\\w*)" RX_COORD_SEP ")?(\\d+)" RX_COORD_SEP "(\\d+)"
 		  //            4         5               6
-		  RX_COORD_SEP "(\\d+)"  "("RX_COORD_SEP "(\\d+))?" "\\s*\\)?", Qt::CaseInsensitive);
+		  RX_COORD_SEP "(\\d+)"  "(" RX_COORD_SEP "(\\d+))?" "\\s*\\)?", Qt::CaseInsensitive);
   static const int BRUSHRX_STYLE = 1, BRUSHRX_R = 2, BRUSHRX_G = 3, BRUSHRX_B = 4, BRUSHRX_A = 6;
 
   //               1           2
