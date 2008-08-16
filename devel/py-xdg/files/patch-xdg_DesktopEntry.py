--- xdg/DesktopEntry.py.orig	2008-08-16 15:02:12.000000000 -0400
+++ xdg/DesktopEntry.py	2008-08-16 15:02:35.000000000 -0400
@@ -181,7 +181,7 @@ class DesktopEntry(IniFile):
         else:
             #OnlyShowIn and NotShowIn
             if self.content[group].has_key("OnlyShowIn") and self.content[group].has_key("NotShowIn"):
-            self.errors.append("Group may either have OnlyShowIn or NotShowIn, but not both")
+                self.errors.append("Group may either have OnlyShowIn or NotShowIn, but not both")
 
     def checkKey(self, key, value, group):
         # standard keys     
