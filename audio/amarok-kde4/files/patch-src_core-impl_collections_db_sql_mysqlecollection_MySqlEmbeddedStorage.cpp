--- ./src/core-impl/collections/db/sql/mysqlecollection/MySqlEmbeddedStorage.cpp
+++ ./src/core-impl/collections/db/sql/mysqlecollection/MySqlEmbeddedStorage.cpp
@@ -82,7 +82,9 @@ MySqlEmbeddedStorage::MySqlEmbeddedStorage( const QString &storageLocation )
     }
 
     setenv( "MYSQL_HOME", storagePath.toAscii().data(), 1 );
-    if( mysql_server_init( 0 , 0, 0 ) != 0 )
+    setenv( "DEFAULT_HOME_ENV", storagePath.toAscii().data(), 1 );
+    char *args[] = { "amarok" };
+    if( mysql_library_init( 1 , args, 0 ) != 0 )
     {
         error() << "MySQL library initialization failed.";
         reportError( "init" );
