--- sources/machine_info.cpp.orig	2026-01-28 12:19:13 UTC
+++ sources/machine_info.cpp
@@ -188,10 +188,8 @@ void MachineInfo::send_info_to_debug()
 	QDirIterator it1(QETApp::commonElementsDir().toLatin1(),nameFilters,  QDir::Files, QDirIterator::Subdirectories);
 			while (it1.hasNext())
 			{
-				if(it1.next() > 0 )
-				{
+				it1.next();
 				commomElementsDir ++;
-				}
 			}
 	qInfo()<< " Common Elements count:"<< commomElementsDir << "Elements";
 	
@@ -200,10 +198,8 @@ void MachineInfo::send_info_to_debug()
 	QDirIterator it2(QETApp::customElementsDir().toLatin1(), nameFilters, QDir::Files, QDirIterator::Subdirectories);
 			while (it2.hasNext())
 			{
-				if(it2.next() > 0 )
-				{
+				it2.next();
 				customElementsDir ++;
-				}
 			}
 	qInfo()<< " Custom Elements count:"<< customElementsDir << "Elements";
 	
@@ -211,10 +207,8 @@ void MachineInfo::send_info_to_debug()
 	QDirIterator it3(QETApp::companyElementsDir().toLatin1(), nameFilters, QDir::Files, QDirIterator::Subdirectories);
 			while (it3.hasNext())
 			{
-				if(it3.next() > 0 )
-				{
+				it3.next();
 				companyElementsDir ++;
-				}
 			}
 	qInfo()<< " Company Elements count:"<< companyElementsDir << "Elements";
 	
