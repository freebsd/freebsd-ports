--- hamster/__init__.py.orig	2008-08-07 10:53:47.000000000 -0400
+++ hamster/__init__.py	2008-08-07 10:54:01.000000000 -0400
@@ -74,6 +74,7 @@ if not exists(USER_HAMSTER_DIR):
 if not exists(HAMSTER_DB):
     print "Database not found in %s - installing default from %s!" % (HAMSTER_DB, SHARED_DATA_DIR)
     copyfile(join(SHARED_DATA_DIR, DB_FILE), HAMSTER_DB)
+    os.chmod(HAMSTER_DB, 0644)
 
 # Init storage
 
