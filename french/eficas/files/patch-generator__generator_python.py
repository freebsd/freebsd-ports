--- ./generator/generator_python.py.orig	Tue Jan  3 18:02:45 2006
+++ ./generator/generator_python.py	Mon Jan  9 22:53:47 2006
@@ -488,8 +488,8 @@
             s = s + ','
          if len(obj.valeur) > 1:
             s = '(' + s + '),'
-   if obj.nbrColonnes() :
-      s=self.formatColonnes(obj.nbrColonnes(),s)
+         if obj.nbrColonnes() :
+            s=self.formatColonnes(obj.nbrColonnes(),s)
       else :
          val=obj.valeur
          if type(val) == types.InstanceType :
@@ -531,13 +531,13 @@
       #if 1 == 1 :
         liste=text.split(",")
         indice=0
-  textformat=""
+        textformat=""
         while ( indice < len(liste) -2  ) :
           for l in range(nbrColonnes) :
-      textformat=textformat+liste[indice]+","
-      indice=indice+1
-    textformat=textformat+"\n"
-  textformat=textformat+"),"
+            textformat=textformat+liste[indice]+","
+            indice=indice+1
+          textformat=textformat+"\n"
+        textformat=textformat+"),"
       except :
       #else :
          textformat=text
