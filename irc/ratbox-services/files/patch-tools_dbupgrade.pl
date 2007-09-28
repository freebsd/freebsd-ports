--- ./tools/dbupgrade.pl.orig	Fri Aug 24 13:01:39 2007
+++ ./tools/dbupgrade.pl	Fri Aug 24 13:38:23 2007
@@ -27,9 +27,9 @@
 	exit;
 }
 
-unless(-r "../include/setup.h")
+unless(-r "%%PREFIX%%/include/setup.h")
 {
-	print("Unable to read ../include/setup.h, please run configure first\n");
+	print("Unable to read %%PREFIX%%/include/setup.h, please run configure first\n");
 	exit();
 }
 
@@ -71,7 +71,7 @@
 }
 else
 {
-	%vals = &parse_includes("../include");
+	%vals = &parse_includes("%%PREFIX%%/include");
 }
 
 while(my ($key, $value) = each(%vals))
