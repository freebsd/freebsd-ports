--- src/MOGL/MOGL_Signal.h.orig	Sat Sep 18 07:21:08 2004
+++ src/MOGL/MOGL_Signal.h	Sat Sep 18 07:27:15 2004
@@ -169,13 +169,13 @@
                  */
                 MOGL_Connexion(TypeClasse * p_Objet, TypeMethode p_Methode)
                 {
-                  _Objet=p_Objet;
+                  this->_Objet=p_Objet;
                   _Methode=p_Methode;
                 }
                 
                 void Emettre(TypeParam1 p_Param1)
                 {
-                  (static_cast<TypeClasse*>(_Objet)->*_Methode)(p_Param1);
+                  (static_cast<TypeClasse*>(this->_Objet)->*_Methode)(p_Param1);
                 }
 
                 MOGL_ConnexionBaseBase *  Dupliquer(MOGL_Action * p_NouvelObjet)
@@ -264,13 +264,13 @@
                  */
                 MOGL_Connexion(TypeClasse * p_Objet, TypeMethode p_Methode)
                 {
-                  _Objet=p_Objet;
+                  this->_Objet=p_Objet;
                   _Methode=p_Methode;
                 }
                 
                 void Emettre(TypeParam1 p_Param1, TypeParam2 p_Param2)
                 {
-                  (static_cast<TypeClasse*>(_Objet)->*_Methode)(p_Param1, p_Param2);
+                  (static_cast<TypeClasse*>(this->_Objet)->*_Methode)(p_Param1, p_Param2);
                 }
 
                 MOGL_ConnexionBaseBase *  Dupliquer(MOGL_Action * p_NouvelObjet)
@@ -359,13 +359,13 @@
                  */
                 MOGL_Connexion(TypeClasse * p_Objet, TypeMethode p_Methode)
                 {
-                  _Objet=p_Objet;
+                  this->_Objet=p_Objet;
                   _Methode=p_Methode;
                 }
                 
                 void Emettre(TypeParam1 p_Param1, TypeParam2 p_Param2, TypeParam3 p_Param3)
                 {
-                  (static_cast<TypeClasse*>(_Objet)->*_Methode)(p_Param1, p_Param2, p_Param3);
+                  (static_cast<TypeClasse*>(this->_Objet)->*_Methode)(p_Param1, p_Param2, p_Param3);
                 }
 
                 MOGL_ConnexionBaseBase *  Dupliquer(MOGL_Action * p_NouvelObjet)
@@ -454,13 +454,13 @@
                  */
                 MOGL_Connexion(TypeClasse * p_Objet, TypeMethode p_Methode)
                 {
-                  _Objet=p_Objet;
+                  this->_Objet=p_Objet;
                   _Methode=p_Methode;
                 }
                 
                 void Emettre(TypeParam1 p_Param1, TypeParam2 p_Param2, TypeParam3 p_Param3, TypeParam4 p_Param4)
                 {
-                  (static_cast<TypeClasse*>(_Objet)->*_Methode)(p_Param1, p_Param2, p_Param3, p_Param4);
+                  (static_cast<TypeClasse*>(this->_Objet)->*_Methode)(p_Param1, p_Param2, p_Param3, p_Param4);
                 }
 
                 MOGL_ConnexionBaseBase *  Dupliquer(MOGL_Action * p_NouvelObjet)
@@ -549,13 +549,13 @@
                  */
                 MOGL_Connexion(TypeClasse * p_Objet, TypeMethode p_Methode)
                 {
-                  _Objet=p_Objet;
+                  this->_Objet=p_Objet;
                   _Methode=p_Methode;
                 }
                 
                 void Emettre(TypeParam1 p_Param1, TypeParam2 p_Param2, TypeParam3 p_Param3, TypeParam4 p_Param4, TypeParam5 p_Param5)
                 {
-                  (static_cast<TypeClasse*>(_Objet)->*_Methode)(p_Param1, p_Param2, p_Param3, p_Param4, p_Param5);
+                  (static_cast<TypeClasse*>(this->_Objet)->*_Methode)(p_Param1, p_Param2, p_Param3, p_Param4, p_Param5);
                 }
 
                 MOGL_ConnexionBaseBase *  Dupliquer(MOGL_Action * p_NouvelObjet)
