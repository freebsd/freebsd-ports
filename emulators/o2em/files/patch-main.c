--- ../o2em117src.old/src/main.c	Sat Jun 25 12:17:20 2005
+++ ./src/main.c	Sat Jun 25 12:11:50 2005
@@ -84,7 +84,7 @@
 	
 	if (argc < 2) {
 		printf("Use: o2em <file> [options]\n");
-		printf("<file> = file to load with extension\n");
+		printf("<file> = file to load\n");
 		#ifndef ALLEGRO_DOS
 		printf("-wsize=n         Window size (1-4)\n");
 		printf("-fullscreen      Full screen mode\n");
@@ -148,7 +148,6 @@
     strcpy(xrom,"");
 	read_default_config();
  
-    strcpy(file,"roms/");
 	for(i=1; i<argc; i++) {
 		if (argv[i][0] != '-') 	{
 			strncat(file,argv[i],MAXC-1);
@@ -186,20 +185,11 @@
 	init_audio();
 	printf("Using Allegro %s\n",allegro_id);
     
-    strcpy (xrom, "roms/");
-    file_name(xrom);
-
-    if (contax < 3)
-                 {
-                 printf("\nROMs directory empty!\n");
-                 exit(EXIT_FAILURE);
-                 }
-                 
     app_data.crc = crc32_file(file);
     crcx = app_data.crc;
-    suck_roms();
     
-    strcpy (xbios, "bios/");
+    strcpy (xbios, PREFIX);
+    strcat (xbios, "/o2em/bios/");
     file_name(xbios);
     suck_bios();
 
@@ -215,7 +205,10 @@
     if (!strcmp(bios,"g7400")) strcpy(bios,g7400);
     if (!strcmp(bios,"c52")) strcpy(bios,c52);
     if (!strcmp(bios,"jopac")) strcpy(bios,jopac);
-    if ((!strcmp(bios,"")) || (!strcmp(bios,"o2rom"))) strcpy(bios,"bios/o2rom.bin");
+    if ((!strcmp(bios,"")) || (!strcmp(bios,"o2rom"))){
+         strcpy(bios, PREFIX); 
+         strcat(bios,"/o2em/bios/o2rom.bin");
+    }
     
     
     
@@ -630,8 +623,8 @@
     int i;
     for (i=0; i<contax; ++i)
         {
-    
-                 strcpy(biossux,"bios/");
+                 strcpy(biossux, PREFIX);
+                 strcat(biossux,"/o2em/bios/");
                  strcat(biossux,arkivo[i]);
   
                  app_data.crc = crc32_file(biossux);
