--- src/models/datemodel.cpp.orig	2020-01-01 20:28:31 UTC
+++ src/models/datemodel.cpp
@@ -347,8 +347,6 @@ void DateModel::setYearCountColumn( int column )
     }
 }
 
-void DateModel::setYearCountColumn( int column );
-
 TreeItem *DateModel::findYearItem(int year)
 {
     TreeItem *yearItem = NULL;
