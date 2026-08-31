Reference:  https://docutils.sourceforge.io/docs/api/publisher.html#component-specification

--- hatch_build.py.orig	2020-02-02 00:00:00 UTC
+++ hatch_build.py
@@ -20,7 +20,7 @@ class CustomBuildHook(BuildHookInterface):
             if line.strip() != ":orphan:"
         )
         (output / "pipx.1").write_bytes(
-            publish_string(source, writer="manpage", settings_overrides={"report_level": 5})
+            publish_string(source, writer_name="manpage", settings_overrides={"report_level": 5})
         )
 
 
