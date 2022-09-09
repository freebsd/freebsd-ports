--- src/showdown.vala.orig	2022-08-26 16:08:34 UTC
+++ src/showdown.vala
@@ -11,7 +11,7 @@ class Showdown.Application: Gtk.Application {
         {"quit", quit},
     };
 
-    public const OptionEntry[] options = {
+    const OptionEntry[] options = {
         {
             "open-in-current-window", 'w', 0,
             OptionArg.FILENAME, ref wflag,
