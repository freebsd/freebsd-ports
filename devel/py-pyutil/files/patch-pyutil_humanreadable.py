Description: Fix Python 2 leftovers: hr() of functions and methods read
  func_name/func_code/im_class/im_func.
Issue ID: to be filed upstream
Changeset: none (upstream master has the same code)
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/humanreadable.py.orig	2022-12-26 22:48:41 UTC
+++ pyutil/humanreadable.py
@@ -24,16 +24,16 @@ class BetterRepr(Repr):
         self.maxother = 300
 
     def repr_function(self, obj, level):
-        if hasattr(obj, 'func_code'):
-            return '<' + obj.func_name + '() at ' + os.path.basename(obj.func_code.co_filename) + ':' + str(obj.func_code.co_firstlineno) + '>'
+        if hasattr(obj, '__code__'):
+            return '<' + obj.__name__ + '() at ' + os.path.basename(obj.__code__.co_filename) + ':' + str(obj.__code__.co_firstlineno) + '>'
         else:
-            return '<' + obj.func_name + '() at (builtin)'
+            return '<' + obj.__name__ + '() at (builtin)'
 
     def repr_instance_method(self, obj, level):
-        if hasattr(obj, 'func_code'):
-            return '<' + obj.im_class.__name__ + '.' + obj.im_func.__name__ + '() at ' + os.path.basename(obj.im_func.func_code.co_filename) + ':' + str(obj.im_func.func_code.co_firstlineno) + '>'
+        if hasattr(obj, '__code__'):
+            return '<' + obj.__self__.__class__.__name__ + '.' + obj.__func__.__name__ + '() at ' + os.path.basename(obj.__func__.__code__.co_filename) + ':' + str(obj.__func__.__code__.co_firstlineno) + '>'
         else:
-            return '<' + obj.im_class.__name__ + '.' + obj.im_func.__name__ + '() at (builtin)'
+            return '<' + obj.__self__.__class__.__name__ + '.' + obj.__func__.__name__ + '() at (builtin)'
 
     def repr_long(self, obj, level):
         s = repr(obj) # XXX Hope this isn't too slow...
