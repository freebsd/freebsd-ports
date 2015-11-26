--- lib/Alembic/AbcCoreOgawa/StreamManager.cpp.orig	2015-01-15 18:28:49 UTC
+++ lib/Alembic/AbcCoreOgawa/StreamManager.cpp
@@ -111,7 +111,8 @@ StreamIDPtr StreamManager::get()
 
         newVal = oldVal & ~( 1 << (val - 1) );
     }
-    while ( !__sync_bool_compare_and_swap( &m_streams, oldVal, newVal ) );
+    while ( !__atomic_compare_exchange_n( &m_streams, &oldVal, newVal,
+        false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST ) );
 
     return StreamIDPtr( new StreamID( this, ( std::size_t ) val - 1 ) );
 }
@@ -140,7 +141,8 @@ void StreamManager::put( std::size_t iSt
         newVal = oldVal | ( 1 << iStreamID );
 
     }
-    while ( !__sync_bool_compare_and_swap( &m_streams, oldVal, newVal ) );
+    while ( !__atomic_compare_exchange_n( &m_streams, &oldVal, newVal,
+        false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST ) );
 }
 
 #else
