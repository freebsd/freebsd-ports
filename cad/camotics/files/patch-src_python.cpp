Description: Fix build with Python 3.13: only call PyEval_ThreadsInitialized()
  and PyEval_InitThreads() (no-ops since 3.9, the former removed in 3.13) on
  older Python versions.
Issue ID: none
Changeset: https://github.com/CauldronDevelopmentLLC/camotics/commit/9acf1a4
TODO: Fixed on upstream master (unreleased); drop when updating to the first
  release after 1.3.0.

--- src/python.cpp.orig	2023-03-09 16:07:30 UTC
+++ src/python.cpp
@@ -105,7 +105,9 @@ PyMODINIT_FUNC PyInit_camotics() {
   cb::Logger::instance().setLogPrefix(true);
   cb::Logger::instance().setLogColor(false);
 
+#if PY_VERSION_HEX < 0x03090000
   if (!PyEval_ThreadsInitialized()) PyEval_InitThreads();
+#endif
 
   PyObject *mod = PyModule_Create(&module);
   if (!mod) return 0;
