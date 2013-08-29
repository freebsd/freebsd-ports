Add support for Python 3.x
Taken from https://github.com/mitsuhiko/speaklater/pull/3 - commit #62dd88e

--- ./speaklater.py.orig	2010-10-17 15:03:41.000000000 +0000
+++ ./speaklater.py	2013-08-11 11:19:18.000000000 +0000
@@ -12,24 +12,24 @@
 
     Example:
 
-    >>> from speaklater import make_lazy_string
+    >>> from speaklater import make_lazy_string, text_type
     >>> sval = u'Hello World'
     >>> string = make_lazy_string(lambda: sval)
 
     This lazy string will evaluate to the value of the `sval` variable.
 
     >>> string
-    lu'Hello World'
-    >>> unicode(string)
-    u'Hello World'
-    >>> string.upper()
-    u'HELLO WORLD'
+    l'Hello World'
+    >>> text_type(string) == u'Hello World'
+    True
+    >>> string.upper() == u'HELLO WORLD'
+    True
 
     If you change the value, the lazy string will change as well:
 
     >>> sval = u'Hallo Welt'
-    >>> string.upper()
-    u'HALLO WELT'
+    >>> string.upper() == u'HALLO WELT'
+    True
 
     This is especially handy when combined with a thread local and gettext
     translations or dicts of translatable strings:
@@ -40,10 +40,10 @@
     >>> l.translations = {u'Yes': 'Ja'}
     >>> lazy_gettext = make_lazy_gettext(lambda: l.translations.get)
     >>> yes = lazy_gettext(u'Yes')
-    >>> print yes
+    >>> print(yes)
     Ja
     >>> l.translations[u'Yes'] = u'Si'
-    >>> print yes
+    >>> print(yes)
     Si
 
     Lazy strings are no real strings so if you pass this sort of string to
@@ -59,6 +59,9 @@
     >>> is_lazy_string(yes)
     True
 
+    New in version 1.4: python >= 3.3 (and also 2.6 and 2.7) support,
+                        repr(lazystring) is l"foo" on py2 and py3 - no "u" on py2!
+
     New in version 1.2: It's now also possible to pass keyword arguments to
     the callback used with `make_lazy_string`.
 
@@ -66,6 +69,28 @@
     :license: BSD, see LICENSE for more details.
 """
 
+import sys
+
+PY2 = sys.version_info[0] == 2
+_identity = lambda x: x
+
+if not PY2:
+    text_type = str
+    implements_to_string = _identity
+    implements_bool = _identity
+else:
+    text_type = unicode
+
+    def implements_to_string(cls):
+        cls.__unicode__ = cls.__str__
+        cls.__str__ = lambda x: x.__unicode__().encode('utf-8')
+        return cls
+
+    def implements_bool(cls):
+        cls.__nonzero__ = cls.__bool__
+        del cls.__bool__
+        return cls
+
 
 def is_lazy_string(obj):
     """Checks if the given object is a lazy string."""
@@ -87,10 +112,10 @@
     >>> lazy_gettext = make_lazy_gettext(lambda: translations.get)
     >>> x = lazy_gettext(u'Yes')
     >>> x
-    lu'Ja'
+    l'Ja'
     >>> translations[u'Yes'] = u'Si'
     >>> x
-    lu'Si'
+    l'Si'
     """
     def lazy_gettext(string):
         if is_lazy_string(string):
@@ -99,6 +124,8 @@
     return lazy_gettext
 
 
+@implements_bool
+@implements_to_string
 class _LazyString(object):
     """Class for strings created by a function call.
 
@@ -117,11 +144,11 @@
     def __contains__(self, key):
         return key in self.value
 
-    def __nonzero__(self):
+    def __bool__(self):
         return bool(self.value)
 
     def __dir__(self):
-        return dir(unicode)
+        return dir(text_type)
 
     def __iter__(self):
         return iter(self.value)
@@ -130,10 +157,7 @@
         return len(self.value)
 
     def __str__(self):
-        return str(self.value)
-
-    def __unicode__(self):
-        return unicode(self.value)
+        return text_type(self.value)
 
     def __add__(self, other):
         return self.value + other
@@ -190,7 +214,10 @@
 
     def __repr__(self):
         try:
-            return 'l' + repr(self.value)
+            r = repr(self.value)
+            if PY2 and r.startswith('u'):
+                r = r[1:]  # make it look same as on py3
+            return 'l' + r
         except Exception:
             return '<%s broken>' % self.__class__.__name__
 
