--- ./tools/generate-schema.pl.orig	Fri Aug 24 12:45:51 2007
+++ ./tools/generate-schema.pl	Fri Aug 24 12:49:13 2007
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
 
