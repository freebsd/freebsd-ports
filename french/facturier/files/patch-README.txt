--- README.txt.orig	Fri Jan 31 16:52:00 2003
+++ README.txt	Fri Jan 31 22:43:57 2003
@@ -64,13 +64,13 @@
 	4) installer la base de donnée FACTURIER:
 	pour cela,  se mettre dans le répertoire sql, puis
 	lancer la commande:
-	mysql  -uuser  -hhost_name  -ppassword > fact.sql
+	mysql  -uuser  -hhost_name  -ppassword < fact.sql
 	où :-user est le login d'un utilisateur pouvant utiliser mysql, et y créer des bases,
 		-password, son mot de passe
 		-host-name = nom du serveur hébergeant mysql
 		par exemple si user = 'toto',  son mot de passe = 'titi' et le serveur = 'www.serveur',
 		faire:
-	mysql -utoto -hwww.serveur -ptiti > fact.sql
+	mysql -utoto -hwww.serveur -ptiti < fact.sql
 
 	La base de donnée installée ne contient qu'un enregistrement. Cet enregistrement
 	concerne un utilisateur : l'utilisateur de login 'admin' et de mot de passe 'ungi99', qui
