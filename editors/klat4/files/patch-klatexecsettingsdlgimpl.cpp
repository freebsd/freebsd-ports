--- klatexecsettingsdlgimpl.cpp.orig
+++ klatexecsettingsdlgimpl.cpp
@@ -271,6 +271,7 @@
 				return tmp.entry().commandLine();
 //			else if (index.column() == 4)
 //				return tmp.entry().shortcut().toString();
+			return QVariant();
 		} 
 		else
 			return QVariant();
@@ -294,6 +295,7 @@
 		return QString(i18n("Parameters"));
 //	else if(sect == 4)
 //		return QString("Shortcut");
+	return QString("Invisible");
 }
 
 void KlatExecConfigModel::slotDataChanged(const QModelIndex &top, const QModelIndex &bottom)
