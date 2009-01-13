--- holyshout.c.orig	2003-11-25 08:43:07.000000000 +0100
+++ holyshout.c	2007-11-09 01:09:35.000000000 +0100
@@ -44,33 +44,34 @@
 char **play_list , **pointer_list , listfile[0xff];
 int play_list_num=0 , shuffle=0 , encode=0, nal=0 ;
 struct timeval lastint, shoutstart;
-lame_global_flags gf ; 
+lame_global_flags *gf ; 
 
 int main(int argc , char **argv)
 {
     int playlist = 0 , loop=0 , check=0 , ch ;
     struct hostent *host ;
-    shout_conn_t conn;
+    shout_t *conn;
 
     signal (SIGINT, s1gnal); signal (SIGHUP, s1gnal);
 
     /* Shout default informaton descriptions. But , It can change using
        Options. do not change that. */
 
-    lame_init(&gf) ;
-    shout_init_connection(&conn);
-    conn.name="AP_"PROGRAM_NAME"_"VERSION ;
-    conn.mount="default" ;
-    conn.description="HOLYSHOUT";
-    conn.url="http://www.icecast.org";
+    gf = lame_init() ;
+    shout_init();
+    conn = shout_new();
+    shout_set_name(conn, "AP_"PROGRAM_NAME"_"VERSION);
+    shout_set_mount(conn, "default");
+    shout_set_description(conn, "HOLYSHOUT");
+    shout_set_host(conn, "http://www.icecast.org");
 
     /* Get arguments options */
     while ((ch = getopt(argc, argv, "P:p:h:l:f:m:b:g:d:n:u:s:izr")) != -1) {
         switch (ch) {
             case 'P':
-                conn.port = atoi(optarg) ; check++ ; break ;
+                shout_set_port(conn, atoi(optarg)) ; check++ ; break ;
             case 'p':
-                conn.password = optarg ; check++ ; break ;
+                shout_set_password(conn, optarg); check++ ; break ;
              case 'l':
 	        playlist=2 ; check++ ; strcpy(listfile,optarg) ; break ;
              case 'z':
@@ -78,28 +79,31 @@
              case 'f':
 	        playlist=1 ; check++ ; strcpy(listfile,optarg) ; break ;
              case 'i':
-	        conn.icy_compat=1 ; conn.ispublic=1; break ;
+           shout_set_public(conn, 1); break ;
              case 'm':
-	        conn.mount=optarg; break ;
+           shout_set_mount(conn, optarg); break ;
              case 'g':
-	        conn.genre=optarg; break ;
+           shout_set_genre(conn, optarg); break ;
              case 'd':
-	        conn.description=optarg; break ;
+           shout_set_description(conn, optarg); break ;
              case 'u':
-	        conn.url=optarg; break ;
+           shout_set_url(conn, optarg); break ;
              case 'n':
-	        conn.name=optarg; break ;
+           shout_set_name(conn, optarg); break ;
              case 'r':
 	        loop=1 ; break ;
              case 's':
-	        gf.mode=atoi(optarg); break ;
+	        lame_set_mode(gf, atoi(optarg)); break ;
              case 'b':
-		check++ ;
-		if (!strcmp(optarg,"auto") || !strcmp(optarg,"AUTO")) encode=0;
-		else {
-	            conn.bitrate=atoi(optarg); gf.brate=conn.bitrate; encode=1; 
-		}
-		break ;
+           check++ ;
+           if (!strcmp(optarg,"auto") || !strcmp(optarg,"AUTO")) encode=0;
+           else {
+              /*
+               * XXX
+              conn.bitrate=atoi(optarg); lame_set_brate(gf, conn.bitrate); encode=1; 
+              */
+           }
+           break ;
              case '?':
              default:
                 usage();
@@ -114,7 +118,7 @@
 
     /* find a address , if the address is a dns , lookup ip */
     if (isdigit(argv[argc-1][0])) {
-        conn.ip = argv[argc-1] ;
+        shout_set_host(conn, argv[argc-1]);
     } else {
         if (argv[argc-1] == NULL) {
             puts("You must specify server name"); exit(0);
@@ -130,27 +134,28 @@
             exit(0);
         }
 
-        conn.ip = (char *)inet_ntoa(*((struct in_addr *)host->h_addr)) ;
-	if (conn.ip == NULL) {
+        shout_set_host(conn, (char *)inet_ntoa(*((struct in_addr *)host->h_addr))) ;
+	if (shout_get_host(conn) == NULL) {
             printf("Can't resolv %s\n",argv[argc-1]) ;
             exit(0);
         }
     }
 
    /* connect to shoutcast (icecast) server. */
-    if (shout_connect(&conn)) {
+    shout_open(conn);
+    if(shout_get_connected(conn) == SHOUTERR_CONNECTED)  {
         printf("Connected.\n");
     } else {
-        printf("Couldn't connect %s:%d (Error Code %d)\n",conn.ip, conn.port ,conn.error);
+        printf("Couldn't connect %s:%d (Error Code %d)\n", shout_get_host(conn), shout_get_port(conn), shout_get_errno(conn));
         /* if the server is a shoutcast , automatic retry using -i */
-        if (conn.error==3) {
+        if (shout_get_errno(conn)==3) {
             printf("Automatic retry using old icy header using -i option.\n");
-            shout_disconnect(&conn) ;
-            conn.icy_compat=1 ; conn.ispublic=1;
-            if (shout_connect(&conn)) {
+            shout_close(conn) ;
+            shout_set_public(conn, 1);
+            if (shout_get_connected(conn) == SHOUTERR_CONNECTED) {
                 printf("Connected.\n");
             } else {
-                printf("Couldn't connect %s:%d (Error Code %d)\n",conn.ip, conn.port ,conn.error);
+                printf("Couldn't connect %s:%d (Error Code %d)\n", shout_get_host(conn), shout_get_port(conn), shout_get_error(conn));
                 exit(0);
             }
         } else {
@@ -183,13 +188,13 @@
         } else usage() ;
         if (loop==0) break ; else puts("Loopping....");
     }
-    shout_disconnect(&conn);
+    shout_close(conn);
 
     return 0 ;
 }
 
 
-int send_setram (shout_conn_t conn , char *filename) 
+int send_setram (shout_t *conn , char *filename) 
 {
     char buff[LAME_MAXMP3BUFFER*2] ;
     char mp3buffer[LAME_MAXMP3BUFFER];
@@ -207,19 +212,13 @@
         return 1 ;
     }
 
-    gf.inPath=filename ;
-    gf.outPath="Streamming server";
+    lame_set_quality(gf, 5);
+    lame_set_num_channels(gf, 2);
 
-    gf.input_format=sf_mp3 ;
-    //gf.mode_fixed=1 ;
-    gf.quality=5 ;
-    gf.num_channels=2;
-
-    lame_init_infile(&gf) ; lame_init_params(&gf) ; lame_print_config(&gf) ;
+    lame_print_config(gf);
 
     do {
-        iread = lame_readframe(&gf,Buffer) ;
-        imp3=lame_encode_buffer(&gf,Buffer[0],Buffer[1],iread, mp3buffer,(int)sizeof(mp3buffer));
+        imp3=lame_encode_buffer(gf,Buffer[0],Buffer[1],iread, mp3buffer,(int)sizeof(mp3buffer));
 
         /* Get the SIGINT . skipped to the next song. */
         if (nal==1) { nal=0 ; break ; }
@@ -230,12 +229,12 @@
         }
 
         if (buf_loc >= buff_size) {
-            ret = shout_send_data(&conn, buff, buf_loc);
-            if (!ret) {
-                fprintf(stderr,"SEND_ERROR : %i...\n", conn.error);
+            ret = shout_send_raw(conn, buff, buf_loc);
+            if (ret) {
+                fprintf(stderr,"SEND_ERROR : %s...\n", shout_get_error(conn));
                 break;
             } 
-            shout_sleep(&conn);
+            shout_sync(conn);
             buf_loc=0 ;
             if (buff_size < MAX_BUF) buff_size += INC_BUF ;
         } 
@@ -246,14 +245,12 @@
     } while(iread) ;
 
     if (buf_loc > 0) {
-        ret = shout_send_data(&conn, buff, buf_loc);
-        shout_sleep(&conn);
+        ret = shout_send(conn, buff, buf_loc);
+        shout_sync(conn);
     }
 
-    imp3=lame_encode_finish(&gf,mp3buffer,(int)sizeof(mp3buffer));
-    //ret = shout_send_data(&conn, mp3buffer, imp3);
-    lame_close_infile(&gf) ;
-    lame_mp3_tags(&gf) ;
+    imp3=lame_encode_flush(gf,mp3buffer,(int)sizeof(mp3buffer));
+    lame_close(gf) ;
     puts("") ;
 
    return 0 ;
@@ -280,11 +277,11 @@
 	fclose(fp) ;
 	    
 	// memory allocation play list //
-        if (!((char **)play_list = (char **) malloc (sizeof(char*)*play_list_num))){
+        if (!(play_list = malloc (sizeof(char*)*play_list_num))){
 	    fprintf(stderr,"malloc failed") ; exit(0);
 	}
 	// memory allocation pointer //
-        if (!((char **)pointer_list = (char **) malloc (sizeof(char*)*play_list_num))){
+        if (!(pointer_list = malloc (sizeof(char*)*play_list_num))){
 	    fprintf(stderr,"malloc failed") ; exit(0);
 	}
 
@@ -298,7 +295,7 @@
         while( (fgets(buf,0xff,fp))) {
 	    if (!mp3_extension_compare(buf)) continue ;
             buf[strlen(buf)-1] = '\0' ; 
-	    (char *)play_list[i] = (char *) malloc(sizeof(char)*strlen(buf)+1) ;
+	    play_list[i] = malloc(sizeof(char)*strlen(buf)+1) ;
 	    strcpy(play_list[i],buf) ;
 	    pointer_list[i] = play_list[i] ;
 	    i++ ;
@@ -349,7 +346,7 @@
     }
 }
 
-int send_setram_direct (shout_conn_t conn , char *filename) 
+int send_setram_direct (shout_t *conn , char *filename) 
 {
     char buff[4096] ;
     int read, total , ret, file_size;
@@ -376,12 +373,12 @@
         if (nal==1) { nal=0 ; break ; }
 
         if (read>0) {
-            ret = shout_send_data(&conn,buff,read) ;
-            if (!ret) {
-                fprintf(stderr,"SEND_ERROR : %i...\n",conn.error) ;
+            ret = shout_send(conn,buff,read) ;
+            if (ret) {
+                fprintf(stderr,"SEND_ERROR : %s...\n",shout_get_error(conn)) ;
                 break ;
             } 
-            shout_sleep(&conn) ;
+            shout_sync(conn) ;
         } else break ;
         fprintf(stderr,"\rSend: %-.2f %%",((float) total / (float)file_size)*100) ;
     }
@@ -421,7 +418,7 @@
     char *code ;
         
     /* Data is null or space line */
-    if (data[0]=='\0' || data[0]=='\n' || data[0]=='') return 0 ;
+    if (data[0]=='\0' || data[0]=='\n' || data[0]=='\r') return 0 ;
 
     code = (char *)malloc ((strlen(data)+1) * sizeof (char) );
             
