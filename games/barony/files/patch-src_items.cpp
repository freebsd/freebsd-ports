--- src/items.cpp.orig	2022-10-30 17:29:46 UTC
+++ src/items.cpp
@@ -4634,14 +4634,14 @@ real_t rangedAttackGetSpeedModifier(const Stat* const 
 	else if ( myStats->weapon->type == HEAVY_CROSSBOW )
 	{
 		bowModifier = 0.4;
-		return std::max(0.1, bowModifier + arrowModifier);
+		return std::max((real_t)0.1, bowModifier + arrowModifier);
 	}
 	else
 	{
 		bowModifier = 1.00;
 	}
 
-	return std::max(0.25, bowModifier + arrowModifier);
+	return std::max((real_t)0.25, bowModifier + arrowModifier);
 }
 
 bool rangedWeaponUseQuiverOnAttack(const Stat* const myStats)
@@ -4995,4 +4995,4 @@ void clientUnequipSlotAndUpdateServer(const EquipItemS
 
 	clientSendEquipUpdateToServer(slot, equipType, clientnum,
 		item->type, item->status, item->beatitude, item->count, item->appearance, item->identified);
-}
\ No newline at end of file
+}
