--- src/debugpy/_vendored/pydevd/_pydev_imps/_pydev_inspect.py.orig	2021-09-26 20:08:06 UTC
+++ src/debugpy/_vendored/pydevd/_pydev_imps/_pydev_inspect.py
@@ -44,7 +44,7 @@ def isclass(object):
     Class objects provide these attributes:
         __doc__         documentation string
         __module__      name of module in which this class was defined"""
-    return isinstance(object, types.ClassType) or hasattr(object, '__bases__')
+    return isinstance(object, type) or hasattr(object, '__bases__')
 
 def ismethod(object):
     """Return true if the object is an instance method.
@@ -267,7 +267,7 @@ def getdoc(object):
         doc = object.__doc__
     except AttributeError:
         return None
-    if not isinstance(doc, (str, unicode)):
+    if not isinstance(doc, str):
         return None
     try:
         lines = string.split(string.expandtabs(doc), '\n')
@@ -290,30 +290,29 @@ def getfile(object):
     if ismodule(object):
         if hasattr(object, '__file__'):
             return object.__file__
-        raise TypeError, 'arg is a built-in module'
+        raise TypeError('arg is a built-in module')
     if isclass(object):
         object = sys.modules.get(object.__module__)
         if hasattr(object, '__file__'):
             return object.__file__
-        raise TypeError, 'arg is a built-in class'
+        raise TypeError('arg is a built-in class')
     if ismethod(object):
-        object = object.im_func
+        object = object.__func__
     if isfunction(object):
-        object = object.func_code
+        object = object.__code__
     if istraceback(object):
         object = object.tb_frame
     if isframe(object):
         object = object.f_code
     if iscode(object):
         return object.co_filename
-    raise TypeError, 'arg is not a module, class, method, ' \
-                     'function, traceback, frame, or code object'
+    raise TypeError('arg is not a module, class, method, ' \
+                     'function, traceback, frame, or code object')
 
 def getmoduleinfo(path):
     """Get the module name, suffix, mode, and module type for a given file."""
     filename = os.path.basename(path)
-    suffixes = map(lambda (suffix, mode, mtype):
-                   (-len(suffix), suffix, mode, mtype), imp.get_suffixes())
+    suffixes = [(-len(suffix_mode_mtype[0]), suffix_mode_mtype[0], suffix_mode_mtype[1], suffix_mode_mtype[2]) for suffix_mode_mtype in imp.get_suffixes()]
     suffixes.sort() # try longest suffixes first, in case they overlap
     for neglen, suffix, mode, mtype in suffixes:
         if filename[neglen:] == suffix:
@@ -356,12 +355,12 @@ def getmodule(object):
         file = getabsfile(object)
     except TypeError:
         return None
-    if modulesbyfile.has_key(file):
+    if file in modulesbyfile:
         return sys.modules[modulesbyfile[file]]
-    for module in sys.modules.values():
+    for module in list(sys.modules.values()):
         if hasattr(module, '__file__'):
             modulesbyfile[getabsfile(module)] = module.__name__
-    if modulesbyfile.has_key(file):
+    if file in modulesbyfile:
         return sys.modules[modulesbyfile[file]]
     main = sys.modules['__main__']
     if hasattr(main, object.__name__):
@@ -384,7 +383,7 @@ def findsource(object):
     try:
         file = open(getsourcefile(object))
     except (TypeError, IOError):
-        raise IOError, 'could not get source code'
+        raise IOError('could not get source code')
     lines = file.readlines()
     file.close()
 
@@ -396,26 +395,26 @@ def findsource(object):
         pat = re.compile(r'^\s*class\s*' + name + r'\b')
         for i in range(len(lines)):
             if pat.match(lines[i]): return lines, i
-        else: raise IOError, 'could not find class definition'
+        else: raise IOError('could not find class definition')
 
     if ismethod(object):
-        object = object.im_func
+        object = object.__func__
     if isfunction(object):
-        object = object.func_code
+        object = object.__code__
     if istraceback(object):
         object = object.tb_frame
     if isframe(object):
         object = object.f_code
     if iscode(object):
         if not hasattr(object, 'co_firstlineno'):
-            raise IOError, 'could not find function definition'
+            raise IOError('could not find function definition')
         lnum = object.co_firstlineno - 1
         pat = re.compile(r'^(\s*def\s)|(.*\slambda(:|\s))')
         while lnum > 0:
             if pat.match(lines[lnum]): break
             lnum = lnum - 1
         return lines, lnum
