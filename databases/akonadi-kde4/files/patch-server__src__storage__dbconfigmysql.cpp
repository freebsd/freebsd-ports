--- ./server/src/storage/dbconfigmysql.cpp.orig	2012-06-13 02:11:19.473370856 +0200
+++ ./server/src/storage/dbconfigmysql.cpp	2012-06-13 02:11:50.113468897 +0200
@@ -265,7 +265,7 @@ void DbConfigMysql::startInternalServer()
   // first run, some MySQL versions need a mysql_install_db run for that
   const QString confFile = XdgBaseDirs::findResourceFile( "config", QLatin1String( "akonadi/mysql-global.conf" ) );
   if ( QDir( dataDir ).entryList( QDir::NoDotAndDotDot | QDir::AllEntries ).isEmpty() && !mMysqlInstallDbPath.isEmpty() ) {
-    const QStringList arguments = QStringList() << QString::fromLatin1( "--force" ) << QString::fromLatin1( "--defaults-file=%1" ).arg( confFile ) << QString::fromLatin1( "--datadir=%1/" ).arg( dataDir );
+    const QStringList arguments = QStringList() << QString::fromLatin1( "--force" ) << QString::fromLatin1( "--defaults-file=%1" ).arg( confFile ) << QString::fromLatin1( "--datadir=%1/" ).arg( dataDir ) << QString::fromLatin1( "--basedir=%%LOCALBASE%%" );
     QProcess::execute( mMysqlInstallDbPath, arguments );
   }
 
