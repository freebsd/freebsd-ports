--- src/Gui/Application.cpp.orig	Sat Feb 24 11:48:30 2007
+++ src/Gui/Application.cpp	Wed Aug  8 22:09:54 2007
@@ -675,7 +675,7 @@
   const char* start = App::Application::Config()["StartWorkbench"].c_str();
 
   PyObject *key, *value;
-  int pos = 0;
+  Py_ssize_t pos = 0;
   QStringList wb;
   // insert all items
   while (PyDict_Next(_pcWorkbenchDictionary, &pos, &key, &value)) {
