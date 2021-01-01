--- src/Game.h.orig
+++ src/Game.h
@@ -82,6 +82,16 @@
 		DRAW_OVERLAY = 0x100,
 	};
 
+	struct BuildProject
+	{
+		int posX;
+		int posY;
+		int teamNumber;
+		int typeNum;
+		int unitWorking;
+		int unitWorkingFuture;
+	};
+
 	/// This method will prepare the game with this mapHeader
 	void setMapHeader(const MapHeader& mapHeader);
 	
@@ -149,16 +159,6 @@
 		BOTTOM_TO_TOP
 	};
 	
-	struct BuildProject
-	{
-		int posX;
-		int posY;
-		int teamNumber;
-		int typeNum;
-		int unitWorking;
-		int unitWorkingFuture;
-	};
-	
 	///Initiates Game
 	void init(GameGUI *gui, MapEdit* edit);
 
