--- kexi/kexidb/drivers/pqxx/pqxxcursor.cpp.orig	Sun Feb 11 16:45:47 2007
+++ kexi/kexidb/drivers/pqxx/pqxxcursor.cpp	Sun Feb 11 16:50:26 2007
@@ -155,7 +155,7 @@
 			m_implicityStarted = true;
 		}
 
-		m_res = new pqxx::result(((pqxxSqlConnection*)connection())->m_trans->data->exec(m_sql.utf8()));
+		m_res = new pqxx::result(((pqxxSqlConnection*)connection())->m_trans->data->exec(m_sql.utf8().data()));
 		((pqxxSqlConnection*)connection())
 			->drv_commitTransaction(((pqxxSqlConnection*)connection())->m_trans);
 //		my_conn->m_trans->commit();
