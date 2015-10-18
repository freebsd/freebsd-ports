--- drToolBarDialog.py.orig	2014-04-20 17:50:40 UTC
+++ drToolBarDialog.py
@@ -36,7 +36,7 @@ def GetToolBarLabels(filename, frame):
         text = f.read()
         f.close()
     except:
-        drScrolledMessageDialog.ShowMessage(frame, "File error with: '" + filename + "".", "ERROR")
+        drScrolledMessageDialog.ShowMessage(frame, "File error with: '" + filename + "'.", "ERROR")
         return []
 
         # modified 22/10/2006 Jean-Pierre MANDON
