--- src/unit/upgrade.cpp.orig	2015-11-10 20:52:37 UTC
+++ src/unit/upgrade.cpp
@@ -298,7 +298,7 @@ static int CclDefineModifier(lua_State *
 	um->UpgradeId = UpgradeIdByIdent(upgrade_name);
 	
 	if (um->UpgradeId == -1) {
-		LuaError(l, "Error when defining upgrade modifier: upgrade \"%s\" doesn't exist." _C_ upgrade_name);
+		LuaError(l, "Error when defining upgrade modifier: upgrade \"%s\" doesn't exist." _C_ upgrade_name.c_str());
 	}
 	//Wyrmgus end
 
@@ -546,7 +546,7 @@ static int CclAcquireTrait(lua_State *l)
 	if (!strncmp(ident, "upgrade-", 8)) {
 		TraitAcquire(*unit, CUpgrade::Get(ident));
 		unit->Trait = ident;
-	} else if (ident == "") {
+	} else if (strlen(ident) == 0) {
 		if (!unit->Trait.empty()) { //remove previous trait, if any
 			if (!GameSettings.NoRandomness || unit->Type->BoolFlag[HERO_INDEX].value) { // if in no randomness setting, only change trait modifiers if the unit is a hero
 				IndividualUpgradeLost(*unit, CUpgrade::Get(unit->Trait));
