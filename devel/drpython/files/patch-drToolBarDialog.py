--- drToolBarDialog.py.orig
+++ drToolBarDialog.py
@@ -36,7 +36,7 @@
         text = f.read()
         f.close()
     except:
-        drScrolledMessageDialog.ShowMessage(frame, "File error with: '" + filename + "".", "ERROR")
+        drScrolledMessageDialog.ShowMessage(frame, "File error with: '" + filename + "'.", "ERROR")
         return []
 
         # modified 22/10/2006 Jean-Pierre MANDON
