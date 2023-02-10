--- build/toolchain/gcc_solink_wrapper.py.orig	2022-02-07 13:39:41 UTC
+++ build/toolchain/gcc_solink_wrapper.py
@@ -39,7 +39,7 @@ def CollectDynSym(args):
   """Replaces: nm --format=posix -g -D -p $sofile | cut -f1-2 -d' '"""
   toc = ''
   nm = subprocess.Popen(wrapper_utils.CommandToRun(
-      [args.nm, '--format=posix', '-g', '-D', '-p', args.sofile]),
+      [args.nm, '-g', '-D', '-p', args.sofile]),
                         stdout=subprocess.PIPE,
                         bufsize=-1,
                         universal_newlines=True)
