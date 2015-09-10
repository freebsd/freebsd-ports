--- script/app_deps.erl.orig	2015-06-02 17:06:36 UTC
+++ script/app_deps.erl
@@ -1,3 +1,4 @@
+#!%%LOCALBASE%%/bin/escript
 %%% Run with 'escript app_deps.erl'
 %%% Change the path in filelib:wildcard/1 as required to capture
 %%% all your dependencies.
