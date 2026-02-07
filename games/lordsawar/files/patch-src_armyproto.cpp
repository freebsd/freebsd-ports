--- src/armyproto.cpp.orig	2020-04-09 19:57:07 UTC
+++ src/armyproto.cpp
@@ -35,9 +35,13 @@ Glib::ustring ArmyProto::d_tag = "armyproto";
 
 ArmyProto::ArmyProto(const ArmyProto& a)
     :ArmyProtoBase(a), d_id(a.d_id), d_defends_ruins(a.d_defends_ruins), 
-     d_awardable(a.d_awardable), d_image_name(a.d_image_name),
+     d_awardable(a.d_awardable),
      d_gender(a.d_gender)
 {
+  for (size_t i = 0; i < sizeof(d_image_name)/sizeof(d_image_name[0]); i++) {
+	  d_image_name[i] = a.d_image_name[i];
+  }
+
   for (unsigned int c = Shield::WHITE; c <= Shield::NEUTRAL; c++)
     {
       d_image_name[c] = a.d_image_name[c];
