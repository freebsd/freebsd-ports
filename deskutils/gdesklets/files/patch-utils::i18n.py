--- utils/i18n.py.orig	Sun Jan  4 13:56:21 2004
+++ utils/i18n.py	Sun Jan  4 14:26:10 2004
@@ -12,6 +12,9 @@
         translate = gettext.translation(domain, localedir).gettext
 
     except:
-        translate = dummy
+	try:
+	   translate = gettext.translation("gdesklets", localedir).gettext
+	except:
+           translate = dummy
 
     return translate
