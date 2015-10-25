--- sope-appserver/NGObjWeb/SoObjects/SoComponent.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/SoObjects/SoComponent.m
@@ -59,13 +59,13 @@
 }
 
 - (void)setResourceManager:(WOResourceManager *)_rm {
-  ASSIGN(self->soResourceManager, _rm);
+  ASSIGN(self->soResourceManager, (SoProductResourceManager*)_rm);
 }
 - (WOResourceManager *)resourceManager {
   if (self->soResourceManager != nil)
     return self->soResourceManager;
   
-  self->soResourceManager = [[[self componentProduct] resourceManager] retain];
+  self->soResourceManager = (SoProductResourceManager*)[[[self componentProduct] resourceManager] retain];
   if (self->soResourceManager)
     return self->soResourceManager;
   
