--- src/daap.c.orig	2008-04-19 21:17:23.000000000 +0200
+++ src/daap.c	2008-07-18 16:32:13.000000000 +0200
@@ -175,7 +175,7 @@ int daap_add_mdcl(DAAP_BLOCK *root, char
 
     mdcl=daap_add_empty(root,"mdcl");
     if(mdcl) {
-	g=(int)daap_add_string(mdcl,"mcnm",tag);
+	g = !!daap_add_string(mdcl,"mcnm",tag);
 	g = g && daap_add_string(mdcl,"mcna",name);
 	g = g && daap_add_short(mdcl,"mcty",number);
     }
@@ -202,7 +202,7 @@ DAAP_BLOCK *daap_response_content_codes(
 
     root=daap_add_empty(NULL,"mccr");
     if(root) {
-	g = (int)daap_add_int(root,"mstt",200);
+	g = !!daap_add_int(root,"mstt",200);
 
 	while(current->type) {
 	    g = g && daap_add_mdcl(root,current->tag,current->description,
@@ -235,7 +235,7 @@ DAAP_BLOCK *daap_response_login(char *ho
 
     root=daap_add_empty(NULL,"mlog");
     if(root) {
-	g = (int)daap_add_int(root,"mstt",200);
+	g = !!daap_add_int(root,"mstt",200);
 	session=config_get_next_session();
 	g = g && daap_add_int(root,"mlid",session);
     }
@@ -437,7 +437,7 @@ DAAP_BLOCK *daap_response_songlist(char*
 
     root=daap_add_empty(NULL,"adbs");
     if(root) {
-	g = (int)daap_add_int(root,"mstt",200);
+	g = !!daap_add_int(root,"mstt",200);
 	g = g && daap_add_char(root,"muty",0);
 	g = g && daap_add_int(root,"mtco",0);
 	g = g && daap_add_int(root,"mrco",0);
@@ -630,7 +630,7 @@ DAAP_BLOCK *daap_response_update(int fd,
 
     root=daap_add_empty(NULL,"mupd");
     if(root) {
-	g = (int)daap_add_int(root,"mstt",200);
+	g = !!daap_add_int(root,"mstt",200);
 	/* theoretically, this would go up if the db changes? */
 	g = g && daap_add_int(root,"musr",db_version());
     }
@@ -661,7 +661,7 @@ DAAP_BLOCK *daap_response_playlists(char
     
     root=daap_add_empty(NULL,"aply");
     if(root) {
-	g = (int)daap_add_int(root,"mstt",200);
+	g = !!daap_add_int(root,"mstt",200);
 	g = g && daap_add_char(root,"muty",0); 
 	g = g && daap_add_int(root,"mtco",1 + db_get_playlist_count());
 	g = g && daap_add_int(root,"mrco",1 + db_get_playlist_count());
@@ -731,7 +731,7 @@ DAAP_BLOCK *daap_response_dbinfo(char *n
     
     root=daap_add_empty(NULL,"avdb");
     if(root) {
-	g = (int)daap_add_int(root,"mstt",200);
+	g = !!daap_add_int(root,"mstt",200);
 	g = g && daap_add_char(root,"muty",0); 
 	g = g && daap_add_int(root,"mtco",1);
 	g = g && daap_add_int(root,"mrco",1);
@@ -788,7 +788,7 @@ DAAP_BLOCK *daap_response_server_info(ch
 	    apro = 2 << 16;
 	}
 
-	g = (int)daap_add_int(root,"mstt",200); /* result */
+	g = !!daap_add_int(root,"mstt",200); /* result */
 	g = g && daap_add_int(root,"mpro",mpro); /* dmap proto ? */
 	g = g && daap_add_int(root,"apro",apro); /* daap protocol */
 
@@ -889,7 +889,7 @@ DAAP_BLOCK *daap_response_playlist_items
 
     root=daap_add_empty(NULL,"apso");
     if(root) {
-	g = (int)daap_add_int(root,"mstt",200);
+	g = !!daap_add_int(root,"mstt",200);
 	g = g && daap_add_char(root,"muty",0);
 	g = g && daap_add_int(root,"mtco",0);
 	g = g && daap_add_int(root,"mrco",0);
