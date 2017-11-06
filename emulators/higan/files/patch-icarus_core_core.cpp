--- icarus/core/core.cpp.orig	2017-01-23 13:51:10 UTC
+++ icarus/core/core.cpp
@@ -1,18 +1,18 @@
 Icarus::Icarus() {
-  database.famicom = BML::unserialize(string::read(locate("Database/Famicom.bml")));
-  database.superFamicom = BML::unserialize(string::read(locate("Database/Super Famicom.bml")));
-  database.masterSystem = BML::unserialize(string::read(locate("Database/Master System.bml")));
-  database.megaDrive = BML::unserialize(string::read(locate("Database/Mega Drive.bml")));
-  database.pcEngine = BML::unserialize(string::read(locate("Database/PC Engine.bml")));
-  database.superGrafx = BML::unserialize(string::read(locate("Database/SuperGrafx.bml")));
-  database.gameBoy = BML::unserialize(string::read(locate("Database/Game Boy.bml")));
-  database.gameBoyColor = BML::unserialize(string::read(locate("Database/Game Boy Color.bml")));
-  database.gameBoyAdvance = BML::unserialize(string::read(locate("Database/Game Boy Advance.bml")));
-  database.gameGear = BML::unserialize(string::read(locate("Database/Game Gear.bml")));
-  database.wonderSwan = BML::unserialize(string::read(locate("Database/WonderSwan.bml")));
-  database.wonderSwanColor = BML::unserialize(string::read(locate("Database/WonderSwan Color.bml")));
-  database.bsMemory = BML::unserialize(string::read(locate("Database/BS Memory.bml")));
-  database.sufamiTurbo = BML::unserialize(string::read(locate("Database/Sufami Turbo.bml")));
+  database.famicom = BML::unserialize(string::read(locateShared("Database/Famicom.bml")));
+  database.superFamicom = BML::unserialize(string::read(locateShared("Database/Super Famicom.bml")));
+  database.masterSystem = BML::unserialize(string::read(locateShared("Database/Master System.bml")));
+  database.megaDrive = BML::unserialize(string::read(locateShared("Database/Mega Drive.bml")));
+  database.pcEngine = BML::unserialize(string::read(locateShared("Database/PC Engine.bml")));
+  database.superGrafx = BML::unserialize(string::read(locateShared("Database/SuperGrafx.bml")));
+  database.gameBoy = BML::unserialize(string::read(locateShared("Database/Game Boy.bml")));
+  database.gameBoyColor = BML::unserialize(string::read(locateShared("Database/Game Boy Color.bml")));
+  database.gameBoyAdvance = BML::unserialize(string::read(locateShared("Database/Game Boy Advance.bml")));
+  database.gameGear = BML::unserialize(string::read(locateShared("Database/Game Gear.bml")));
+  database.wonderSwan = BML::unserialize(string::read(locateShared("Database/WonderSwan.bml")));
+  database.wonderSwanColor = BML::unserialize(string::read(locateShared("Database/WonderSwan Color.bml")));
+  database.bsMemory = BML::unserialize(string::read(locateShared("Database/BS Memory.bml")));
+  database.sufamiTurbo = BML::unserialize(string::read(locateShared("Database/Sufami Turbo.bml")));
 }
 
 auto Icarus::error() const -> string {
