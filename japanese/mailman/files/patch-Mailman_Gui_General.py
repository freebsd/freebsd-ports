--- Mailman/Gui/General.py.orig	2011-12-11 07:56:23 UTC
+++ Mailman/Gui/General.py
@@ -1,4 +1,4 @@
-# Copyright (C) 2001-2011 by the Free Software Foundation, Inc.
+# Copyright (C) 2001-2018 by the Free Software Foundation, Inc.
 #
 # This program is free software; you can redistribute it and/or
 # modify it under the terms of the GNU General Public License
@@ -493,6 +493,14 @@ mlist.info.
                                           or not isinstance(val, IntType)):
             doc.addError(_("""<b>admin_member_chunksize</b> attribute not
             changed!  It must be an integer > 0."""))
+        elif property == 'host_name':
+            try:
+                Utils.ValidateEmail('user@' + val)
+            except Errors.EmailAddressError:
+                doc.addError(_("""<b>host_name</b> attribute not changed!
+                It must be a valid domain name."""))
+            else:
+                GUIBase._setValue(self, mlist, property, val, doc)
         else:
             GUIBase._setValue(self, mlist, property, val, doc)
 
