--- internal/route/install.go.orig	2020-08-30 17:50:22 UTC
+++ internal/route/install.go
@@ -121,7 +121,7 @@ func InstallInit(c *context.Context) {
 	c.Title("install.install")
 	c.PageIs("Install")
 
-	c.Data["DbOptions"] = []string{"MySQL", "PostgreSQL", "MSSQL", "SQLite3"}
+	c.Data["DbOptions"] = []string{"MySQL", "PostgreSQL", "SQLite3"}
 }
 
 func Install(c *context.Context) {
