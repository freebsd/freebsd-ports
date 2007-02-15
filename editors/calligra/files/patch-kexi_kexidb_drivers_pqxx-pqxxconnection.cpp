--- kexi/kexidb/drivers/pqxx/pqxxconnection.cpp.orig	Sun Feb 11 16:58:22 2007
+++ kexi/kexidb/drivers/pqxx/pqxxconnection.cpp	Sun Feb 11 16:58:53 2007
@@ -277,7 +277,7 @@
 		//		m_trans = new pqxx::nontransaction(*m_pqxxsql);
 //		KexiDBDrvDbg << "About to execute" << endl;
 		//Create a result object through the transaction
-		d->res = new pqxx::result(m_trans->data->exec(statement.utf8()));
+		d->res = new pqxx::result(m_trans->data->exec(statement.utf8().data()));
 //		KexiDBDrvDbg << "Executed" << endl;
 		//Commit the transaction
 		if (implicityStarted) {
