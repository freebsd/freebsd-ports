--- share/plug-ins/dispatching.py.orig	2014-11-13 18:15:57 UTC
+++ share/plug-ins/dispatching.py
@@ -35,11 +35,8 @@ class Dispatching_Highlighter(Location_H
         GPS.Hook("file_edited").add(self.__on_file_edited)
         GPS.Hook("file_changed_on_disk").add(self.__on_file_edited)
 
-        if GPS.Logger("ENTITIES.SQLITE").active:
-            GPS.Hook("xref_updated").add(self.__on_compilation_finished)
-        else:
-            GPS.Hook("compilation_finished").add(
-                self.__on_compilation_finished)
+        GPS.Hook("compilation_finished").add(
+            self.__on_compilation_finished)
 
     def __del__(self):
         Location_Highlighter.__del__(self)
@@ -47,11 +44,8 @@ class Dispatching_Highlighter(Location_H
         GPS.Hook("file_edited").remove(self.__on_file_edited)
         GPS.Hook("file_changed_on_disk").remove(self.__on_file_edited)
 
-        if GPS.Logger("ENTITIES.SQLITE").active:
-            GPS.Hook("xref_updated").remove(self.__on_compilation_finished)
-        else:
-            GPS.Hook("compilation_finished").remove(
-                self.__on_compilation_finished)
+        GPS.Hook("compilation_finished").remove(
+            self.__on_compilation_finished)
 
     def __on_preferences_changed(self, hook):
         changed = False
