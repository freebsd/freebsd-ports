-- Trim trailing whitespace from the substrait-rs fallback version file.
-- The build script reads gen/version when no git submodule is available;
-- the generated file may contain a trailing newline, which semver rejects.
--- build.rs.orig
+++ build.rs
@@ -167,9 +167,7 @@
         }

         // File exists we should get the version and return it.
-        Ok(semver::Version::parse(&fs::read_to_string(
-            substrait_version_file,
-        )?)?)
+        Ok(semver::Version::parse(&fs::read_to_string(substrait_version_file)?.trim())?)
     }
 }

