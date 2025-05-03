--- test/tests-sqlite3.lua.orig	2024-03-27 05:11:12 UTC
+++ test/tests-sqlite3.lua
@@ -1114,7 +1114,7 @@ function colla.test()
     --  print(row.id,row.content)
     --end
     local n = 0
-    for row in colla.db:nrows('SELECT * FROM test WHERE content="hElLo wOrLd"') do
+    for row in colla.db:nrows("SELECT * FROM test WHERE content='hElLo wOrLd'") do
       -- print(row.id,row.content)
       assert_equal (row.content:lower(), "hello world")
       n = n + 1
