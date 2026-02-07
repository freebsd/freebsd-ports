--- lang/tcl/tcl_db.c.orig	2013-09-09 15:35:07 UTC
+++ lang/tcl/tcl_db.c
@@ -3708,9 +3708,10 @@ tcl_DbGetFlags(interp, objc, objv, dbp)
 		for (i = 0; db_flags[i].flag != 0; i++)
 			if (LF_ISSET(db_flags[i].flag)) {
 				if (strlen(buf) > 0)
-					(void)strncat(buf, " ", sizeof(buf));
-				(void)strncat(
-				    buf, db_flags[i].arg, sizeof(buf));
+					(void)strncat(buf, " ",
+					    sizeof(buf) - (strlen(buf) + 1));
+				(void)strncat(buf, db_flags[i].arg,
+				    sizeof(buf) - (strlen(buf) + 1));
 			}
 
 		res = NewStringObj(buf, strlen(buf));
@@ -3764,9 +3765,10 @@ tcl_DbGetOpenFlags(interp, objc, objv, d
 		for (i = 0; open_flags[i].flag != 0; i++)
 			if (LF_ISSET(open_flags[i].flag)) {
 				if (strlen(buf) > 0)
-					(void)strncat(buf, " ", sizeof(buf));
-				(void)strncat(
-				    buf, open_flags[i].arg, sizeof(buf));
+					(void)strncat(buf, " ",
+					    sizeof(buf) - (strlen(buf) + 1));
+				(void)strncat(buf, open_flags[i].arg,
+				    sizeof(buf) - (strlen(buf) + 1));
 			}
 
 		res = NewStringObj(buf, strlen(buf));
