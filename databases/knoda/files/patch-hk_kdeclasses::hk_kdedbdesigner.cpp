--- hk_kdeclasses/hk_kdedbdesigner.cpp.orig	Thu Jul 15 22:18:12 2004
+++ hk_kdeclasses/hk_kdedbdesigner.cpp	Thu Jul 15 22:21:24 2004
@@ -238,7 +238,7 @@
 	QString n;
 	//cerr <<"drag wert="<<index(itemAt(event->pos()))<<endl;
 	n.setNum(p_datasourceframe->datasource()->presentationnumber());
-	n="<VUPN>"+n+"</VUPN>\n<VALUE>"+( itemAt(event->pos())?itemAt(event->pos())->text():"") +"</VALUE>\n";
+	n="<VUPN>"+n+"</VUPN>\n<VALUE>"+( itemAt(event->pos())?itemAt(event->pos())->text():static_cast<QString>("")) +"</VALUE>\n";
 	//cerr<<"dragwert"<<n<<endl;
         QCString cstr =n.utf8();
 	//cerr<"cstr"<<cstr<<endl;
