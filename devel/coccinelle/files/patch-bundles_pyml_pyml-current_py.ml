Query the python-M.N-embed pkg-config module for libpython. The bare
python-M.N module ships an empty Libs: on FreeBSD (extension-building
metadata), so it lacks the -lpython needed to embed the interpreter and
find_library_path aborts with "unable to parse the output of pkg-config".

--- bundles/pyml/pyml-current/py.ml.orig
+++ bundles/pyml/pyml-current/py.ml
@@ -376,7 +376,7 @@

 let libpython_from_pkg_config version_major version_minor =
   let command =
-    Printf.sprintf "pkg-config --libs python-%d.%d" version_major
+    Printf.sprintf "pkg-config --libs python-%d.%d-embed" version_major
       version_minor in
   match run_command_opt command false with
     Some (words :: _) ->
