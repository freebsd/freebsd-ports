--- locale/install_locales.py.orig	Sun Aug 31 23:07:07 2003
+++ locale/install_locales.py	Sun Aug 31 23:07:33 2003
@@ -17,7 +17,7 @@
     file = os.path.basename(source)
     lang, ext = os.path.splitext(file)
     fulltargetpath = os.path.join(targetpath, lang, "LC_MESSAGES")
-    os.system("mkdir --parents " + fulltargetpath)
+    os.system("mkdir -p " + fulltargetpath)
     
     print (source)
     mofile = os.path.join(fulltargetpath, domain + ".mo")
