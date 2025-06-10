FreeBSD ps(1) does not have "cmd" display format like in linuxes, but
"args" is equivalent.

--- gtweak/tweaks/tweak_group_startup.py.orig	2024-04-26 06:06:48 UTC
+++ gtweak/tweaks/tweak_group_startup.py
@@ -335,7 +335,7 @@ class AutostartTweakGroup(Adw.PreferencesPage, TweakGr
         exes = set()
         cmd = subprocess.Popen([
             'ps', '-e', '-w', '-w', '-U',
-            str(os.getuid()), '-o', 'cmd'],
+            str(os.getuid()), '-o', 'args'],
             stdout=subprocess.PIPE)
         out = cmd.communicate()[0]
         for process in out.decode('utf8').split('\n'):
