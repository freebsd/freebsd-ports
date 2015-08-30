--- src/include/xmmsclient/xmmsclient++/coll.h.orig	2011-10-20 19:26:08 UTC
+++ src/include/xmmsclient/xmmsclient++/coll.h
@@ -612,7 +612,7 @@ namespace Xmms 
 
 		template< typename keyT, typename valT >
 		AbstractElement< keyT, valT >::AbstractElement( const Coll& coll, keyT index )
-			: coll_ (coll), index_( index )
+			: coll_ ( const_cast< Coll& >( coll ) ), index_( index )
 		{
 			xmmsv_coll_ref( coll_.getColl() );
 		}
