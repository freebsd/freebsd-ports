--- lib/Conf.pm.orig	Sat Feb  1 15:54:45 2003
+++ lib/Conf.pm	Sat Feb  1 16:32:36 2003
@@ -58,28 +58,28 @@
 
 #$CONNECTBDD est la variable de connection à la base de donnée
 #remplacer 'host_name' par l'adresse de la machine où tourne le serveur MySQL
- $CONNECTBDD = "dbi:mysql:FACTURIER:host_name";
+ $CONNECTBDD = "dbi:mysql:FACTURIER:localhost";
 
 
  
 #$USERBDD à pour valeur le login d'un utilisateur pouvant se connecter
 #à la base de donnée  'FACTURIER' sur le serveur MySQL 
- #remplacer 'user' par le login d'un utilisateur ayant le droit d'utiliser
+ #remplacer '%%DBOWN%%' par le login d'un utilisateur ayant le droit d'utiliser
  #la base de donnée 'facturier' sur le serveur MySQL
- $USERBDD="user";
+ $USERBDD="%%DBOWN%%";
  
  
  #$MDPBDD contient la valeur du mot de passe de connection de l'utilisateur
  #$USERBDD au serveur MySQL
- #remplacer 'password' par le mot de passe du login de l'utilisateur
+ #remplacer '%%DBPWD%%' par le mot de passe du login de l'utilisateur
  #ci-dessus
- $MDPBDD="password";
+ $MDPBDD="%%DBPWD%%";
  
  
  #$CGIADR contient la valeur du scriptalias pour le 'Facturier' sur le serveur web 
  #remplacer 'scriptalias' par le scriptalias du 'Facturier'
  #si scriptalias = fact alors 
- $CGIADR="/scriptalias";
+ $CGIADR="/fact";
 
  
  
@@ -87,18 +87,18 @@
  # où est installé le 'Facturier'
  #remplacer 'chemin repertoire principale (facturier/)' par le chemin du repertoire
  #facturier : si le facturier est dans /var/www/html, alors :
- $BASEAD ="chemin_repertoire_principal(facturier/)";
+ $BASEAD ="%%FACT_REP%%/";
 
  
  
  #$HTMLDOC contient le chemin de la commande htmldoc
  #si la commande htmldoc que vous désirez utiliser est dans "/usr/bin/" faire
- $HTMLDOC="/repertoire_de_htmldoc/htmldoc";
+ $HTMLDOC="%%PREFIX%%/bin/htmldoc";
 
  #$HTMLADRESSE indique au serveur web où se trouve les pages html utilisées par le facturier
  # par apport au DocumentRoot. Si vous avez installé le facturier dans le DocumentRoot
  #vous n'aurez pas besoin de modifier la valeur de $HTMLADRESSE
- $HTMLADRESSE='/facturier/html';
+ $HTMLADRESSE='/../facturier/html';
  
 ###################################
 #finvariables serveur à configurer
