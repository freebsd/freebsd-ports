--- src/graphic/Screen.cpp	Mon Mar  6 16:56:16 2006
+++ src/graphic/Screen.cpp	Mon Mar 20 10:38:14 2006
@@ -17,7 +17,16 @@
 
 	// Setting screen mode
 	a_surface = SDL_SetVideoMode(a_rectangle->w, a_rectangle->h, 0, a_flags); 
-	
+
+	if(!a_surface)
+	{
+		cout << "Video mode supported" << endl;
+		cout << "* 1024x768" << endl;
+		cout << "* 800x600" << endl;
+		cout << "Try: mars-nomercy <width> <height>" << endl;		
+		exit(0);
+	}
+
 	a_backup = NULL;
 }
 	
@@ -38,6 +47,15 @@
 	if(w != a_rectangle->w || h != a_rectangle->h)
 	{
 		a_surface = SDL_SetVideoMode(w, h, 0, a_flags);
+		
+		if(!a_surface)
+		{
+			cout << "Video mode supported" << endl;
+			cout << "* 1024x768" << endl;
+			cout << "* 800x600" << endl;
+			cout << "Try: mars-nomercy <width> <height>" << endl;
+			exit(0);
+		}
 		
 		// Setting screen dimensions
 		a_rectangle->w = w;
