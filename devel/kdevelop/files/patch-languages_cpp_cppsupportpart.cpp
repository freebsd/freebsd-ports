--- languages/cpp/cppsupportpart.cpp	2007/10/08 11:32:36	722993
+++ languages/cpp/cppsupportpart.cpp	2007/10/23 22:58:44	728690
@@ -2533,6 +2533,9 @@
 				QStringList l = files.res;
 				while(!l.isEmpty() ) {
 					emit addedSourceInfo( l.front() );
+					emit aboutToRemoveSourceInfo( l.front() );
+					emit removedSourceInfo( l.front() );
+					emit addedSourceInfo( l.front() );
 					l.pop_front();
 				}
 
@@ -2542,9 +2545,11 @@
 				QStringList l = files.res;
 				while( !l.isEmpty() ) {
 					emit codeModelUpdated( l.front() );
+					emit aboutToRemoveSourceInfo( l.front() );
+					emit removedSourceInfo( l.front() );
+					emit addedSourceInfo( l.front() );
 					l.pop_front();
 				}
-				emit updatedSourceInfo();
 			}
 		}
 		kdDebug( 9007 ) << "files in code-model after parseEmit: " << codeModel()->fileList().count() << " before: " << oldFileCount << endl;
