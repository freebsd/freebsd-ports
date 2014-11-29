--- src/game.cpp.orig	2005-07-19 03:25:16.000000000 +0400
+++ src/game.cpp	2014-11-24 16:13:27.000000000 +0300
@@ -54,6 +54,8 @@
   attractionStautsP2(0.00, 0, 0.18, 0.08, TEX_ATTRACT),
   attractionStautsP1(0.82, 0, 1.00, 0.08, TEX_ATTRACT)
 {
+	dInitODE();
+
 	this->context.setGravity(0,0,ODE_WORLD_GRAVITY);// @fixme remove this
 	/* ODE setup */
 // 	dWorldSetERP (context.getWid(), 0.9);
@@ -990,5 +992,6 @@
 	}else {
 		//@fixme throw something
 	}
+	return false;
 }
 };
