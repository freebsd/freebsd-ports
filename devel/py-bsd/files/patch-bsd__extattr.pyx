--- bsd/extattr.pyx.orig	2017-03-30 01:24:59 UTC
+++ bsd/extattr.pyx
@@ -335,7 +335,7 @@ def _list(fobj, namespace = Namespaces.U
             if isinstance(fobj, file_types):
                 kr = defs.extattr_list_file(fobj.fileno(), namespace, data_buffer, nbytes)
             elif type(fobj) is int:
-                kr = defs.exattr_list_file(fobj, namespace, data_buffer, nbytes)
+                kr = defs.extattr_list_file(fobj, namespace, data_buffer, nbytes)
             elif type(fobj) is str:
                 if follow:
                     kr = defs.extattr_list_file(pname, namespace, data_buffer, nbytes)
