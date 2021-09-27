--- src/debugpy/_vendored/pydevd/_pydevd_bundle/pydevconsole_code_for_ironpython.py.orig	2021-09-26 20:08:05 UTC
+++ src/debugpy/_vendored/pydevd/_pydevd_bundle/pydevconsole_code_for_ironpython.py
@@ -102,23 +102,23 @@ def _maybe_compile(compiler, source, filename, symbol)
 
     try:
         code = compiler(source, filename, symbol)
-    except SyntaxError, err:
+    except SyntaxError as err:
         pass
 
     try:
         code1 = compiler(source + "\n", filename, symbol)
-    except SyntaxError, err1:
+    except SyntaxError as err1:
         pass
 
     try:
         code2 = compiler(source + "\n\n", filename, symbol)
-    except SyntaxError, err2:
+    except SyntaxError as err2:
         pass
 
     if code:
         return code
     if not code1 and repr(err1) == repr(err2):
-        raise SyntaxError, err1
+        raise SyntaxError(err1)
 
 def _compile(source, filename, symbol):
     return compile(source, filename, symbol, PyCF_DONT_IMPLY_DEDENT)
@@ -302,7 +302,7 @@ class InteractiveInterpreter:
 
         """
         try:
-            exec code in self.locals
+            exec(code, self.locals)
         except SystemExit:
             raise
         except:
@@ -338,7 +338,7 @@ class InteractiveInterpreter:
                 value = SyntaxError(msg, (filename, lineno, offset, line))
                 sys.last_value = value
         list = traceback.format_exception_only(type, value)
-        map(self.write, list)
+        list(map(self.write, list))
 
     def showtraceback(self, *args, **kwargs):
         """Display the exception that just occurred.
@@ -361,7 +361,7 @@ class InteractiveInterpreter:
             list[len(list):] = traceback.format_exception_only(type, value)
         finally:
             tblist = tb = None
-        map(self.write, list)
+        list(map(self.write, list))
 
     def write(self, data):
         """Write a string.
@@ -436,7 +436,7 @@ class InteractiveConsole(InteractiveInterpreter):
                     line = self.raw_input(prompt)
                     # Can be None if sys.stdin was redefined
                     encoding = getattr(sys.stdin, "encoding", None)
-                    if encoding and not isinstance(line, unicode):
+                    if encoding and not isinstance(line, str):
                         line = line.decode(encoding)
                 except EOFError:
                     self.write("\n")
@@ -480,7 +480,7 @@ class InteractiveConsole(InteractiveInterpreter):
         implementation.
 
         """
-        return raw_input(prompt)
+        return input(prompt)
 
 
 def interact(banner=None, readfunc=None, local=None):
