--- utils/mdb2rec.c.orig	2019-01-03 08:47:43 UTC
+++ utils/mdb2rec.c
@@ -33,7 +33,7 @@
 #include <gettext.h>
 #define _(str) gettext (str)
 
-#include <glib.h>
+#define HAVE_GLIB
 #include <mdbtools.h>
 
 #include <rec.h>
@@ -472,16 +472,14 @@ process_mdb (void)
   if (!db)
     recutl_out_of_memory ();
 
-  /* Initialize libmdb and open the input file.  */
-  mdb_init();
-  mdb_set_date_fmt ("%Y-%m-%dT%H:%M:%S%z"); /* ISO 8601 */
-
   mdb = mdb_open (mdb2rec_mdb_file, MDB_NOFLAGS);
   if (!mdb)
     {
       recutl_fatal (_("could not open file %s\n"),
                     mdb2rec_mdb_file);
     }
+
+  mdb_set_date_fmt (mdb, "%Y-%m-%dT%H:%M:%S%z"); /* ISO 8601 */
 
   /* Read the catalog.  */
   if (!mdb_read_catalog (mdb, MDB_TABLE))
