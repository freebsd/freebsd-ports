-- Handle the case when jax is installed but jaxlib is not available,
-- which causes an ImportError when importing jax. In this case, jax
-- should be excluded from the available backends.
--- tests/conftest.py.orig	2026-09-11 16:12:26 UTC
+++ tests/conftest.py
@@ -24,11 +24,14 @@ for _lib in _ALL_BACKENDS:
     if _lib_available:
         _AVAILABLE_BACKENDS.add(_lib)
         if _lib == "jax":
-            import jax
+            try:
+                import jax
 
-            jax.config.update("jax_enable_x64", True)
-            jax.config.update("jax_platform_name", "cpu")
-            os.environ["XLA_PYTHON_CLIENT_ALLOCATOR"] = "platform"
+                jax.config.update("jax_enable_x64", True)
+                jax.config.update("jax_platform_name", "cpu")
+                os.environ["XLA_PYTHON_CLIENT_ALLOCATOR"] = "platform"
+            except (ImportError, ModuleNotFoundError):
+                _AVAILABLE_BACKENDS.discard(_lib)
 
         elif _lib == "mlx":
             # default to cpu, since many linear algebra decompositions are
