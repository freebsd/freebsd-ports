--- engine/SCons/Scanner/Prog.py.orig	Wed Feb 16 03:12:11 2005
+++ engine/SCons/Scanner/Prog.py	Tue Mar  1 22:00:50 2005
@@ -89,7 +89,7 @@
             lib = env.subst(lib)
             for pref, suf in pairs:
                 l = adjustixes(lib, pref, suf)
-                l = find_file(l, libpath, fs.File, verbose=print_find_libs)
+                l = find_file(l, libpath, verbose=print_find_libs)
                 if l:
                     result.append(l)
         else:
