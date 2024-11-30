--- CHANGELOG.md.orig	2024-11-29 01:52:15 UTC
+++ CHANGELOG.md
@@ -7596,7 +7596,12 @@ - **readme**: Fix Docker image reference
 - **readme**: Fix Docker image reference
   ([`b9a40d8`](https://github.com/python-gitlab/python-gitlab/commit/b9a40d822bcff630a4c92c395c134f8c002ed1cb))
 
-v1.8.0 is not available. ``` Unable to find image
+  v1.8.0 is not available.
+  ```
+  Unable to find image 'registry.gitlab.com/python-gitlab/python-gitlab:v1.8.0' locally
+  docker: Error response from daemon: manifest for registry.gitlab.com/python-gitlab/python-gitlab:v1.8.0 not found: manifest unknown: manifest unknown.
+  ```
+
   'registry.gitlab.com/python-gitlab/python-gitlab:v1.8.0' locally docker: Error response from
   daemon: manifest for registry.gitlab.com/python-gitlab/python-gitlab:v1.8.0 not found: manifest
   unknown: manifest unknown. ```
@@ -7928,9 +7933,12 @@ The integration tests failed because a test called 'de
   GitLabException class handles byte-to-string conversion already in its __init__. This commit
   removes the call to 'decode()' in the test.
 
-``` Traceback (most recent call last): File "./tools/python_test_v4.py", line 801, in <module>
-  assert 'Retry later' in error_message.decode() AttributeError: 'str' object has no attribute
-  'decode' ```
+  ```
+  Traceback (most recent call last):
+    File "./tools/python_test_v4.py", line 801, in <module>
+      assert 'Retry later' in error_message.decode()
+  AttributeError: 'str' object has no attribute 'decode'
+  ```
 
 - Handle empty 'Retry-After' header from GitLab
   ([`7a3724f`](https://github.com/python-gitlab/python-gitlab/commit/7a3724f3fca93b4f55aed5132cf46d3718c4f594))
