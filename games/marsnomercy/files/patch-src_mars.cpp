--- src/mars.cpp	Mon Mar  6 17:45:01 2006
+++ src/mars.cpp	Mon Mar 20 10:33:25 2006
@@ -96,6 +96,21 @@
 
 int main(int argc, char **argv)
 {
+int r_w = 0;
+int r_h = 0;
+
+	switch(argc)
+	{
+		case 1:r_w = 1024;
+	               r_h = 768;
+		       break;
+		case 3:r_w = atoi(argv[1]);
+                       r_h = atoi(argv[2]);
+		       break;
+		default: cout << "Use: mars-nomercy or mars-nomercy <width> <height>" <<endl;
+		       exit(0);
+	}
+		
 	// the system video is initialized
     SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
 	// init SDL_ttf
@@ -103,9 +118,9 @@
 
 	// when exit, execute SDL_Quit to restore everything
 	atexit(SDL_Quit);
-	
-	Dimension screen_dim = { RIS2_W, RIS2_H };	
-	
+ 
+	Dimension screen_dim = { r_w, r_h };
+
 	// init screen
 	screen = new Screen(screen_dim.w, screen_dim.h, SDL_SWSURFACE|SDL_FULLSCREEN);    
 	
@@ -116,8 +131,8 @@
 	Options opt;
 	
 	// default res is 1024 x 768
-	opt.ris.w = RIS2_W;
-	opt.ris.h = RIS2_H;
+	opt.ris.w = r_w;
+	opt.ris.h = r_h;
 	
 	// start menu
 	menu(opt);
