--- main/ui-gtk.c.orig	Sun Oct 14 18:02:05 2001
+++ main/ui-gtk.c	Mon Apr  7 01:40:55 2003
@@ -18,7 +18,8 @@
 /* need Xlib.h for XAutoRepeatOff - how poo is X */
 #include "X11/Xlib.h"
 
-#include "SDL.h"
+#include <SDL.h>
+#include <SDL_joystick.h>
 
 #include "generator.h"
 #include "snprintf.h"
@@ -98,6 +99,8 @@
 static int ui_query_response = -1; /* query response */
 t_gtkkeys ui_cont[2];           /* keyboard key codes */
 static int ui_musicfile = -1;   /* fd of output file for GYM/GNM logging */
+static int ui_joysticks = 0;	/* number of joysticks */
+static SDL_Joystick *js_handle[2] = { NULL, NULL };
 
 static enum {
   SCREEN_100, SCREEN_200, SCREEN_FULL
@@ -120,6 +123,7 @@
 static int ui_gtk_query(const char *msg, int style);
 static void ui_gtk_opts_to_menu(void);
 static void ui_simpleplot(void);
+static void ui_sdl_events (void);
 
 /*** Program entry point ***/
 
@@ -129,6 +133,8 @@
   GtkWidget *button, *draw, *obj;
   struct passwd *passwd;
   struct stat statbuf;
+  int i;
+  const char *name;
 
   gtk_set_locale();
   gtk_init(&argc, &argv);
@@ -209,10 +215,21 @@
              GDK_WINDOW_XWINDOW(draw->window));
     putenv(SDL_windowhack);
   }
-  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
+  if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK) < 0) {
     fprintf(stderr, "Couldn't initialise SDL: %s\n", SDL_GetError());
     return -1;
   }
+  ui_joysticks = SDL_NumJoysticks();
+  /* Print information about the joysticks */
+  fprintf(stderr, "%d joysticks detected\n", ui_joysticks);
+  for (i = 0; i < ui_joysticks; ++i) {
+    name = SDL_JoystickName(i);
+    fprintf(stderr, "Joystick %d: %s\n", i, name ? name : "Unknown Joystick");
+  }
+  js_handle[0] = SDL_JoystickOpen(0);
+  js_handle[1] = SDL_JoystickOpen(1);
+  SDL_JoystickEventState(SDL_ENABLE);
+
   ui_gtk_sizechange();
   ui_gtk_newoptions();
   ui_gtk_opts_to_menu();
@@ -264,9 +281,11 @@
     if (ui_running) {
       while (gtk_events_pending())
         gtk_main_iteration_do(0);
+      ui_sdl_events();
       ui_newframe();
       event_doframe();
     } else {
+      ui_sdl_events();
       gtk_main();
     }
   }
@@ -1529,6 +1548,62 @@
     }
   }
 }
+
+static void
+ui_sdl_events (void)
+{
+	SDL_Event event;
+
+#define	LEFT(event)	((event.jaxis.value < -16384) ? 1 : 0)
+#define	RIGHT(event)	((event.jaxis.value > 16384) ? 1 : 0)
+#define	UP(event)	((event.jaxis.value < -16384) ? 1 : 0)
+#define	DOWN(event)	((event.jaxis.value > 16384) ? 1 : 0)
+#define	PRESS(event)	((event.type == SDL_JOYBUTTONDOWN) ? 1 : 0)
+
+	while (SDL_PollEvent(&event)) {
+		switch (event.type) {
+		case SDL_JOYAXISMOTION:
+			if (event.jaxis.which > 1)
+				break;
+			switch (event.jaxis.axis) {
+			case 0:	/* left & right */
+				mem68k_cont[event.jaxis.which].left = LEFT(event);
+				mem68k_cont[event.jaxis.which].right = RIGHT(event);
+				break;
+			case 1: /* up & down */
+				mem68k_cont[event.jaxis.which].up = UP(event);
+				mem68k_cont[event.jaxis.which].down = DOWN(event);
+				break;
+			default:
+				break;
+			}
+			break;
+		case SDL_JOYBUTTONDOWN:
+		case SDL_JOYBUTTONUP:
+			if (event.jbutton.which > 1)
+				break;
+			switch (event.jbutton.button) {
+			case 0:
+				mem68k_cont[event.jbutton.which].a = PRESS(event);
+				break;
+			case 1:
+				mem68k_cont[event.jbutton.which].b = PRESS(event);
+				break;
+			case 2:
+				mem68k_cont[event.jbutton.which].c = PRESS(event);
+				break;
+			case 3:
+				mem68k_cont[event.jbutton.which].start = PRESS(event);
+				break;
+			default:
+				break;
+			}
+			break;
+		default:
+			break;
+		}
+	}
+}	
 
 void ui_gtk_mainenter(void)
 {
