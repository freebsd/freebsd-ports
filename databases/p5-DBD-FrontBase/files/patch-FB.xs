--- ../DBD-FB-1.37.orig/FB.xs	Wed Jul 26 16:49:08 2006
+++ FB.xs	Fri Jul 20 14:30:25 2007
@@ -111,10 +111,6 @@
         XSRETURN_YES;
     }
     /* pre-disconnect checks and tidy-ups */
-    if (DBIc_CACHED_KIDS(imp_dbh)) {
-        SvREFCNT_dec(DBIc_CACHED_KIDS(imp_dbh));
-        DBIc_CACHED_KIDS(imp_dbh) = Nullhv;
-    }
     /* Check for disconnect() being called whilst refs to cursors	*/
     /* still exists. This possibly needs some more thought.		*/
     if (DBIc_ACTIVE_KIDS(imp_dbh) && DBIc_WARN(imp_dbh) && !dirty) {
@@ -167,10 +163,6 @@
     }
     else {
 	/* pre-disconnect checks and tidy-ups */
-        if (DBIc_CACHED_KIDS(imp_dbh)) {
-            SvREFCNT_dec(DBIc_CACHED_KIDS(imp_dbh));
-            DBIc_CACHED_KIDS(imp_dbh) = Nullhv;
-        }
         if (DBIc_IADESTROY(imp_dbh)) { /* want's ineffective destroy    */
             DBIc_ACTIVE_off(imp_dbh);
         }