-    raise IOError, 'could not find code object'
+    raise IOError('could not find code object')
 
 def getcomments(object):
     """Get lines of comments immediately preceding an object's source code."""
@@ -479,7 +478,9 @@ class BlockFinder:
         self.started = 0
         self.last = 0
 
-    def tokeneater(self, type, token, (srow, scol), (erow, ecol), line):
+    def tokeneater(self, type, token, xxx_todo_changeme, xxx_todo_changeme1, line):
+        (srow, scol) = xxx_todo_changeme
+        (erow, ecol) = xxx_todo_changeme1
         if not self.started:
             if type == tokenize.NAME: self.started = 1
         elif type == tokenize.NEWLINE:
@@ -488,15 +489,15 @@ class BlockFinder:
             self.indent = self.indent + 1
         elif type == tokenize.DEDENT:
             self.indent = self.indent - 1
-            if self.indent == 0: raise EndOfBlock, self.last
+            if self.indent == 0: raise EndOfBlock(self.last)
         elif type == tokenize.NAME and scol == 0:
-            raise EndOfBlock, self.last
+            raise EndOfBlock(self.last)
 
 def getblock(lines):
     """Extract the block of code at the top of the given list of lines."""
     try:
         tokenize.tokenize(ListReader(lines).readline, BlockFinder().tokeneater)
-    except EndOfBlock, eob:
+    except EndOfBlock as eob:
         return lines[:eob.args[0]]
     # Fooling the indent/dedent logic implies a one-line definition
     return lines[:1]
@@ -530,7 +531,7 @@ def walktree(classes, children, parent):
     classes.sort(lambda a, b: cmp(a.__name__, b.__name__))
     for c in classes:
         results.append((c, c.__bases__))
-        if children.has_key(c):
+        if c in children:
             results.append(walktree(children[c], children, c))
     return results
 
@@ -548,13 +549,13 @@ def getclasstree(classes, unique=0):
     for c in classes:
         if c.__bases__:
             for parent in c.__bases__:
-                if not children.has_key(parent):
+                if parent not in children:
                     children[parent] = []
                 children[parent].append(c)
                 if unique and parent in classes: break
         elif c not in roots:
             roots.append(c)
-    for parent in children.keys():
+    for parent in list(children.keys()):
         if parent not in classes:
             roots.append(parent)
     return walktree(roots, children, None)
@@ -569,7 +570,7 @@ def getargs(co):
     Three things are returned: (args, varargs, varkw), where 'args' is
     a list of argument names (possibly containing nested lists), and
     'varargs' and 'varkw' are the names of the * and ** arguments or None."""
-    if not iscode(co): raise TypeError, 'arg is not a code object'
+    if not iscode(co): raise TypeError('arg is not a code object')
 
     nargs = co.co_argcount
     names = co.co_varnames
@@ -622,10 +623,10 @@ def getargspec(func):
     'varargs' and 'varkw' are the names of the * and ** arguments or None.
     'defaults' is an n-tuple of the default values of the last n arguments."""
     if ismethod(func):
-        func = func.im_func
-    if not isfunction(func): raise TypeError, 'arg is not a Python function'
-    args, varargs, varkw = getargs(func.func_code)
-    return args, varargs, varkw, func.func_defaults
+        func = func.__func__
+    if not isfunction(func): raise TypeError('arg is not a Python function')
+    args, varargs, varkw = getargs(func.__code__)
+    return args, varargs, varkw, func.__defaults__
 
 def getargvalues(frame):
     """Get information about arguments passed into a particular frame.
@@ -645,8 +646,8 @@ def joinseq(seq):
 
 def strseq(object, convert, join=joinseq):
     """Recursively walk a sequence, stringifying each element."""
-    if type(object) in [types.ListType, types.TupleType]:
-        return join(map(lambda o, c=convert, j=join: strseq(o, c, j), object))
+    if type(object) in [list, tuple]:
+        return join(list(map(lambda o, c=convert, j=join: strseq(o, c, j), object)))
     else:
         return convert(object)
 
@@ -785,4 +786,4 @@ def stack(context=1):
 
 def trace(context=1):
     """Return a list of records for the stack below the current exception."""
-    return getinnerframes(sys.exc_traceback, context) #@UndefinedVariable
+    return getinnerframes(sys.exc_info()[2], context) #@UndefinedVariable
