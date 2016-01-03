# Add patch for https://mariadb.atlassian.net/browse/MDEV-9322

--- storage/connect/json.cpp.orig	2015-12-16 16:05:45 UTC
+++ storage/connect/json.cpp
@@ -594,7 +594,7 @@ PSZ Serialize(PGLOBAL g, PJSON jsp, char
   if (fs) {
 		fputs(EL, fs);
     fclose(fs);
-		str = (err) ? NULL : "Ok";
+		str = (err) ? NULL : (char*)"Ok";
   } else if (!err) {
     str = ((JOUTSTR*)jp)->Strp;
     jp->WriteChr('\0');
