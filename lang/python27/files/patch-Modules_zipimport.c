
Bug: http://bugs.python.org/issue26171

--- Modules/zipimport.c.orig	2015-12-05 19:47:16 UTC
+++ Modules/zipimport.c
@@ -895,6 +895,11 @@ get_data(char *archive, PyObject *toc_en
         PyMarshal_ReadShortFromFile(fp);        /* local header size */
     file_offset += l;           /* Start of file data */
 
+    if (data_size > LONG_MAX - 1) {
+        fclose(fp);
+        PyErr_NoMemory();
+        return NULL;
+    }
     raw_data = PyString_FromStringAndSize((char *)NULL, compress == 0 ?
                                           data_size : data_size + 1);
     if (raw_data == NULL) {
