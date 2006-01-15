--- Editeur/change_comm.py.orig	Tue Jan  3 18:02:45 2006
+++ Editeur/change_comm.py	Wed Jan 11 23:54:17 2006
@@ -80,9 +80,9 @@
          p=convert.plugins[format]()
          p.readfile(fichier)
          text=p.convert('exec',self)
-         if not p.cr.estvide(): 
-      print ("Erreur à la conversion")
-      print str(p.cr)
+         if not p.cr.estvide() :
+            print ("Erreur à la conversion")
+            print str(p.cr)
             return
 
       # On se met dans le repertoire ou se trouve le fichier de commandes
@@ -108,33 +108,33 @@
           self.JDC=J
 
    def modifieJDC(self,texte):
-         if texte == None or texte == "" : return
-         format="python"
-   lignes=string.split(texte,";")
-   textedecoup=""
-   for l in lignes :
-      textedecoup=textedecoup+l+'\n'
+      if texte == None or texte == "" : return
+      format="python"
+      lignes=string.split(texte,";")
+      textedecoup=""
+      for l in lignes :
+         textedecoup=textedecoup+l+'\n'
          if convert.plugins.has_key(format):
             p=convert.plugins[format]()
             p.settext(textedecoup)
             text=p.convert('exec',self)
       print text
-         if not p.cr.estvide(): 
-      print ("Erreur à la conversion")
-      print str(p.cr)
+      if not p.cr.estvide() :
+            print ("Erreur à la conversion")
+            print str(p.cr)
             return
-         self.J2=self.cata[0].JdC(procedure=text,appli=self,
+      self.J2=self.cata[0].JdC(procedure=text,appli=self,
                          cata=self.cata,
-         cata_ord_dico=self.readercata.cata_ordonne_dico,
+      cata_ord_dico=self.readercata.cata_ordonne_dico,
                          nom = self.JDCName+"2",
                          rep_mat=self.CONFIGURATION.rep_mat,
                          )
-   self.J2.definition.code = "MODIF"
-         self.J2.analyse()
-     
+      self.J2.definition.code = "MODIF"
+      self.J2.analyse()
+
 
    def saveJDC(self,fichierSortie):
-      """ 
+      """
           Sauvegarde le JDC courant.
           Retourne 1 si la sauvegarde s'est bien faite, 0 sinon.
       """
@@ -155,7 +155,7 @@
       self.jdc_fini = string.replace(jdc_formate,'\r\n','\n')
 
       if not save_in_file(fichierSortie,self.jdc_fini) :
-   self.affiche_infos("Problème à la sauvegarde du fichier")
+         self.affiche_infos("Problème à la sauvegarde du fichier")
          return 0
       else :
          self.affiche_infos("sauvegarde effectuée")
@@ -164,4 +164,4 @@
 
    def affiche_infos(self,mess):
        print mess
-          
+
