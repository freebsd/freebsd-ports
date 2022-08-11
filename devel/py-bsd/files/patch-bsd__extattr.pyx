--- bsd/extattr.pyx.orig	2022-04-25 12:03:03 UTC
+++ bsd/extattr.pyx
@@ -71,7 +71,7 @@ def get_namespace(*args):
                 raise ValueError("%s is not a valid extattr namespace" % n)
             retval[n] = _namespace_mapping[n]
         return retval
-    
+
 def get(fobj, namespace = Namespaces.USER, attrname = None, follow = True):
     """Wrapper for extattr_get(3) API.
 
@@ -215,7 +215,7 @@ def set(fobj, namespace = Namespaces.USER, attr = None
 
 def set(fobj, namespace = Namespaces.USER, attr = None, follow = True):
     """Wrapper for the extattr_set(3) API.
-    
+
     :Parameters:
     	- fobj (file, str, int):  the file object upon which to operate.
 		If a string, this is the path; if a file, the file object
@@ -241,7 +241,7 @@ def set(fobj, namespace = Namespaces.USER, attr = None
         char *attr_data
         size_t data_len
         ssize_t kr
-        
+
     pname = NULL
     data_buffer = NULL
     data_len = 0
@@ -261,11 +261,11 @@ def set(fobj, namespace = Namespaces.USER, attr = None
         attr_name = k
         attr_data = v
         data_len = len(v)
-        
+
         if isinstance(fobj, file_types):
-            kr = defs.exattr_set_fd(fobj.fileno(), namespace, attr_name, attr_data, data_len)
+            kr = defs.extattr_set_fd(fobj.fileno(), namespace, attr_name, attr_data, data_len)
         elif type(fobj) is int:
-            kr = defs.exattr_set_fd(fobj, namespace, attr_name, attr_data, data_len)
+            kr = defs.extattr_set_fd(fobj, namespace, attr_name, attr_data, data_len)
         elif type(fobj) is str:
             if follow:
                 kr = defs.extattr_set_file(fobj, namespace, attr_name, attr_data, data_len)
@@ -304,11 +304,11 @@ def _list(fobj, namespace = Namespaces.USER, follow = 
         size_t nbytes
         ssize_t kr
         unsigned char *ptr
-        
+
     retval = []
     pname = NULL
     data_buffer = NULL
-    
+
     try:
         if isinstance(fobj, file_types):
             kr = defs.extattr_list_fd(fobj.fileno(), namespace, data_buffer, 0)
@@ -322,7 +322,7 @@ def _list(fobj, namespace = Namespaces.USER, follow = 
                 kr = defs.extattr_list_link(pname, namespace, NULL, 0)
         else:
             raise ValueError("Unknown file type")
-        
+
         if kr == -1:
             raise OSError(errno, os.strerror(errno))
 
@@ -331,7 +331,7 @@ def _list(fobj, namespace = Namespaces.USER, follow = 
             data_buffer = <char*>malloc(nbytes)
             if not data_buffer:
                 raise MemoryError()
-        
+
             if isinstance(fobj, file_types):
                 kr = defs.extattr_list_file(fobj.fileno(), namespace, data_buffer, nbytes)
             elif type(fobj) is int:
@@ -358,6 +358,5 @@ def _list(fobj, namespace = Namespaces.USER, follow = 
     finally:
         if data_buffer:
             free(data_buffer)
-            
-list = _list
 
+list = _list
