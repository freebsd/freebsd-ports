commit a6b8bae5a6a4752926eba409202ec061d81c6c8a
Author: Serge Hallyn <serge.hallyn@canonical.com>
Date:   Wed Jan 30 21:05:45 2013 -0600

    complete virterror->virerror name change
    
    Without these two string changes in generator.py, the
    virGetLastError wrapper does not get created in
    /usr/share/pyshared/libvirt.py.  Noticed when running
    tests with virt-install.
    
    Signed-off-by: Serge Hallyn <serge.hallyn@ubuntu.com>

diff --git a/python/generator.py b/python/generator.py
index 5d27f66..71ca883 100755
--- ./python/generator.py
+++ ./python/generator.py
@@ -123,7 +123,7 @@ class docParser(xml.sax.handler.ContentHandler):
                     self.function_return_field = attrs['field']
         elif tag == 'enum':
             if (attrs['file'] == "libvirt" or
-                attrs['file'] == "virterror"):
+                attrs['file'] == "virerror"):
                 enum(attrs['type'],attrs['name'],attrs['value'])
             elif attrs['file'] == "libvirt-lxc":
                 lxc_enum(attrs['type'],attrs['name'],attrs['value'])
@@ -137,7 +137,7 @@ class docParser(xml.sax.handler.ContentHandler):
             if self.function != None:
                 if (self.function_module == "libvirt" or
                     self.function_module == "virevent" or
-                    self.function_module == "virterror"):
+                    self.function_module == "virerror"):
                     function(self.function, self.function_descr,
                              self.function_return, self.function_args,
                              self.function_file, self.function_module,
