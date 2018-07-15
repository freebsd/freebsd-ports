# Fix for CVE-2018-8740: https://nvd.nist.gov/vuln/detail/CVE-2018-8740
# Detect databases whose schema is corrupted using a CREATE TABLE AS statement and issue an appropriate error message.
# Commit [d75e6765]: https://www.sqlite.org/src/info/d75e67654aa9620b
# Description: https://bugs.launchpad.net/ubuntu/+source/sqlite3/+bug/1756349

--- uppsrc/plugin/sqlite3/lib/sqlite3.c.orig	2018-03-31 06:10:16 UTC
+++ uppsrc/plugin/sqlite3/lib/sqlite3.c
@@ -103474,8 +103474,6 @@ SQLITE_PRIVATE void sqlite3EndTable(
   p = pParse->pNewTable;
   if( p==0 ) return;
 
-  assert( !db->init.busy || !pSelect );
-
   /* If the db->init.busy is 1 it means we are reading the SQL off the
   ** "sqlite_master" or "sqlite_temp_master" table on the disk.
   ** So do not write to the disk again.  Extract the root page number
@@ -103486,6 +103484,10 @@ SQLITE_PRIVATE void sqlite3EndTable(
   ** table itself.  So mark it read-only.
   */
   if( db->init.busy ){
+    if( pSelect ){
+      sqlite3ErrorMsg(pParse, "");
+      return;
+    }
     p->tnum = db->init.newTnum;
     if( p->tnum==1 ) p->tabFlags |= TF_Readonly;
   }
@@ -117813,7 +117815,7 @@ static void corruptSchema(
     char *z;
     if( zObj==0 ) zObj = "?";
     z = sqlite3MPrintf(db, "malformed database schema (%s)", zObj);
-    if( zExtra ) z = sqlite3MPrintf(db, "%z - %s", z, zExtra);
+    if( zExtra && zExtra[0] ) z = sqlite3MPrintf(db, "%z - %s", z, zExtra);
     sqlite3DbFree(db, *pData->pzErrMsg);
     *pData->pzErrMsg = z;
   }
