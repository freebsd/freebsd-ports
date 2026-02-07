interface/weapon_menu.cpp:394:12: error: cannot initialize return object of type 'Weapon *' with an rvalue of type 'bool'
    return false;
           ^~~~~

--- src/interface/weapon_menu.cpp.orig	2018-07-30 10:50:34 UTC
+++ src/interface/weapon_menu.cpp
@@ -391,7 +391,7 @@ void WeaponsMenu::Draw()
 Weapon * WeaponsMenu::UpdateCurrentOverflyItem(const Polygon * poly)
 {
   if (!show)
-    return false;
+    return NULL;
   const std::vector<PolygonItem *>& items = poly->GetItem();
   WeaponMenuItem * tmp;
   Interface::GetInstance()->SetCurrentOverflyWeapon(NULL);
