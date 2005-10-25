
$FreeBSD$

--- amarok/src/collectiondb.cpp.orig
+++ amarok/src/collectiondb.cpp
@@ -290,15 +290,18 @@
     QString yearAutoIncrement = "";
     if ( m_dbConnPool->getDbConnectionType() == DbConnection::postgresql )
     {
-        query( QString( "CREATE %1 SEQUENCE album_seq%2;" ).arg( conn ? "TEMPORARY" : "").arg( conn ? "_temp" : ""), conn );
-        query( QString( "CREATE %1 SEQUENCE artist_seq%2;" ).arg( conn ? "TEMPORARY" : "").arg( conn ? "_temp" : ""), conn );
-        query( QString( "CREATE %1 SEQUENCE genre_seq%2;" ).arg( conn ? "TEMPORARY" : "").arg( conn ? "_temp" : ""), conn );
-        query( QString( "CREATE %1 SEQUENCE year_seq%2;" ).arg( conn ? "TEMPORARY" : "").arg( conn ? "_temp" : ""), conn );
+	if(!conn) 
+	{
+	    query( QString( "CREATE SEQUENCE album_seq;" ), conn );
+	    query( QString( "CREATE SEQUENCE artist_seq;" ), conn );
+	    query( QString( "CREATE SEQUENCE genre_seq;" ), conn );
+	    query( QString( "CREATE SEQUENCE year_seq;" ), conn );
+	}
 
-        albumAutoIncrement = QString("DEFAULT nextval('album_seq%1')").arg( conn ? "_temp" : "");
-        artistAutoIncrement = QString("DEFAULT nextval('artist_seq%1')").arg( conn ? "_temp" : "");
-        genreAutoIncrement = QString("DEFAULT nextval('genre_seq%1')").arg( conn ? "_temp" : "");
-        yearAutoIncrement = QString("DEFAULT nextval('year_seq%1')").arg( conn ? "_temp" : "");
+        albumAutoIncrement = QString("DEFAULT nextval('album_seq')");
+        artistAutoIncrement = QString("DEFAULT nextval('artist_seq')");
+        genreAutoIncrement = QString("DEFAULT nextval('genre_seq')");
+        yearAutoIncrement = QString("DEFAULT nextval('year_seq')");
     }
     else if ( m_dbConnPool->getDbConnectionType() == DbConnection::mysql )
     {
@@ -412,10 +415,12 @@
 
     if ( m_dbConnPool->getDbConnectionType() == DbConnection::postgresql )
     {
-            query( QString( "DROP SEQUENCE album_seq%1;" ).arg( conn ? "_temp" : ""), conn );
-            query( QString( "DROP SEQUENCE artist_seq%1;" ).arg( conn ? "_temp" : ""), conn );
-            query( QString( "DROP SEQUENCE genre_seq%1;" ).arg( conn ? "_temp" : ""), conn );
-            query( QString( "DROP SEQUENCE year_seq%1;" ).arg( conn ? "_temp" : ""), conn );
+	if (conn == NULL) {
+		query( QString( "DROP SEQUENCE album_seq;" ), conn );
+		query( QString( "DROP SEQUENCE artist_seq;" ), conn );
+		query( QString( "DROP SEQUENCE genre_seq;" ), conn );
+		query( QString( "DROP SEQUENCE year_seq;" ), conn );
+	}
     }
 }
 
@@ -1461,10 +1466,26 @@
         path = path.left( path.length() - 1 );
 
     if (m_dbConnPool->getDbConnectionType() == DbConnection::postgresql) {
-        query( QString( "UPDATE directories%1 SET changedate=%2 WHERE dir='%3';")
-                        .arg( conn ? "_temp" : "" )
-                        .arg( datetime )
-                        .arg( escapeString( path ) ), conn );
+	// REPLACE INTO is not valid SQL for postgres, so we need to check whether we 
+	// should UPDATE() or INSERT()
+	QStringList values = query(QString("SELECT * FROM directories%1 WHERE dir='%2';")
+	    .arg( conn ? "_temp" : "")
+	    .arg( escapeString( path ) ), conn );
+
+	if(values.count() > 0 )
+	{
+	    query( QString( "UPDATE directories%1 SET changedate=%2 WHERE dir='%3';")
+		.arg( conn ? "_temp" : "" )
+		.arg( datetime )
+		.arg( escapeString( path ) ), conn );
+	}
+	else
+	{
+	    query( QString( "INSERT INTO directories%1 (dir,changedate) VALUES ('%2','%3');")
+		.arg( conn ? "_temp" : "")
+		.arg( escapeString( path ) )
+		.arg( datetime ), conn );
+	}
     }
     else
     {
@@ -2429,9 +2450,7 @@
     QString _table = table;
     if (table.find("_temp") > 0) _table = table.left(table.find("_temp"));
 
-    /* this does not work with postgres
-    curvalSql = QString("SELECT currval('%1_seq');").arg(_table); */
-    curvalSql = QString("SELECT last_value FROM %1_seq;").arg(_table);
+    curvalSql = QString("SELECT currval('%1_seq');").arg(_table);
     result = PQexec(m_db, curvalSql.utf8());
     if (result == NULL)
     {
