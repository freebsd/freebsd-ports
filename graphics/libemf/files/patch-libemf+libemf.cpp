--- libemf/libemf.cpp.org	Sat Oct  4 09:50:55 2003
+++ libemf/libemf.cpp	Sat Oct  4 09:51:09 2003
@@ -849,7 +849,7 @@
     if ( dc->fp ) {
 
       std::for_each( dc->records.begin(), dc->records.end(),
-		     std::bind2nd( std::mem_fun1( &EMF::METARECORD::serialize ),
+		     std::bind2nd( mem_fun1( &EMF::METARECORD::serialize ),
 				   dc->ds ) );
       fclose( dc->fp );
 
@@ -896,7 +896,7 @@
     if ( dc->fp ) {
 
       std::for_each( dc->records.begin(), dc->records.end(),
-		     std::bind2nd( std::mem_fun1( &EMF::METARECORD::serialize ),
+		     std::bind2nd( mem_fun1( &EMF::METARECORD::serialize ),
 				   dc->ds ) );
     }
 
@@ -1108,7 +1108,7 @@
     if ( dc == 0 ) return;
 
     std::for_each( dc->records.begin(), dc->records.end(),
-		   std::mem_fun( &EMF::METARECORD::edit ) );
+		   mem_fun( &EMF::METARECORD::edit ) );
 #endif /* ENABLE_EDITING */
   }
 
