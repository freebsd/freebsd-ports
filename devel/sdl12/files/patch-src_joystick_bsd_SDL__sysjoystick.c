--- src/joystick/bsd/SDL_sysjoystick.c.orig	Fri Nov 12 22:24:46 2004
+++ src/joystick/bsd/SDL_sysjoystick.c	Tue Nov  8 20:19:38 2005
@@ -122,6 +122,12 @@
 	struct	report_desc *repdesc;
 	struct	report inreport;
 	int	axis_map[JOYAXE_count];	/* map present JOYAXE_* to 0,1,..*/
+	int	x;
+	int	y;
+	int	xmin;
+	int	ymin;
+	int	xmax;
+	int	ymax;
 };
 
 static char *joynames[MAX_JOYS];
@@ -255,6 +261,12 @@
 	joy->hwdata = hw;
 	hw->fd = fd;
 	hw->path = strdup(path);
+	hw->x = 0;
+	hw->y = 0;
+	hw->xmin = 0xffff;
+	hw->ymin = 0xffff;
+	hw->xmax = 0;
+	hw->ymax = 0;
 	if (! strncmp(path, "/dev/joy", 8)) {
 		hw->type = BSDJOY_JOY;
 		joy->naxes = 2;
@@ -372,43 +384,42 @@
 
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 	struct joystick gameport;
-	static int x, y, xmin = 0xffff, ymin = 0xffff, xmax = 0, ymax = 0;
  
 	if (joy->hwdata->type == BSDJOY_JOY) {
 		if (read(joy->hwdata->fd, &gameport, sizeof gameport) != sizeof gameport)
 			return;
-		if (abs(x - gameport.x) > 8) {
-			x = gameport.x;
-			if (x < xmin) {
-				xmin = x;
+		if (abs(joy->hwdata->x - gameport.x) > 8) {
+			joy->hwdata->x = gameport.x;
+			if (joy->hwdata->x < joy->hwdata->xmin) {
+				joy->hwdata->xmin = joy->hwdata->x;
 			}
-			if (x > xmax) {
-				xmax = x;
+			if (joy->hwdata->x > joy->hwdata->xmax) {
+				joy->hwdata->xmax = joy->hwdata->x;
 			}
-			if (xmin == xmax) {
-				xmin--;
-				xmax++;
+			if (joy->hwdata->xmin == joy->hwdata->xmax) {
+				joy->hwdata->xmin--;
+				joy->hwdata->xmax++;
 			}
-			v = (Sint32)x;
-			v -= (xmax + xmin + 1)/2;
-			v *= 32768/((xmax - xmin + 1)/2);
+			v = (Sint32)joy->hwdata->x;
+			v -= (joy->hwdata->xmax + joy->hwdata->xmin + 1)/2;
+			v *= 32768/((joy->hwdata->xmax - joy->hwdata->xmin + 1)/2);
 			SDL_PrivateJoystickAxis(joy, 0, v);
 		}
-		if (abs(y - gameport.y) > 8) {
-			y = gameport.y;
-			if (y < ymin) {
-				ymin = y;
+		if (abs(joy->hwdata->y - gameport.y) > 8) {
+			joy->hwdata->y = gameport.y;
+			if (joy->hwdata->y < joy->hwdata->ymin) {
+				joy->hwdata->ymin = joy->hwdata->y;
 			}
-			if (y > ymax) {
-				ymax = y;
+			if (joy->hwdata->y > joy->hwdata->ymax) {
+				joy->hwdata->ymax = joy->hwdata->y;
 			}
-			if (ymin == ymax) {
-				ymin--;
-				ymax++;
+			if (joy->hwdata->ymin == joy->hwdata->ymax) {
+				joy->hwdata->ymin--;
+				joy->hwdata->ymax++;
 			}
-			v = (Sint32)y;
-			v -= (ymax + ymin + 1)/2;
-			v *= 32768/((ymax - ymin + 1)/2);
+			v = (Sint32)joy->hwdata->y;
+			v -= (joy->hwdata->ymax + joy->hwdata->ymin + 1)/2;
+			v *= 32768/((joy->hwdata->ymax - joy->hwdata->ymin + 1)/2);
 			SDL_PrivateJoystickAxis(joy, 1, v);
 		}
 		if (gameport.b1 != joy->buttons[0]) {
