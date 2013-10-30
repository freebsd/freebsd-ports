--- sql/chartablesql.cpp.orig	2013-10-30 15:20:29.130118000 +0000
+++ sql/chartablesql.cpp
@@ -57,7 +57,7 @@ QVariant CharSqlModel::data(const QModel
 			// Read the unicode value
 			unicode = value.toInt();
 			// Convert unicode to a char
-			unicodeToChar = QString::QString(QChar(unicode)); //"\'" + QString::QString(QChar(unicode)) + "\'";
+			unicodeToChar = QString(QChar(unicode)); //"\'" + QString::QString(QChar(unicode)) + "\'";
 			return unicodeToChar;
 		} else {
 			// Last column (error weight)
