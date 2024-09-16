--- tests/unit/test_graphql.py.orig	2024-09-15 19:09:56 UTC
+++ tests/unit/test_graphql.py
@@ -1,5 +1,7 @@
-import httpx
 import pytest
+
+pytest.skip(reason="gql is missing from ports", allow_module_level=True)
+import httpx
 import respx
 
 import gitlab
