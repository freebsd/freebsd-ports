--- peak/util/decorators.py.orig	2010-05-05 06:03:34 UTC
+++ peak/util/decorators.py
@@ -103,7 +103,7 @@ def %(wrapname)s(%(wrapspec)s):
     
     filename = "<%s wrapping %s at 0x%08X>" % (qname(wrapper), qname(func), id(func))
     d ={}
-    exec compile(body, filename, "exec") in func.func_globals, d
+    exec(compile(body, filename, "exec"), func.func_globals, d)
 
     f = d[wrapname](func, *args, **kw)
     cache_source(filename, body, f)
