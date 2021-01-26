--- IPython/core/completer.py.orig	2020-10-30 18:09:09 UTC
+++ IPython/core/completer.py
@@ -988,8 +988,18 @@ def _make_signature(completion)-> str:
 
     """
 
-    return '(%s)'% ', '.join([f for f in (_formatparamchildren(p) for p in completion.params) if f])
+    # it looks like this might work on jedi 0.17
+    if hasattr(completion, 'get_signatures'):
+        signatures = completion.get_signatures()
+        if not signatures:
+            return  '(?)'
 
+        c0 = completion.get_signatures()[0]
+        return '('+c0.to_string().split('(', maxsplit=1)[1]
+
+    return '(%s)'% ', '.join([f for f in (_formatparamchildren(p) for signature in completion.get_signatures()
+                                          for p in signature.defined_names()) if f])
+
 class IPCompleter(Completer):
     """Extension of the completer class with IPython-specific features"""
 
@@ -1370,8 +1380,7 @@ class IPCompleter(Completer):
                 else:
                     raise ValueError("Don't understand self.omit__names == {}".format(self.omit__names))
 
-        interpreter = jedi.Interpreter(
-            text[:offset], namespaces, column=cursor_column, line=cursor_line + 1)
+        interpreter = jedi.Interpreter(text[:offset], namespaces)
         try_jedi = True
 
         try:
@@ -1398,7 +1407,7 @@ class IPCompleter(Completer):
         if not try_jedi:
             return []
         try:
-            return filter(completion_filter, interpreter.completions())
+            return filter(completion_filter, interpreter.complete(column=cursor_column, line=cursor_line + 1))
         except Exception as e:
             if self.debug:
                 return [_FakeJediCompletion('Oops Jedi has crashed, please report a bug with the following:\n"""\n%s\ns"""' % (e))]
