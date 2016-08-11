
Bug: http://bugs.python.org/issue26171

--- Modules/zipimport.c.orig	2014-10-12 07:03:53 UTC
+++ Modules/zipimport.c
@@ -1089,6 +1089,11 @@ get_data(PyObject *archive, PyObject *to
         PyMarshal_ReadShortFromFile(fp);        /* local header size */
     file_offset += l;           /* Start of file data */
 
+    if (data_size > LONG_MAX - 1) {
+        fclose(fp);
+        PyErr_NoMemory();
+        return NULL;
+    }
     bytes_size = compress == 0 ? data_size : data_size + 1;
     if (bytes_size == 0)
         bytes_size++;
