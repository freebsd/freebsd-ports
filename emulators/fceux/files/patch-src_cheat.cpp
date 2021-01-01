--- src/cheat.cpp.orig	2017-02-26 13:33:11 UTC
+++ src/cheat.cpp
@@ -216,7 +216,7 @@ void FCEU_LoadGameCheats(FILE *override)
 	}
 
 	FCEU_DispMessage("Cheats file loaded.",0); //Tells user a cheats file was loaded.
-	while(fgets(linebuf,2048,fp)>0)
+	while(fgets(linebuf,2048,fp))
 	{
 		char *tbuf=linebuf;
 		int doc=0;
