Index: Lib/SimpleXMLRPCServer.py
===================================================================
RCS file: /cvsroot/python/python/dist/src/Lib/SimpleXMLRPCServer.py,v
retrieving revision 1.7.8.1
diff -c -r1.7.8.1 SimpleXMLRPCServer.py
*** Lib/SimpleXMLRPCServer.py	3 Oct 2004 23:23:00 -0000	1.7.8.1
--- Lib/SimpleXMLRPCServer.py	3 Feb 2005 05:33:55 -0000
***************
*** 107,120 ****
  import types
  import os
  
! def resolve_dotted_attribute(obj, attr):
      """resolve_dotted_attribute(a, 'b.c.d') => a.b.c.d
  
      Resolves a dotted attribute name to an object.  Raises
      an AttributeError if any attribute in the chain starts with a '_'.
      """
  
!     for i in attr.split('.'):
          if i.startswith('_'):
              raise AttributeError(
                  'attempt to access private attribute "%s"' % i
--- 107,128 ----
  import types
  import os
  
! def resolve_dotted_attribute(obj, attr, allow_dotted_names=True):
      """resolve_dotted_attribute(a, 'b.c.d') => a.b.c.d
  
      Resolves a dotted attribute name to an object.  Raises
      an AttributeError if any attribute in the chain starts with a '_'.
+ 
+     If the optional allow_dotted_names argument is false, dots are not
+     supported and this function operates similar to getattr(obj, attr).
      """
  
!     if allow_dotted_names:
!         attrs = attr.split('.')
!     else:
!         attrs = [attr]
! 
!     for i in attrs:
          if i.startswith('_'):
              raise AttributeError(
                  'attempt to access private attribute "%s"' % i
***************
*** 156,162 ****
          self.funcs = {}
          self.instance = None
  
!     def register_instance(self, instance):
          """Registers an instance to respond to XML-RPC requests.
  
          Only one instance can be installed at a time.
--- 164,170 ----
          self.funcs = {}
          self.instance = None
  
!     def register_instance(self, instance, allow_dotted_names=False):
          """Registers an instance to respond to XML-RPC requests.
  
          Only one instance can be installed at a time.
***************
*** 174,182 ****
--- 182,204 ----
  
          If a registered function matches a XML-RPC request, then it
          will be called instead of the registered instance.
+ 
+         If the optional allow_dotted_names argument is true and the
+         instance does not have a _dispatch method, method names
+         containing dots are supported and resolved, as long as none of
+         the name segments start with an '_'.
+ 
+             *** SECURITY WARNING: ***
+ 
+             Enabling the allow_dotted_names options allows intruders
+             to access your module's global variables and may allow
+             intruders to execute arbitrary code on your machine.  Only
+             use this option on a secure, closed network.
+ 
          """
  
          self.instance = instance
+         self.allow_dotted_names = allow_dotted_names
  
      def register_function(self, function, name = None):
          """Registers a function to respond to XML-RPC requests.
***************
*** 295,301 ****
                  try:
                      method = resolve_dotted_attribute(
                                  self.instance,
!                                 method_name
                                  )
                  except AttributeError:
                      pass
--- 317,324 ----
                  try:
                      method = resolve_dotted_attribute(
                                  self.instance,
!                                 method_name,
!                                 self.allow_dotted_names
                                  )
                  except AttributeError:
                      pass
***************
*** 374,380 ****
                      try:
                          func = resolve_dotted_attribute(
                              self.instance,
!                             method
                              )
                      except AttributeError:
                          pass
--- 397,404 ----
                      try:
                          func = resolve_dotted_attribute(
                              self.instance,
!                             method,
!                             self.allow_dotted_names
                              )
                      except AttributeError:
                          pass
