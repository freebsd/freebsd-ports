-- Increase recursion limit to avoid "queries overflow the depth limit" error.
-- This is often needed for complex async code or deeply nested types.

--- src/frontend/src/lib.rs.orig	2026-05-14 04:51:15 UTC
+++ src/frontend/src/lib.rs
@@ -1,3 +1,5 @@
+#![recursion_limit = "512"]
+
 // Copyright 2023 Greptime Team
 //
 // Licensed under the Apache License, Version 2.0 (the "License");
