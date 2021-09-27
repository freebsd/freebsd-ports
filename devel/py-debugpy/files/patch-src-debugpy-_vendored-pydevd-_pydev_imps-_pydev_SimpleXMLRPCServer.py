--- src/debugpy/_vendored/pydevd/_pydev_imps/_pydev_SimpleXMLRPCServer.py.orig	2021-09-26 20:11:30 UTC
+++ src/debugpy/_vendored/pydevd/_pydev_imps/_pydev_SimpleXMLRPCServer.py
@@ -155,7 +155,7 @@ def remove_duplicates(lst):
     for x in lst:
         u[x] = 1
 
-    return u.keys()
+    return list(u.keys())
 
 class SimpleXMLRPCDispatcher:
     """Mix-in class that dispatches XML-RPC requests.
@@ -260,13 +260,13 @@ class SimpleXMLRPCDispatcher:
             response = (response,)
             response = xmlrpclib.dumps(response, methodresponse=1,
                                        allow_none=self.allow_none, encoding=self.encoding)
-        except Fault, fault:
+        except Fault as fault:
             response = xmlrpclib.dumps(fault, allow_none=self.allow_none,
                                        encoding=self.encoding)
         except:
             # report exception back to server
             response = xmlrpclib.dumps(
-                xmlrpclib.Fault(1, "%s:%s" % (sys.exc_type, sys.exc_value)), #@UndefinedVariable exc_value only available when we actually have an exception
+                xmlrpclib.Fault(1, "%s:%s" % (sys.exc_info()[0], sys.exc_info()[1])), #@UndefinedVariable exc_value only available when we actually have an exception
                 encoding=self.encoding, allow_none=self.allow_none,
                 )
 
@@ -277,7 +277,7 @@ class SimpleXMLRPCDispatcher:
 
         Returns a list of the methods supported by the server."""
 
-        methods = self.funcs.keys()
+        methods = list(self.funcs.keys())
         if self.instance is not None:
             # Instance can implement _listMethod to return a list of
             # methods
@@ -314,7 +314,7 @@ class SimpleXMLRPCDispatcher:
         Returns a string containing documentation for the specified method."""
 
         method = None
-        if self.funcs.has_key(method_name):
+        if method_name in self.funcs:
             method = self.funcs[method_name]
         elif self.instance is not None:
             # Instance can implement _methodHelp to return help for a method
@@ -363,7 +363,7 @@ class SimpleXMLRPCDispatcher:
                 # XXX A marshalling error in any response will fail the entire
                 # multicall. If someone cares they should fix this.
                 results.append([self._dispatch(method_name, params)])
-            except Fault, fault:
+            except Fault as fault:
                 results.append(
                     {'faultCode' : fault.faultCode,
                      'faultString' : fault.faultString}
@@ -371,7 +371,7 @@ class SimpleXMLRPCDispatcher:
             except:
                 results.append(
                     {'faultCode' : 1,
-                     'faultString' : "%s:%s" % (sys.exc_type, sys.exc_value)} #@UndefinedVariable exc_value only available when we actually have an exception
+                     'faultString' : "%s:%s" % (sys.exc_info()[0], sys.exc_info()[1])} #@UndefinedVariable exc_value only available when we actually have an exception
                     )
         return results
 
