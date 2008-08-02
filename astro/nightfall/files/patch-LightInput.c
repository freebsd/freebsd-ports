--- LightInput.c.orig	2008-07-23 03:59:38.000000000 +0900
+++ LightInput.c	2008-07-23 23:44:48.000000000 +0900
@@ -672,7 +672,9 @@
 	Flags.interactive = ON;
 	Flags.fractional  = ON;
 	Flags.visualize   = ON;
+#ifdef _WITH_OPENGL
 	Flags.use_opengl  = ON;
+#endif
 	Flags.PlotBand    = Vmag;
       } else {
 	WARNERR(_("Bad Option (use 'nightfall <RETURN> to get a list of options): "), 
