-- Provide a local fallback for trim_kwargs_from_test_function when the internal
-- Azure SDK devtools_testutils package is not available.  This helper is used
-- by the await_prepared_test decorator to stripPreparer-provided keyword arguments
-- before calling the wrapped async test method.  The fallback is only active when
-- devtools_testutils is missing, allowing the offline async unit tests to run in
-- the FreeBSD ports environment.
-- Upstream feature request to publish the test utilities:
-- https://github.com/azure/azure-sdk-for-python/issues/47397

--- tests/test_search_index_client_async.py.orig	2026-09-24 02:57:41 UTC
+++ tests/test_search_index_client_async.py
@@ -4,13 +4,28 @@ import functools
 # ------------------------------------
 import asyncio
 import functools
+import inspect
 import pytest
 from unittest import mock
 from azure.core.credentials import AzureKeyCredential
 from azure.search.documents import ApiVersion
 from azure.search.documents.aio import SearchClient
 from azure.search.documents.indexes.aio import SearchIndexClient, SearchIndexerClient
-from devtools_testutils import trim_kwargs_from_test_function
+
+try:
+    from devtools_testutils import trim_kwargs_from_test_function
+except ImportError:
+    def trim_kwargs_from_test_function(fn, kwargs):
+        # Minimal fallback for running unit tests without the internal Azure SDK test utilities.
+        # Removes keyword arguments that the wrapped test function does not accept.
+        try:
+            args, _, kw, _, _, _, _ = inspect.getfullargspec(fn)
+        except AttributeError:
+            args, _, kw, _ = inspect.getargspec(fn)  # pylint: disable=deprecated-method
+        if kw is None:
+            accepted = set(args)
+            for key in [k for k in kwargs if k not in accepted]:
+                del kwargs[key]

 CREDENTIAL = AzureKeyCredential(key="test_api_key")

