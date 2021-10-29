--- dump_symbols.py.orig	2021-05-24 10:47:30 UTC
+++ dump_symbols.py
@@ -4,22 +4,15 @@ from path import Path
 
 prefix = sys.argv[1]
 
-prefix_mac = (Path(prefix) / 'lib_mac').expand()
-libs_mac = prefix_mac.glob('**/libTK*.7.5.1.dylib')
+prefix_freebsd = (Path(prefix) / 'lib').expand()
+libs_freebsd = prefix_freebsd.glob('libTK*.so')
 
-prefix_linux = (Path(prefix) / 'lib_linux').expand()
-libs_linux = prefix_linux.glob('**/libTK*.so.7.5.1')
+for name,libs in {'freebsd' : libs_freebsd}.items():
 
-prefix_win = (Path(prefix) / 'lib_win').expand()
-libs_win = prefix_win.glob('**/**/TK*.dll')
-
-
-for name,libs in {'linux' : libs_linux,'mac' : libs_mac, 'win' : libs_win}.items():
-
     exported_symbols = []
     
     for lib in libs:
-        p = lief.parse(lib)
+        p = lief.parse(str(lib))
         
         if name=='linux':
             for s in p.exported_symbols:
