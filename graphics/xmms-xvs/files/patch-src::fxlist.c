--- src/fxlist.c.orig	Thu Jun 21 10:49:06 2001
+++ src/fxlist.c	Tue Oct 28 23:51:39 2003
@@ -60,28 +60,4 @@
 
   return NULL;
 }
-
-#else /* FXLIST_RECURSIVE */
-
-/* List all available modules. */
-/* Filters */
-FXMODULE( FXBlur )
-FXMODULE( FXBump )
-/* Transitions */
-FXMODULE( FXZoomer )
-FXMODULE( FXRotoZoomer )
-FXMODULE( FXUniBlitter )
-/* Renderers */
-FXMODULE( FXClear )
-FXMODULE( FXFlash )
-FXMODULE( FXParticle )
-FXMODULE( FXScope )
-FXMODULE( FXRing )
-FXMODULE( FXUniScope )
-/* Containers */
-FXMODULE( FXSimple )
-FXMODULE( FXOnce )
-/* Other */
-FXMODULE( FXComment )
-
-#endif /* FXLIST_RECURSIVE */
+#endif
