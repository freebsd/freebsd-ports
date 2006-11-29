--- migrate/versioning/script/script.py.orig	Fri Oct 27 05:48:25 2006
+++ migrate/versioning/script/script.py	Thu Nov  9 20:01:50 2006
@@ -19,10 +19,11 @@
     del sys.path[-1]
     return module
 
-def logsql_engine(func):
+def logsql_engine(func,force=False):
     """migrate.run.migrate_engine is a logengine in the decorated function"""
     def entangle(*p,**k):
-        migrate.run.migrate_engine = sqlalchemy.create_engine(None,strategy='logsql')
+        if force or (not getattr(migrate.run,'migrate_engine',None)):
+            migrate.run.migrate_engine = sqlalchemy.create_engine(None,strategy='logsql')
         reload(migrate)
         try:
             return func(*p,**k)

