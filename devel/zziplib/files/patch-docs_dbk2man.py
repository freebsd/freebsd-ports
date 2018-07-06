--- docs/dbk2man.py.orig	2018-03-16 11:55:55 UTC
+++ docs/dbk2man.py
@@ -1,4 +1,4 @@
-#!/usr/local/bin/python2.7
+#! /usr/bin/python
 """ Converts an xml-file with docbook elements into troff manual pages.
     The conversion uses etree expecting <refentry> elements in the input.
     The output goes to a multiple files in manX/* subdirectories.
@@ -223,22 +223,23 @@ def refentry2man(refentry, subdirectory 
         if found is not None: manvolnum = found.text
     written = 0
     section = refentry.find("refnamediv")
-    for refname in section.findall("refname"):
-        if not refentrytitle:
-            refentrytitle = refname.text
-        manpage = refname.text
-        filename = "%s/man%s/%s.%s" % (subdirectory, manvolnum, manpage, manvolnum)
-        if manpage != refentrytitle:
-            manpagetext = ".so %s.%s\n" % (refentrytitle, manvolnum)
-            writefile(filename, manpagetext)
-        else:
-            manpagetext = text
+    if section is not None:
+        for refname in section.findall("refname"):
+            if not refentrytitle:
+                refentrytitle = refname.text
+            manpage = refname.text
+            filename = "%s/man%s/%s.%s" % (subdirectory, manvolnum, manpage, manvolnum)
+            if manpage != refentrytitle:
+                manpagetext = ".so %s.%s\n" % (refentrytitle, manvolnum)
+                writefile(filename, manpagetext)
+            else:
+                manpagetext = text
+                writefile(filename, manpagetext)
+                written += 1
+        if not written:
+            manpage = refentrytitle
+            filename = "%s/man%s/%s.%s" % (subdirectory, manvolnum, manpage, manvolnum)
             writefile(filename, manpagetext)
-            written += 1
-    if not written:
-        manpage = refentrytitle
-        filename = "%s/man%s/%s.%s" % (subdirectory, manvolnum, manpage, manvolnum)
-        writefile(filename, manpagetext)
 
 def writefile(filename, manpagetext):
     dirname = os.path.dirname(filename)
