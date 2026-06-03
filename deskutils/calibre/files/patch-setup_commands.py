--- setup/commands.py.orig	2025-08-08 02:10:36 UTC
+++ setup/commands.py
@@ -30,7 +30,6 @@ __all__ = [
     'manual',
     'mathjax',
     'osx',
-    'piper_voices',
     'pot',
     'publish',
     'publish_betas',
@@ -93,10 +92,6 @@ hyphenation = Hyphenation()
 from setup.hyphenation import Hyphenation
 
 hyphenation = Hyphenation()
-
-from setup.piper import PiperVoices
-
-piper_voices = PiperVoices()
 
 from setup.liberation import LiberationFonts
 
