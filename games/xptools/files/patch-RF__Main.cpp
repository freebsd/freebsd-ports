--- src/RenderFarmUI/RF_Main.cpp.orig	2018-07-04 20:42:21 UTC
+++ src/RenderFarmUI/RF_Main.cpp
@@ -303,7 +303,7 @@ static	GISTool_RegCmd_t		sUtilCmds[] = {
 
 
 
-static int fifo = NULL;
+static int fifo = 0;
 
 static float CheckFifo(void)
 {
