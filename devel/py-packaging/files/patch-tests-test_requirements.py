Obtained from:  https://github.com/pypa/packaging/commit/8cb9dbf19e2b76ab025efc11208bd50e09e8223e

--- tests/test_requirements.py.orig	2021-07-23 07:28:49 UTC
+++ tests/test_requirements.py
@@ -192,4 +192,6 @@ class TestRequirements:
     def test_parseexception_error_msg(self):
         with pytest.raises(InvalidRequirement) as e:
             Requirement("toto 42")
-        assert "Expected stringEnd" in str(e.value)
+        assert "Expected stringEnd" in str(e.value) or (
+            "Expected string_end" in str(e.value)  # pyparsing>=3.0.0
+        )
