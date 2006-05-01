--- src/Resources.py	Mon Jan 30 20:17:48 2006
+++ src/Resources.py	Mon Jan 30 20:18:40 2006
@@ -37,15 +37,15 @@
         sep = r'\\'
     base = re.sub(r'/', sep, base)
     name = re.sub(r'/', sep, name)   
-    result = os.path.join("data", campaign, base, name)
+    result = os.path.join("%%DATADIR%%", campaign, base, name)
     if os.path.exists(result):
         logger.debug('found ' + result)
         return result
-    result = os.path.join("data", "extra", base, name)
+    result = os.path.join("%%DATADIR%%", "extra", base, name)
     if os.path.exists(result):
         logger.debug('found ' + result)
         return result
-    result = os.path.join("data", "core", base, name)
+    result = os.path.join("%%DATADIR%%", "core", base, name)
     if os.path.exists(result):
         logger.debug('found ' + result)
         return result
