--- src/libtomahawk/sip/PeerInfo.cpp.orig	2015-04-15 04:41:40 UTC
+++ src/libtomahawk/sip/PeerInfo.cpp
@@ -333,7 +333,7 @@ PeerInfo::setAvatar( const QPixmap& avat
     d->fancyAvatar.reset();
 
     Q_ASSERT( !contactId().isEmpty() );
-    TomahawkUtils::Cache::instance()->putData( "Sources", 7776000000 /* 90 days */, contactId(), ba );
+    TomahawkUtils::Cache::instance()->putData( "Sources", Q_INT64_C(7776000000) /* 90 days */, contactId(), ba );
 }
 
 
