--- src/modules/server-stats/serverstatsmodel.cpp.orig	2018-11-30 15:43:21 UTC
+++ src/modules/server-stats/serverstatsmodel.cpp
@@ -21,7 +21,7 @@ ServerStats::Model::Model(QSharedPointer<RedisClient::
             return;
           }
 
-          m_serverInfo = RedisClient::ServerInfo::fromString(r.toRawString(-1))
+          m_serverInfo = RedisClient::ServerInfo::fromString(r.toRawString())
                              .parsed.toVariantMap();
           emit serverInfoChanged();
         });
