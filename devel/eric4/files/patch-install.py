--- install.py~	2013-02-18 20:06:18.000000000 +0200
+++ install.py	2013-02-18 20:07:37.000000000 +0200
@@ -1030,7 +1030,7 @@
                 res = raw_input("    Shall pyXML be patched now (y/n)? ")
                 if res in ["Y", "y"]:
                     patchPyXML()
-    except ImportError:
+    except (ImportError, EOFError):
         pass
     
     #check version of PyQt
