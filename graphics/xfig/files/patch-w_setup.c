--- w_setup.c.orig	Tue Jul 26 09:40:02 2005
+++ w_setup.c
@@ -23,7 +23,7 @@
 #include "w_setup.h"
 #include "w_util.h"
 
-#define	NUM_DRAW_SW 17 /* kludge - shouldn't have to edit this by hand */
+#define	NUM_DRAW_SW 15 /* kludge - shouldn't have to edit this by hand */
 
 int		TOOL_WD, TOOL_HT;
 int		CMDFORM_WD, CMDFORM_HT = CMD_BUT_HT;
@@ -94,7 +94,7 @@
 
     /* space for both modepanel titles (Drawing modes and Editing modes) */
     MODEPANEL_SPACE = 1 + CANVAS_HT + RULER_WD - 
-	(MODE_SW_HT + INTERNAL_BW) * (ceil((double)NUM_DRAW_SW/SW_PER_ROW) +
+	(MODE_SW_HT + INTERNAL_BW) * (ceil((double)(NUM_DRAW_SW+1)/SW_PER_ROW) +
 			ceil((double)(NUM_MODE_SW-NUM_DRAW_SW)/SW_PER_ROW));
     if (MODEPANEL_SPACE < 2)
 	MODEPANEL_SPACE = 2;
