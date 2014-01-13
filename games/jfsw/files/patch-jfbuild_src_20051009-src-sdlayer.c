--- jfbuild_src_20051009/src/sdlayer.c.orig	2005-10-09 15:23:00.000000000 +0200
+++ jfbuild_src_20051009/src/sdlayer.c	2005-10-10 15:06:22.000000000 +0200
@@ -24,6 +24,10 @@
 // undefine to restrict windowed resolutions to conventional sizes
 #define ANY_WINDOWED_SIZE
 
+// fix for mousewheel
+#define MWHEELTICKS 10
+static unsigned long mwheelup, mwheeldown;
+
 int   _buildargc = 1;
 char **_buildargv = NULL;
 extern long app_main(long argc, char *argv[]);
@@ -486,8 +490,8 @@
 	initprintf("Initialising mouse\n");
 
 	// grab input
-	grabmouse(1);
 	moustat=1;
+	grabmouse(1);
 
 	return 0;
 }
@@ -1363,14 +1367,22 @@
 					case SDL_BUTTON_LEFT: j = 0; break;
 					case SDL_BUTTON_RIGHT: j = 1; break;
 					case SDL_BUTTON_MIDDLE: j = 2; break;
-					default: j = -1; break;
+					default: j = ev.button.button; break;
 				}
 				if (j<0) break;
 				
-				if (ev.button.state == SDL_PRESSED)
+				if (ev.button.state == SDL_PRESSED) {
+					if (ev.button.button == SDL_BUTTON_WHEELUP) {
+						mwheelup = totalclock;
+					}
+					if (ev.button.button == SDL_BUTTON_WHEELDOWN) {
+						mwheeldown = totalclock;
+					}
 					mouseb |= (1<<j);
-				else
-					mouseb &= ~(1<<j);
+				}
+				else {
+					if (j < 4) mouseb &= ~(1<<j);
+				}
 
 				if (mousepresscallback)
 					mousepresscallback(j+1, ev.button.state == SDL_PRESSED);
@@ -1435,6 +1447,17 @@
 
 	sampletimer();
 
+	if (moustat) {
+		if ((mwheelup) && (mwheelup <= (totalclock - MWHEELTICKS))) {
+			mouseb &= ~16;
+			mwheelup = 0;
+		}
+		if ((mwheeldown) && (mwheeldown <= (totalclock - MWHEELTICKS))) {
+			mouseb &= ~32;
+			mwheeldown = 0;
+		}
+	}
+
 #ifdef HAVE_GTK2
 	if (gtkenabled) update_startwin();
 #endif
