--- ../../work.orig/seahaven-1.41/main.C	Mon Aug  5 22:51:21 2002
+++ main.C	Mon Aug  5 23:36:23 2002
@@ -25,11 +25,21 @@
     exit(1);
 }
 
+static void Quit() {
+    XDestroyWindow(dpy, toplevel);
+    XFlush(dpy);
+    exit(0);
+}
 
 main(int argc, char **argv) {
     char *displayname = NULL;
+    char *name = NULL;
+    XClassHint *classhint;
+    XWMHints *wmhints;
+    XSizeHints *sizehints;
     bool sync = false;
     int i;
+    Atom wm_protocols, wm_delete_window;
 
     progname = argv[0];
 
@@ -44,6 +54,10 @@
 	} else if (strcmp(argv[i], "-speedup") == 0) {
 	    speedup = atoi(argv[++i]);
 	    if (speedup <= 0) Usage();
+	} else if (strcmp(argv[i], "-name") == 0) {
+	    if (argv[++i] == NULL)
+		Usage();
+	    name = argv[i];
 	} else {
 	    Usage();
 	}
@@ -69,7 +83,7 @@
 
     XSetWindowAttributes attributes;
     long valuemask = CWEventMask | CWBackPixel;
-    attributes.event_mask = KeyPressMask;
+    attributes.event_mask = KeyPressMask; /* ClientMessage is always there */
     attributes.background_pixel = backpixel;
 
     toplevel = XCreateWindow(dpy, DefaultRootWindow(dpy), 0, 0,
@@ -78,6 +92,44 @@
 			     valuemask, &attributes);
     XSetIconName(dpy, toplevel, "Seahaven");
     XStoreName(dpy, toplevel, "Seahaven Towers");
+    classhint = XAllocClassHint();
+    if (!classhint)
+	Punt("can't allocate memory for class hint");
+    if (name)
+	classhint->res_name = name;
+    else {
+	classhint->res_name = strrchr(progname, '/');
+	if (!classhint->res_name)
+	    classhint->res_name = progname;
+    }
+    classhint->res_class = "Seahaven";
+    XSetClassHint(dpy, toplevel, classhint);
+    XFree(classhint);
+
+    /* We don't do focus management -- must tell WM to do it for us, or
+       otherwise we might not get the focus when initially mapped. */
+    wmhints = XAllocWMHints();
+    if (!wmhints)
+	Punt("can't allocate memory for window manager hints");
+    wmhints->flags = InputHint | StateHint;
+    wmhints->input = True;
+    wmhints->initial_state = NormalState;
+    XSetWMHints(dpy, toplevel, wmhints);
+    XFree(wmhints);
+
+    /* Let the WM know that we can't be resized. */
+    sizehints = XAllocSizeHints();
+    if (!sizehints)
+	Punt("can't allocate memory for window size hints");
+    sizehints->flags = PMinSize | PMaxSize;
+    sizehints->min_width = sizehints->max_width = GAMEWIDTH;
+    sizehints->min_height = sizehints->max_height = GAMEHEIGHT;
+    XSetWMNormalHints(dpy, toplevel, sizehints);
+    XFree(sizehints);
+
+    wm_protocols = XInternAtom(dpy, "WM_PROTOCOLS", False);
+    wm_delete_window = XInternAtom(dpy, "WM_DELETE_WINDOW", False);
+    XSetWMProtocols(dpy, toplevel, &wm_delete_window, 1);
 
     font = XLoadQueryFont
 	(dpy, "-*-helvetica-medium-r-normal--*-120-*-*-p-*-iso8859-1");
@@ -139,12 +191,15 @@
 		      case '\033': //esc
 		      case 'Q':
 		      case 'q':
-			XUnmapWindow(dpy, toplevel);
-			XFlush(dpy);
-			exit(0);
+			Quit();
 			break;
 		    }
 		}
+	    } else if (event.type == ClientMessage
+			&& event.xclient.message_type == wm_protocols
+			&& event.xclient.format == 32
+			&& *(Atom *)&event.xclient.data == wm_delete_window) {
+		Quit();
 	    } else if (event.type == ButtonPress) {
 		Window w = event.xbutton.window;
 		if (w == undobutton) DoUndo();
@@ -152,11 +207,7 @@
 		else if (w == restartbutton) DoRestart();
 		else if (w == autobutton) DoAutoPlay();
 		else if (w == newgamebutton) NewGame();
-		else if (w == quitbutton) {
-		    XUnmapWindow(dpy, toplevel);
-		    XFlush(dpy);
-		    exit(0);
-		}
+		else if (w == quitbutton) Quit();
 	    }
 	}
     }
