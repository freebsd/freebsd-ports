--- ./src/libtomahawk/sip/PeerInfo.cpp.orig	2013-06-28 17:01:55.000000000 +0200
+++ ./src/libtomahawk/sip/PeerInfo.cpp	2013-06-28 17:02:45.000000000 +0200
@@ -312,7 +312,7 @@
     m_fancyAvatar = 0;
 
     Q_ASSERT( !contactId().isEmpty() );
-    TomahawkUtils::Cache::instance()->putData( "Sources", 7776000000 /* 90 days */, contactId(), ba );
+    TomahawkUtils::Cache::instance()->putData( "Sources", Q_INT64_C(7776000000) /* 90 days */, contactId(), ba );
 }
 
 
