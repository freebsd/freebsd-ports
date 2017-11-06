Fix SAR selection of ship sizes for missions
https://github.com/pioneerspacesim/pioneer/commit/008e30a857036a8cc40c42bf89ef68e65b47a41e

--- data/modules/SearchRescue/SearchRescue.lua.orig	2017-10-01 00:01:47 UTC
+++ data/modules/SearchRescue/SearchRescue.lua
@@ -613,7 +613,20 @@ local createTargetShipParameters = funct
 	---- loading drive, weapons etc.
 	if flavour.id == 1 or flavour.id == 6 then
 		for i,shipdef in pairs(shipdefs) do
-			if shipdef.capacity / 10 < 1 then shipdefs[i] = nil end
+
+			-- get mass of hyperdrive if this ship has a default drive
+			-- if no default drive assume lowest mass drive
+			-- higher mass drives will only be fitted later at ship creation if capacity is huge
+			local drive = Equipment.hyperspace['hyperdrive_'..tostring(shipdef.hyperdriveClass)]
+			if not drive then
+				local drives = {}
+				for i = 9, 1, -1 do
+					table.insert(drives, Equipment.hyperspace['hyperdrive_'..tostring(i)])
+				end
+				table.sort(drives, function (a,b) return a.capabilities.mass < b.capabilities.mass end)
+				drive = drives[1]
+			end
+			if (shipdef.capacity-drive.capabilities.mass) / 10 < 1 then shipdefs[i] = nil end
 		end
 	elseif flavour.pickup_pass > 0 then
 		for i,shipdef in pairs(shipdefs) do
@@ -661,7 +674,16 @@ local createTargetShipParameters = funct
 	if flavour.id == 1 or flavour.id == 6 then
 		local any_pass = rand:Integer(0,1)
 		if any_pass > 0 then
-			pickup_pass = rand:Integer(1, math.min((shipdef.capacity / 10)+1, max_pass))
+			local drive = Equipment.hyperspace['hyperdrive_'..tostring(shipdef.hyperdriveClass)]
+			if not drive then
+				local drives = {}
+				for i = 9, 1, -1 do
+					table.insert(drives, Equipment.hyperspace['hyperdrive_'..tostring(i)])
+				end
+				table.sort(drives, function (a,b) return a.capabilities.mass < b.capabilities.mass end)
+				drive = drives[1]
+			end
+			pickup_pass = rand:Integer(1, math.min(((shipdef.capacity-drive.capabilities.mass) / 10)+1, max_pass))
 		else
 			pickup_pass = 0
 		end
@@ -709,22 +731,25 @@ local createTargetShip = function (missi
 	ship:SetPattern(pattern)
 
 	-- load a hyperdrive
-	local default_drive = Equipment.hyperspace['hyperdrive_'..tostring(shipdef.hyperdriveClass)]
-	if default_drive then
-		ship:AddEquip(default_drive)
-	else
-		local drive
+	-- 1st try: default drive for this ship class
+	-- 2nd try: largest drive possible that doesn't take more than a 10th of available room
+	-- fallback: smallest drive
+	local drives = {}
+	local drive = Equipment.hyperspace['hyperdrive_'..tostring(shipdef.hyperdriveClass)]
+	if not drive then
 		for i = 9, 1, -1 do
-			drive = Equipment.hyperspace['hyperdrive_'..tostring(i)]
-			if shipdef.capacity / 10 > drive.capabilities.mass then
-				ship:AddEquip(drive)
-				break
-			end
+			table.insert(drives, Equipment.hyperspace['hyperdrive_'..tostring(i)])
 		end
-		if not drive then
-			ship:AddEquip(Equipment.hyperspace['hyperdrive_1'])
+		table.sort(drives, function (a,b) return a.capabilities.mass < b.capabilities.mass end)
+		for i = #drives, 1, -1 do
+			local test_drive = drives[i]
+			if shipdef.capacity / 10 > test_drive.capabilities.mass then
+				drive = test_drive
+			end
 		end
 	end
+	if not drive then drive = drives[1] end
+	ship:AddEquip(drive)
 
 	-- add thruster fuel
 	if mission.flavour.id == 2 or mission.flavour.id == 4 or mission.flavour.id == 5 then
