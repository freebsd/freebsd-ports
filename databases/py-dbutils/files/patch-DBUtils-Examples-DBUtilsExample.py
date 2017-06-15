--- DBUtils/Examples/DBUtilsExample.py.orig	2017-02-05 12:39:41 UTC
+++ DBUtils/Examples/DBUtilsExample.py
@@ -147,7 +147,7 @@ class DBUtilsExample(ExamplePage):
                 else:
                     db.cursor().execute(ddl)
                     db.commit()
-            except self.dbapi.Error, error:
+            except self.dbapi.Error as error:
                 if self.dbapi_name != 'pg':
                     db.rollback()
                 self.outputMsg(error, True)
@@ -173,7 +173,7 @@ class DBUtilsExample(ExamplePage):
                 else:
                     db.cursor().execute(cmd)
                     db.commit()
-            except self.dbapi.Error, error:
+            except self.dbapi.Error as error:
                 try:
                     if self.dbapi_name == 'pg':
                         db.query('end')
@@ -198,7 +198,7 @@ class DBUtilsExample(ExamplePage):
                 cursor.execute(query)
                 result = cursor.fetchall()
                 cursor.close()
-        except self.dbapi.Error, error:
+        except self.dbapi.Error as error:
             self.outputMsg(error, True)
             return
         if not result:
@@ -251,7 +251,7 @@ class DBUtilsExample(ExamplePage):
                     for cmd in cmds:
                         db.cursor().execute(cmd)
                     db.commit()
-            except self.dbapi.Error, error:
+            except self.dbapi.Error as error:
                 if self.dbapi_name == 'pg':
                     db.query('end')
                 else:
@@ -275,7 +275,7 @@ class DBUtilsExample(ExamplePage):
                 cursor.execute(query)
                 result = cursor.fetchall()
                 cursor.close()
-        except self.dbapi.Error, error:
+        except self.dbapi.Error as error:
             self.outputMsg(error, True)
             return
         if not result:
@@ -335,7 +335,7 @@ class DBUtilsExample(ExamplePage):
             else:
                 db.cursor().execute(cmd)
                 db.commit()
-        except self.dbapi.Error, error:
+        except self.dbapi.Error as error:
             if self.dbapi_name == 'pg':
                 db.query('end')
             else:
@@ -359,7 +359,7 @@ class DBUtilsExample(ExamplePage):
                 cursor.execute(query)
                 result = cursor.fetchall()
                 cursor.close()
-        except self.dbapi.Error, error:
+        except self.dbapi.Error as error:
             self.outputMsg(error, True)
             return
         if not result:
@@ -422,7 +422,7 @@ class DBUtilsExample(ExamplePage):
                 db.cursor().execute(cmd)
                 cursor.close()
                 db.commit()
-        except self.dbapi.Error, error:
+        except self.dbapi.Error as error:
             if self.dbapi_name == 'pg':
                 db.query('end')
             else:
