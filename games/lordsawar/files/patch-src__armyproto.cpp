--- src/armyproto.cpp.orig	2011-02-12 19:13:14 UTC
+++ src/armyproto.cpp
@@ -34,7 +34,7 @@
 
 ArmyProto::ArmyProto(const ArmyProto& a)
     :ArmyProtoBase(a), d_id(a.d_id), d_defends_ruins(a.d_defends_ruins), 
-     d_awardable(a.d_awardable), d_image_name(a.d_image_name),
+     d_awardable(a.d_awardable),
      d_gender(a.d_gender)
 {
   for (unsigned int c = Shield::WHITE; c <= Shield::NEUTRAL; c++)
