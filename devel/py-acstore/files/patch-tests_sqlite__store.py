--- tests/sqlite_store.py.orig	2024-03-30 05:07:58 UTC
+++ tests/sqlite_store.py
@@ -188,13 +188,13 @@ class SQLiteAttributeContainerStoreTest(test_lib.BaseT
             attribute_container.CONTAINER_TYPE, column_names=column_names))
         self.assertEqual(len(containers), 1)
 
-        filter_expression = 'attribute == "8f0bf95a7959baad9666b21a7feed79d"'
+        filter_expression = 'attribute == \'8f0bf95a7959baad9666b21a7feed79d\''
         containers = list(test_store._GetAttributeContainersWithFilter(
             attribute_container.CONTAINER_TYPE, column_names=column_names,
             filter_expression=filter_expression))
         self.assertEqual(len(containers), 1)
 
-        filter_expression = 'attribute != "8f0bf95a7959baad9666b21a7feed79d"'
+        filter_expression = 'attribute != \'8f0bf95a7959baad9666b21a7feed79d\''
         containers = list(test_store._GetAttributeContainersWithFilter(
             attribute_container.CONTAINER_TYPE, column_names=column_names,
             filter_expression=filter_expression))
