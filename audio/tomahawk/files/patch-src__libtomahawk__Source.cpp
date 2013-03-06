--- ./src/libtomahawk/Source.cpp.orig	2013-02-13 21:31:17.000000000 +0100
+++ ./src/libtomahawk/Source.cpp	2013-02-13 21:32:00.000000000 +0100
@@ -148,7 +148,7 @@
     m_avatar = new QPixmap( avatar );
     m_fancyAvatar = 0;
 
-    TomahawkUtils::Cache::instance()->putData( "Sources", 7776000000 /* 90 days */, m_username, ba );
+    TomahawkUtils::Cache::instance()->putData( "Sources", Q_INT64_C(7776000000) /* 90 days */, m_username, ba );
     m_avatarUpdated = true;
 }
 
