--- ./src/libtomahawk/Source.cpp.orig	2013-03-24 10:41:13.000000000 +0100
+++ ./src/libtomahawk/Source.cpp	2013-04-29 22:46:47.000000000 +0200
@@ -148,7 +148,7 @@
     m_avatar = new QPixmap( avatar );
     m_fancyAvatar = 0;
 
-    TomahawkUtils::Cache::instance()->putData( "Sources", 7776000000 /* 90 days */, m_username, ba );
+    TomahawkUtils::Cache::instance()->putData( "Sources", Q_INT64_C(7776000000) /* 90 days */, m_username, ba );
     m_avatarUpdated = true;
 }
 
