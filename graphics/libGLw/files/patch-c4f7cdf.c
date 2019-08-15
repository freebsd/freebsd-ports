diff --git a/GLwDrawA.c b/GLwDrawA.c
index b9ef47b1ce505553120fa7556693b97e5d91b3c5..8ce12fba0f6ef4b092837ca0c2e6aa44f5de2dfa 100644
--- GLwDrawA.c
+++ GLwDrawA.c
@@ -474,7 +474,7 @@ static void Initialize(GLwDrawingAreaWidget req,GLwDrawingAreaWidget neww,ArgLis
 
   /* fix size */
   if(req->core.width==0) neww->core.width=100;
-  if(req->core.height==0) neww->core.width=100;
+  if(req->core.height==0) neww->core.height=100;
 
   /* create the attribute list if needed */
   neww->glwDrawingArea.myList=FALSE;
