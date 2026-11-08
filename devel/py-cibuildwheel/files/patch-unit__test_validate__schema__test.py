-- Use cibuildwheel's own bundled schema in the validate-pyproject tests.
-- The schema bundled in validate-pyproject-schema-store is older than
-- cibuildwheel 4.2.1 and rejects new options such as [tool.cibuildwheel].enable
-- and the pyodide build-frontend table.

--- unit_test/validate_schema_test.py.orig	2026-09-14 15:11:41 UTC
+++ unit_test/validate_schema_test.py
@@ -4,7 +4,9 @@ import validate_pyproject.api

 import pytest
 import validate_pyproject.api
+from validate_pyproject.plugins import PluginWrapper

+from cibuildwheel import schema
 from cibuildwheel.util import resources

 DIR = Path(__file__).parent.resolve()
@@ -14,8 +16,12 @@ def validator() -> validate_pyproject.api.Validator:
 def validator() -> validate_pyproject.api.Validator:
     """
     Reuse the validator for all tests, to keep unit tests fast.
+    Use only cibuildwheel's own schema, avoiding outdated copies bundled in
+    validate-pyproject-schema-store.
     """
-    return validate_pyproject.api.Validator()
+    return validate_pyproject.api.Validator(
+        plugins=[PluginWrapper("cibuildwheel", schema.get_schema)]
+    )


 def test_validate_default_schema(validator: validate_pyproject.api.Validator) -> None:
