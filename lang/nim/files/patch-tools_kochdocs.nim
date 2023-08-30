--- tools/kochdocs.nim.orig	2023-08-03 15:46:14 UTC
+++ tools/kochdocs.nim
@@ -94,7 +94,6 @@ proc nimCompileFold*(desc, input: string, outputDir = 
   execFold(desc, cmd)
 
 const officialPackagesMarkdown = """
-pkgs/atlas/doc/atlas.md
 """.splitWhitespace()
 
 proc getMd2html(): seq[string] =
@@ -157,24 +156,9 @@ lib/std/sha1.nim
 """.splitWhitespace()
 
   officialPackagesList = """
-pkgs/asyncftpclient/src/asyncftpclient.nim
-pkgs/smtp/src/smtp.nim
-pkgs/punycode/src/punycode.nim
-pkgs/db_connector/src/db_connector/db_common.nim
-pkgs/db_connector/src/db_connector/db_mysql.nim
-pkgs/db_connector/src/db_connector/db_odbc.nim
-pkgs/db_connector/src/db_connector/db_postgres.nim
-pkgs/db_connector/src/db_connector/db_sqlite.nim
-pkgs/checksums/src/checksums/md5.nim
-pkgs/checksums/src/checksums/sha1.nim
 """.splitWhitespace()
 
   officialPackagesListWithoutIndex = """
-pkgs/db_connector/src/db_connector/mysql.nim
-pkgs/db_connector/src/db_connector/sqlite3.nim
-pkgs/db_connector/src/db_connector/postgres.nim
-pkgs/db_connector/src/db_connector/odbcsql.nim
-pkgs/db_connector/src/db_connector/private/dbutils.nim
 """.splitWhitespace()
 
 when (NimMajor, NimMinor) < (1, 1) or not declared(isRelativeTo):
@@ -341,7 +325,7 @@ proc buildJS(): string =
 proc buildDocsDir*(args: string, dir: string) =
   let args = nimArgs & " " & args
   let docHackJsSource = buildJS()
-  gitClonePackages(@["asyncftpclient", "punycode", "smtp", "db_connector", "checksums", "atlas"])
+  #gitClonePackages(@["asyncftpclient", "punycode", "smtp", "db_connector", "checksums", "atlas"])
   createDir(dir)
   buildDocSamples(args, dir)
 
