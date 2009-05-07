--- src/common.c.orig	2009-05-02 19:19:39.000000000 +0400
+++ src/common.c	2009-05-02 19:20:04.000000000 +0400
@@ -941,7 +941,7 @@
 		}
 	    }
 	    if (!(dbst->options & BDB_NOT_OPEN)) {
-		bdb_test_error(dbst->dbp->close(dbst->dbp, flags));
+		dbst->dbp->close(dbst->dbp, flags);
 	    }
 	}
 	else {
@@ -950,7 +950,7 @@
 		bdb_ary_delete(&envst->db_ary, dbst->ori_val);
 	    }
 	    if (!(dbst->options & BDB_NOT_OPEN)) {
-		bdb_test_error(dbst->dbp->close(dbst->dbp, flags));
+		dbst->dbp->close(dbst->dbp, flags);
 	    }
 	}
     }
