Add additional arguments to "www/yarn" to point to the cache folder and prevent
it to establish network connections during the build process.

--- local_repos/rules_nodejs/internal/npm_install/npm_install.bzl.orig	2022-07-10 12:17:50 UTC
+++ local_repos/rules_nodejs/internal/npm_install/npm_install.bzl
@@ -824,6 +824,8 @@ def _yarn_install_impl(repository_ctx):
     yarn = get_yarn_label(repository_ctx)
     yarn_version = _detect_yarn_version(repository_ctx, yarn)
     yarn_args = []
+    yarn_args.append("--cache-folder %%_MY_YARNCACHE%%")
+    yarn_args.append("--offline")
 
     # CLI arguments changed in yarn 2+
     if yarn_version == "berry":
