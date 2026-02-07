Only check for the default spelling engine

--- install.py.orig	2018-09-06 12:23:56 UTC
+++ install.py
@@ -251,7 +251,7 @@ def main():
             sys.exit(3)
         global testSpell
         if testSpell:
-            spellCheck(['aspell -a', 'ispell -a', 'hunspell -a'])
+            spellCheck(['%%SPELL_ENGINE%% -a'])
 
     pythonPrefixDir = os.path.join(prefixDir, 'share', progName)
     pythonBuildDir = os.path.join(buildRoot, pythonPrefixDir[1:])
