--- khacc/qhaccacctchsr.cpp.orig	Mon Apr  5 01:23:08 2004
+++ khacc/qhaccacctchsr.cpp	Fri Apr  9 21:08:02 2004
@@ -47,7 +47,7 @@
 	if( acct.isNull() ) return;
 	setText( 0, myrow[QC::ANAME].gets()+
 					 ( showanums && !myrow[QC::ANUM].gets().isEmpty() ?
-						 " ("+myrow[QC::ANUM].gets()+")" : "" ) );
+						 QString(" (")+myrow[QC::ANUM].gets()+QString(")") : QString("") ) );
 	setText( 1, acct[QC::ACBAL].gets() );
 	setRenameEnabled( 0, true );
 	setRenameEnabled( 1, false );
@@ -70,7 +70,7 @@
 	else if( p=="CHOOSERSHOWANUMS" ){
 		setText( 0, myrow[QC::ANAME].gets()+
 						 ( b && !myrow[QC::ANUM].gets().isEmpty() ?
-							 " ("+myrow[QC::ANUM].gets()+")" : "" ) );
+							 QString(" (")+myrow[QC::ANUM].gets()+QString(")") : QString("") ) );
 	}
 	else if( p=="HIDECATEGORIES" ){
 		bool vis=true;
