--- src/utils/textutils.cpp.orig	2025-10-07 13:46:45 UTC
+++ src/utils/textutils.cpp
@@ -80,7 +80,7 @@ QList<double> PowerPrefixValues;
 
 QList<QString> PowerPrefixes;
 QList<double> PowerPrefixValues;
-const QString TextUtils::PowerPrefixesString = QString("pnmkMGTu\\x%1").arg(MicroSymbolCode, 4, 16, QChar('0'));
+const QString TextUtils::PowerPrefixesString = QString("pnmkMGTu\\x%1").arg(static_cast<int>(MicroSymbolCode), 4, 16, QChar('0'));
 
 typedef QHash<QString /*brokenFont*/, QString /*replacementFont*/> FixedFontsHash;
 
@@ -763,7 +763,7 @@ QString TextUtils::convertExtendedChars(const QString 
 			result.append(c);
 		}
 		else {
-			result.append(QString("&#x%1;").arg(c.unicode(), 0, 16));
+			result.append(QString("&#x%1;").arg(static_cast<int>(c.unicode()), /*fieldWidth*/ 0, /*base*/ 16));
 		}
 	}
 
