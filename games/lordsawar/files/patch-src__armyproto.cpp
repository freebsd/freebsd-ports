--- src/armyproto.cpp.orig	2011-02-12 19:13:14 UTC
+++ src/armyproto.cpp
@@ -36,7 +36,7 @@ std::string ArmyProto::d_tag = "armyprot
 ArmyProto::ArmyProto(const ArmyProto& a)
     :ArmyProtoBase(a),
      d_defends_ruins(a.d_defends_ruins), 
-     d_awardable(a.d_awardable), d_image_name(a.d_image_name),
+     d_awardable(a.d_awardable),
      d_gender(Hero::NONE)
 {
   for (unsigned int c = Shield::WHITE; c <= Shield::NEUTRAL; c++)
