--- Mailman/Cgi/admin.py.orig	2011-12-11 07:56:23 UTC
+++ Mailman/Cgi/admin.py
@@ -266,7 +266,7 @@ def admin_overview(msg=''):
             else:
                 advertised.append((mlist.GetScriptURL('admin'),
                                    mlist.real_name,
-                                   mlist.description))
+                                   Utils.websafe(mlist.description)))
     # Greeting depends on whether there was an error or not
     if msg:
         greeting = FontAttr(msg, color="ff5060", size="+1")
