Clang fix; initializer is not needed anyway, array is copied in ctor body
--- src/armyproto.cpp.orig	2011-02-12 22:13:14.000000000 +0300
+++ src/armyproto.cpp	2014-05-16 19:24:16.982231310 +0400
@@ -36,7 +36,7 @@
 ArmyProto::ArmyProto(const ArmyProto& a)
     :ArmyProtoBase(a),
      d_defends_ruins(a.d_defends_ruins), 
-     d_awardable(a.d_awardable), d_image_name(a.d_image_name),
+     d_awardable(a.d_awardable),
      d_gender(Hero::NONE)
 {
   for (unsigned int c = Shield::WHITE; c <= Shield::NEUTRAL; c++)
