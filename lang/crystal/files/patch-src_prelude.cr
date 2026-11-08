--- src/prelude.cr.orig	2026-10-29 18:48:14 UTC
+++ src/prelude.cr
@@ -1,15 +1,3 @@
-{%
-  min_compiler_version = "1.13.0"
-  if compare_versions(Crystal::VERSION, min_compiler_version) < 0
-    @top_level.warning <<-TXT
-      This compiler release at version #{Crystal::VERSION.id} is no longer supported.
-      Please upgrade to at least Crystal #{min_compiler_version.id}.
-
-      Learn about the forward compatibility policy at https://crystal-lang.org/reference/project/release-policy.html#forward-compatibility
-      TXT
-  end
-%}
-
 # Entries to this file should only be ordered if macros are involved -
 # macros need to be defined before they are used.
 # A first compiler pass gathers all classes and methods, removing the
