--- Mailman/Cgi/options.py.orig	2011-12-11 07:56:23 UTC
+++ Mailman/Cgi/options.py
@@ -1,4 +1,4 @@
-# Copyright (C) 1998-2011 by the Free Software Foundation, Inc.
+# Copyright (C) 1998-2018 by the Free Software Foundation, Inc.
 #
 # This program is free software; you can redistribute it and/or
 # modify it under the terms of the GNU General Public License
@@ -165,20 +165,6 @@ def main():
     doc.set_language(userlang)
     i18n.set_language(userlang)
 
-    # See if this is VARHELP on topics.
-    varhelp = None
-    if cgidata.has_key('VARHELP'):
-        varhelp = cgidata['VARHELP'].value
-    elif os.environ.get('QUERY_STRING'):
-        # POST methods, even if their actions have a query string, don't get
-        # put into FieldStorage's keys :-(
-        qs = cgi.parse_qs(os.environ['QUERY_STRING']).get('VARHELP')
-        if qs and type(qs) == types.ListType:
-            varhelp = qs[0]
-    if varhelp:
-        topic_details(mlist, doc, user, cpuser, userlang, varhelp)
-        return
-
     # Are we processing an unsubscription request from the login screen?
     if cgidata.has_key('login-unsub'):
         # Because they can't supply a password for unsubscribing, we'll need
@@ -290,6 +276,22 @@ def main():
         print doc.Format()
         return
 
+    # See if this is VARHELP on topics.
+    varhelp = None
+    if cgidata.has_key('VARHELP'):
+        varhelp = cgidata['VARHELP'].value
+    elif os.environ.get('QUERY_STRING'):
+        # POST methods, even if their actions have a query string, don't get
+        # put into FieldStorage's keys :-(
+        qs = cgi.parse_qs(os.environ['QUERY_STRING']).get('VARHELP')
+        if qs and type(qs) == types.ListType:
+            varhelp = qs[0]
+    if varhelp:
+        # Sanitize the topic name.
+        varhelp = re.sub('<.*', '', varhelp)
+        topic_details(mlist, doc, user, cpuser, userlang, varhelp)
+        return
+
     if cgidata.has_key('logout'):
         print mlist.ZapCookie(mm_cfg.AuthUser, user)
         loginpage(mlist, doc, user, language)
