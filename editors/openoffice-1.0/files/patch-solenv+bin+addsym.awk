--- solenv/bin/addsym.awk.kan	Sat Jul 27 10:10:19 2002
+++ solenv/bin/addsym.awk	Thu Jul 25 14:49:30 2002
@@ -62,6 +62,7 @@
 BEGIN { global_found = "false" }
 /[ \t]*local:/ { global_found = "false" }
 global_found == "true"  { 
+    print "\t\tGetVersionInfo;"
     print "\t\t_ZTS*;"
     print "\t\t_ZTI*;"
     global_found = "false" }
