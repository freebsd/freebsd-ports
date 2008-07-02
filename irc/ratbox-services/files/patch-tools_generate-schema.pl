--- ./tools/generate-schema.pl.orig	2006-09-09 16:41:27.000000000 +0100
+++ ./tools/generate-schema.pl	2008-06-26 15:36:23.000000000 +0100
@@ -15,11 +15,11 @@
 my @schemas = ("base/schema-mysql.txt", "base/schema-pgsql.txt");
 my @plain_schemas = ("base/schema-sqlite.txt");
 
-my %vals = &parse_includes("../include");
+my %vals = &parse_includes("%%PREFIX%%/include");
 
-unless(-r "../include/setup.h")
+unless(-r "%%PREFIX%%/include/setup.h")
 {
-	print("Unable to read ../include/setup.h, please run configure first\n");
+	print("Unable to read %%PREFIX%%/include/setup.h, please run configure first\n");
 	exit();
 }
 
