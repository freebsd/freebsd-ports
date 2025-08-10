--- setup/resources.py.orig	2025-08-08 02:10:36 UTC
+++ setup/resources.py
@@ -104,7 +104,7 @@ class Resources(Command):  # {{{
 class Resources(Command):  # {{{
 
     description = 'Compile various needed calibre resources'
-    sub_commands = ['liberation_fonts', 'mathjax', 'rapydscript', 'hyphenation', 'piper_voices']
+    sub_commands = ['liberation_fonts', 'mathjax', 'rapydscript', 'hyphenation']
 
     def run(self, opts):
         from calibre.utils.serialize import msgpack_dumps
