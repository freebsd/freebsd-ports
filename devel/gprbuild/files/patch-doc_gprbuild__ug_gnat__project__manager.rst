
  Patch GPRBuild to search host's ${PREFIX} in addition to the installed
  GNAT ${PREFIX}. This enables easier integration of Ada Ports, and removes
  the restriction of of limited "with"-ing of GPR projects to the GNAT
  ${PREFIX} only.

--- doc/gprbuild_ug/gnat_project_manager.rst.orig	2026-06-22 14:19:29 UTC
+++ doc/gprbuild_ug/gnat_project_manager.rst
@@ -1195,7 +1195,6 @@ file is used:
   :envvar:`ADA_PROJECT_PATH` is used for compatibility, it is recommended to
   use :envvar:`GPR_PROJECT_PATH_FILE` or :envvar:`GPR_PROJECT_PATH`.
 
-* Finally, it is searched relative to the default project directories.
   The following locations are searched, in the specified order:
 
   * :file:`<compiler_prefix>/<target>/<runtime>/share/gpr`
@@ -1204,6 +1203,10 @@ file is used:
   * :file:`<compiler_prefix>/<target>/lib/gnat`
   * :file:`<compiler_prefix>/share/gpr/`
   * :file:`<compiler_prefix>/lib/gnat/`
+
+* Finally, on FreeBSD only, a global default project directory is searched:
+
+  * :file:`%%PREFIX%%/share/gpr/`
 
 The first two paths are only added if the explicit runtime is specified either
 via :option:`--RTS` switch or via ``Runtime`` attribute. <target> can be
