# Many thanks to Alexander Leidinger <netchild@FreeBSD.org> and
# Franz Klammer <klammer@webonaut.com> for help and create
# those patches.

--- libdesklets/Memory.py.orig	Sun Nov 16 17:02:45 2003
+++ libdesklets/Memory.py	Sun Nov 16 17:03:19 2003
@@ -49,7 +49,7 @@
 
         # Swap
         elif (mode == 1):
-            total, used, free = glibtop.get_mem()[:3]
+            total, used, free = glibtop.get_swap()[:3]
             #for l in lines:
             #    if (l.startswith("SwapTotal:")):
             #        value = l.split()
