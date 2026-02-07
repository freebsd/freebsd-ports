The spelling engine is not configurable at runtime and the program uses the
first one it comes across. This change sets a default to check first based
on the engine selected in the port options.

--- source/spellcheck.py.orig	2018-04-08 19:19:50 UTC
+++ source/spellcheck.py
@@ -44,6 +44,12 @@ class SpellCheckInterface:
                               ('ispell', ['-a -h -Tutf8', '-a']),
                               ('hunspell', ['-a -H -i utf-8'])])
         langPrefix = {'aspell': 'l', 'ispell': 'd', 'hunspell': 'd'}
+        
+        """Set the default engine and check it first
+        """
+        defaultEngine = '%%SPELL_ENGINE%%'
+        engineOptions.move_to_end(defaultEngine, last=False)
+
         if spellPath:
             newEngineOptions = {}
             for engine in engineOptions.keys():
