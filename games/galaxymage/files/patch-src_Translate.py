--- src/Translate.py	Mon Jan 30 20:20:01 2006
+++ src/Translate.py	Mon Jan 30 20:21:30 2006
@@ -4,7 +4,7 @@
 class Translate:
        
     def getLanguageDict(self,lang):
-        return gettext.translation('GalaxyMage',os.path.join(os.getcwd(),'locale'), languages=[lang])
+        return gettext.translation('GalaxyMage',os.path.join('%%X11BASE%%/share/locale'), languages=[lang])
     
     def __init__(self):       
         #fill our language dictionnary with each language
