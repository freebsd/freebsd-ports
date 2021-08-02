Add additional arguments to "www/yarn" to point to the cache folder and prevent
it to establish network connections during the build process.

--- local_repos/rules_nodejs/internal/npm_install/npm_install.bzl.orig	2021-02-21 10:43:57 UTC
+++ local_repos/rules_nodejs/internal/npm_install/npm_install.bzl
@@ -360,6 +360,8 @@ def _yarn_install_impl(repository_ctx):
     yarn = get_yarn_label(repository_ctx)
 
     yarn_args = []
+    yarn_args.append("--cache-folder %%_MY_YARNCACHE%%")
+    yarn_args.append("--offline")
 
     # Set frozen lockfile as default install to install the exact version from the yarn.lock
     # file. To perform an yarn install use the vendord yarn binary with:
