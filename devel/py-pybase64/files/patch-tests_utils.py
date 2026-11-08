-- Add missing test support files that upstream left out of the PyPI sdist.
-- tests/__init__.py lets the test modules use relative imports, and
-- tests/utils.py provides the param_simd fixture/helpers they import.
-- See https://github.com/mayeut/pybase64/tree/v1.5.0/tests

--- tests/__init__.py.orig	2026-09-14 14:34:28 UTC
+++ tests/__init__.py
@@ -0,0 +1 @@
+# placeholder to allow relative imports in the test suite
--- tests/utils.py.orig	2026-09-14 14:34:28 UTC
+++ tests/utils.py
@@ -0,0 +1,64 @@
+from __future__ import annotations
+
+import os
+
+import pytest
+
+import pybase64
+
+TYPE_CHECKING = False
+if TYPE_CHECKING:
+    from collections.abc import Iterator
+    from typing import Any
+
+has_extension = hasattr(pybase64, "_set_simd_path")
+assert has_extension or os.environ.get("CIBUILDWHEEL", "0") == "0"
+
+compile_flags = [0]
+runtime_flags = 0
+if has_extension:
+    runtime_flags = pybase64._get_simd_flags_runtime()  # type: ignore[attr-defined]
+    flags = pybase64._get_simd_flags_compile()  # type: ignore[attr-defined]
+    for i in range(31):
+        if flags & (1 << i):
+            compile_flags += [(1 << i)]
+
+
+def _get_simd_name(simd_id: int) -> str:
+    if has_extension:
+        simd_flag = compile_flags[simd_id]
+        simd_name = "C" if simd_flag == 0 else pybase64._get_simd_name(simd_flag)  # type: ignore[attr-defined]
+    else:
+        simd_name = "PY"
+    return simd_name
+
+
+param_simd = pytest.mark.parametrize(
+    "simd",
+    range(len(compile_flags)),
+    ids=_get_simd_name,
+    indirect=True,
+)
+
+
+@pytest.fixture
+def simd(request: pytest.FixtureRequest) -> Iterator[int]:
+    simd_id = request.param
+    if not has_extension:
+        assert simd_id == 0
+        yield simd_id
+        return
+
+    flag = compile_flags[simd_id]
+    if flag != 0 and not flag & runtime_flags:  # pragma: no branch
+        simd_name = _get_simd_name(simd_id)  # pragma: no cover
+        pytest.skip(f"{simd_name!r} SIMD extension not available")  # pragma: no cover
+    old_flag = pybase64._get_simd_path()  # type: ignore[attr-defined]
+    pybase64._set_simd_path(flag)  # type: ignore[attr-defined]
+    assert pybase64._get_simd_path() == flag  # type: ignore[attr-defined]
+    yield simd_id
+    pybase64._set_simd_path(old_flag)  # type: ignore[attr-defined]
+
+
+def unused_args(*args: Any) -> None:  # noqa: ARG001
+    return None
