--- src/menu.c.orig	Tue Jul 16 23:49:04 2002
+++ src/menu.c	Tue Jul 16 23:49:31 2002
@@ -28,7 +28,7 @@
 
 int initmenu(void){
 
-  playmusic("data/music/lktheme.mod");
+  playmusic("%%DATADIR%%/data/music/lktheme.mod");
   
   return 1;
 }
@@ -114,13 +114,13 @@
 	          loadc = COURSES-1;
 	        else
 	          loadc--;
-		  playsound("data/sounds/menu.wav",0);
+		  playsound("%%DATADIR%%/data/sounds/menu.wav",0);
 	        break;
 		
 	      case 2:
 		SDL_WM_ToggleFullScreen(surface);
 	        fullscreen = 0;
-		playsound("data/sounds/menu.wav",0);
+		playsound("%%DATADIR%%/data/sounds/menu.wav",0);
 	        break;
 	      default:
 	        break;
@@ -133,12 +133,12 @@
 	          loadc = 0;
 	        else
 	          loadc++;
-		playsound("data/sounds/menu.wav",0);
+		playsound("%%DATADIR%%/data/sounds/menu.wav",0);
 	        break;
 	      case 2:
 	        fullscreen = 0;
 	        SDL_WM_ToggleFullScreen(surface);
-		playsound("data/sounds/menu.wav",0);
+		playsound("%%DATADIR%%/data/sounds/menu.wav",0);
 	        break;
 	      default:
 	        break;
@@ -149,14 +149,14 @@
               menuitem = MENU_ITEMS-1;
 	    else
 	      menuitem--;
-	    playsound("data/sounds/menu.wav",0);
+	    playsound("%%DATADIR%%/data/sounds/menu.wav",0);
 	    break;
 	  case SDLK_DOWN:
 	    if(menuitem == MENU_ITEMS-1)
               menuitem = 0;
 	    else
 	      menuitem++;
-    	    playsound("data/sounds/menu.wav",0);
+    	    playsound("%%DATADIR%%/data/sounds/menu.wav",0);
 	    break;
 	  case SDLK_q:
 	    killgame(1);
