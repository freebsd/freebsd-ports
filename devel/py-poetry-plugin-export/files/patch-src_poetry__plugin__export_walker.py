-- Fix marker simplification for pylock.toml export when poetry-core
-- does not provide BaseMarker.apply() (e.g. poetry-core >= 2.4).
-- The previous fallback used marker.without_extras() which incorrectly
-- simplifies OR markers containing an extra condition to AnyMarker.
-- See https://github.com/python-poetry/poetry-plugin-export/issues/218

--- src/poetry_plugin_export/walker.py.orig	2026-09-24 02:39:43 UTC
+++ src/poetry_plugin_export/walker.py
@@ -5,6 +5,7 @@ from poetry.core.version.markers import AnyMarker
 from packaging.utils import canonicalize_name
 from poetry.core.constraints.version.util import constraint_regions
 from poetry.core.version.markers import AnyMarker
+from poetry.core.version.markers import BaseMarker
 from poetry.core.version.markers import SingleMarker
 from poetry.packages import DependencyPackage
 from poetry.utils.extras import get_extra_package_names
@@ -262,6 +263,59 @@ def get_locked_package(
     return next(iter(compatible_candidates), None)
 
 
+def _apply_extras_to_marker(
+    marker: BaseMarker, extras: Collection[NormalizedName]
+) -> BaseMarker:
+    """Apply selected extras to a marker, returning the residual marker.
+
+    This is a fallback for poetry-core versions that do not provide
+    ``BaseMarker.apply()``.  It evaluates ``extra`` markers against the
+    selected extras and preserves all non-extra markers.
+    """
+    from poetry.core.version.markers import EmptyMarker
+    from poetry.core.version.markers import MarkerUnion
+    from poetry.core.version.markers import MultiMarker
+    from poetry.core.version.markers import SingleMarkerLike
+
+    if isinstance(marker, SingleMarkerLike):
+        if marker.name == "extra":
+            return AnyMarker() if marker.validate({"extra": extras}) else EmptyMarker()
+
+        return marker
+
+    if isinstance(marker, MultiMarker):
+        new_markers: list[BaseMarker] = []
+        for m in marker.markers:
+            applied = _apply_extras_to_marker(m, extras)
+            if applied.is_empty():
+                return EmptyMarker()
+
+            if not applied.is_any():
+                new_markers.append(applied)
+
+        if not new_markers:
+            return AnyMarker()
+
+        return MultiMarker(*new_markers)
+
+    if isinstance(marker, MarkerUnion):
+        new_markers: list[BaseMarker] = []
+        for m in marker.markers:
+            applied = _apply_extras_to_marker(m, extras)
+            if applied.is_any():
+                return AnyMarker()
+
+            if not applied.is_empty():
+                new_markers.append(applied)
+
+        if not new_markers:
+            return EmptyMarker()
+
+        return MarkerUnion(*new_markers)
+
+    return marker
+
+
 def get_project_dependency_packages2(
     locker: Locker,
     project_python_marker: BaseMarker | None = None,
@@ -276,15 +330,11 @@ def get_project_dependency_packages2(
         try:
             marker = marker.apply({"extra": extras})  # type: ignore[attr-defined]
         except AttributeError:
-            # poetry-core <= 1.4.2
-            if not marker.validate({"extra": extras}):
-                continue
+            # poetry-core <= 1.4.2 or >= 2.4 (apply() was removed)
+            marker = _apply_extras_to_marker(marker, extras)
 
-            marker = marker.without_extras()
-
-        else:
-            if marker.is_empty():
-                continue
+        if marker.is_empty():
+            continue
 
         if project_python_marker:
             marker = project_python_marker.intersect(marker)
