--- src/utils/textutils.cpp.orig	2025-04-02 10:33:24 UTC
+++ src/utils/textutils.cpp
@@ -77,7 +77,7 @@ QList<double> PowerPrefixValues;
 
 QList<QString> PowerPrefixes;
 QList<double> PowerPrefixValues;
-const QString TextUtils::PowerPrefixesString = QString("pnmkMGTu\\x%1").arg(MicroSymbolCode, 4, 16, QChar('0'));
+const QString TextUtils::PowerPrefixesString = QString("pnmkMGTu\\x%1").arg(static_cast<int>(MicroSymbolCode), 4, 16, QChar('0'));
 
 typedef QHash<QString /*brokenFont*/, QString /*replacementFont*/> FixedFontsHash;
 
@@ -761,7 +761,7 @@ QString TextUtils::convertExtendedChars(const QString 
 			result.append(c);
 		}
 		else {
-			result.append(QString("&#x%1;").arg(c.unicode(), 0, 16));
+			result.append(QString("&#x%1;").arg(static_cast<int>(c.unicode()), /*fieldWidth*/ 0, /*base*/ 16));
 		}
 	}
 
