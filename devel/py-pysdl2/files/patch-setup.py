--- setup.py.orig	2023-06-28 14:26:02 UTC
+++ setup.py
@@ -15,7 +15,7 @@ if __name__ == "__main__":
         long_desc = re.sub(r"\[!\[Build Status(.*?)\n", "", long_desc)
 
     setupdata = {
-        "name":  "PySDL2",
+        "name":  "pysdl2",
         "version": VERSION,
         "description": "Python SDL2 bindings",
         "long_description": long_desc,
