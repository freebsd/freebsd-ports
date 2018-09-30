FreeBSD ps(1) does not have "cmd" display format like in linuxes, but
"args" is equivalent.

--- gtweak/tweaks/tweak_group_startup.py.orig	2015-10-26 16:48:16 UTC
+++ gtweak/tweaks/tweak_group_startup.py
@@ -334,7 +334,7 @@ class AutostartListBoxTweakGroup(ListBox
         exes = []
         cmd = subprocess.Popen([
                     'ps','-e','-w','-w','-U',
-                    str(os.getuid()),'-o','cmd'],
+                    str(os.getuid()),'-o','args'],
                     stdout=subprocess.PIPE)
         out = cmd.communicate()[0]
         for l in out.split('\n'):
