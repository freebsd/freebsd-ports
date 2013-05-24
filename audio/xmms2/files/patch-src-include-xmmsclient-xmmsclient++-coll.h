--- src/include/xmmsclient/xmmsclient++/coll.h.orig	2013-05-24 12:04:02.505430442 +0200
+++ src/include/xmmsclient/xmmsclient++/coll.h	2013-05-24 12:07:11.694426120 +0200
@@ -612,7 +612,7 @@
 
 		template< typename keyT, typename valT >
 		AbstractElement< keyT, valT >::AbstractElement( const Coll& coll, keyT index )
-			: coll_ (coll), index_( index )
+			: coll_ ( const_cast< Coll& >( coll ) ), index_( index )
 		{
 			xmmsv_coll_ref( coll_.getColl() );
 		}
