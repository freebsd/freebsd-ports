--- tools/kochdocs.nim.orig	2025-02-06 01:49:40 UTC
+++ tools/kochdocs.nim
@@ -93,7 +93,6 @@ const officialPackagesMarkdown = """
   execFold(desc, cmd)
 
 const officialPackagesMarkdown = """
-pkgs/atlas/doc/atlas.md
 """.splitWhitespace()
 
 proc getMd2html(): seq[string] =
@@ -158,28 +157,9 @@ lib/pure/htmlparser.nim
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
-pkgs/checksums/src/checksums/sha2.nim
-pkgs/checksums/src/checksums/sha3.nim
-pkgs/checksums/src/checksums/bcrypt.nim
-pkgs/htmlparser/src/htmlparser.nim
 """.splitWhitespace()
 
   officialPackagesListWithoutIndex = """
-pkgs/db_connector/src/db_connector/mysql.nim
-pkgs/db_connector/src/db_connector/sqlite3.nim
-pkgs/db_connector/src/db_connector/postgres.nim
-pkgs/db_connector/src/db_connector/odbcsql.nim
-pkgs/db_connector/src/db_connector/private/dbutils.nim
 """.splitWhitespace()
 
 when (NimMajor, NimMinor) < (1, 1) or not declared(isRelativeTo):
@@ -349,7 +329,7 @@ proc buildDocsDir*(args: string, dir: string) =
 proc buildDocsDir*(args: string, dir: string) =
   let args = nimArgs & " " & args
   let docHackJsSource = buildJS()
-  gitClonePackages(@["asyncftpclient", "punycode", "smtp", "db_connector", "checksums", "atlas", "htmlparser"])
+  #gitClonePackages(@["asyncftpclient", "punycode", "smtp", "db_connector", "checksums", "atlas", "htmlparser"])
   createDir(dir)
   buildDocSamples(args, dir)
 
