--- src/extconf.rb.orig	Thu Feb  7 23:02:25 2002
+++ src/extconf.rb	Wed Feb 13 08:27:48 2002
@@ -24,13 +24,48 @@
 	 else
 	    ""
 	 end
-unless (!test && (have_library("db-4", "db_version#{unique}") ||
-		  have_library("db4", "db_version#{unique}") ||
-		  have_library("db3", "db_version#{unique}") ||
-		  have_library("db2", "db_version")) ||
-	have_library("db", "db_version"))
-    raise "libdb.a not found"
-end
+
+catch(:done) {
+  unless test
+    with_ver = with_config('db-version')
+
+    unless with_ver && with_ver != '4'
+      if have_library("db-4", "db_version#{unique}") ||
+	  have_library("db4", "db_version#{unique}")
+	throw :done
+      end
+
+      if with_ver == '4'
+	raise "libdb-4 or libdb4 not found"
+      end
+    end
+
+    unless with_ver && with_ver != '3'
+      if have_library("db3", "db_version#{unique}")
+	throw :done
+      end
+
+      if with_ver == '3'
+	raise "libdb3 not found"
+      end
+    end
+
+    unless with_ver && with_ver != '2'
+      if have_library("db2", "db_version")
+	throw :done
+      end
+
+      if with_ver == '2'
+	raise "libdb3 not found"
+      end
+    end
+  end
+
+  if !have_library("db", "db_version")
+    raise "libdb not found"
+  end
+}
+
 create_makefile("bdb")
 begin
    make = open("Makefile", "a")
