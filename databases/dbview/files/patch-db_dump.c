--- db_dump.c.orig	Thu May 30 14:15:30 2002
+++ db_dump.c Wed Apr 17 15:56:46 2002
@@ -164,6 +164,9 @@
 int	flags;
 {
     int             fields;
+    char	    *info;
+    char	    *lang;
+    char	    *cdx;
     DBASE_FIELD     *fld;
 
     if(dbfile==-1) {
@@ -171,26 +174,71 @@
         return;
         }
     read(dbfile,&dbhead,sizeof(DBASE_HEAD));
-    if( !(dbhead.version==3 || dbhead.version==0x83) ) {
+    if ( ! ( dbhead.version==0x03 || dbhead.version==0x83 || dbhead.version==0x04 || dbhead.version==0x05 || dbhead.version==0x8b || dbhead.version==0xf5 ) ) {
         printf ("Version %d not supported\n",dbhead.version);
-	if(dbhead.version==0x8b ) {
-	    printf ("dBase IV - partially known...\n");
+	if (dbhead.version==0x8e ) {
+	    printf ("dBase IV or dBase V with SQL table - partially known...\n");
 	}
+	if (dbhead.version==0x43 || dbhead.version==0xb3){
+	    printf ("FlagShip - partially known...\n");
+        }
 	return;
     }
+    if (dbhead.version==0x03){
+ 	info="Plain dbf, dBaseIII+";
+    }
+    if (dbhead.version==0x04){
+ 	info="Plain dbf, dBaseIV+";
+    }
+    if (dbhead.version==0x05){
+ 	info="Plain dbf, dBaseV or FoxPro";
+    }
+    if (dbhead.version==0x83){
+ 	info="dBaseIII+ w/memo";
+    }
+    if (dbhead.version==0x8b){
+ 	info="dBaseIV+ w/memo";
+    }
+    if (dbhead.version==0xf5){
+ 	info="FoxPro w/memo";
+    }
+
+    fields=(dbhead.header-1)/32-1;
 
+    if (dbhead.excdx){
+	cdx="Yes";
+    }
+    else{
+	cdx="No";
+    }
+    if (dbhead.language==101){
+	lang="DOS 866";
+    }
+    else if (dbhead.language==2){
+	lang="WIN 1251";
+    }
+    else if (dbhead.language==2){
+	lang="DOS 850 Multi ling";
+    }
+    else if (dbhead.language==1){
+	lang="DOS 437 USA";
+    }
+    else{
+	lang="Unknown";
+    }
     if (flags & DB_FL_INFO) {
-	printf("File version  : %d\n",dbhead.version);
-	printf("Last update   : %02d/%02d/%2d\n", dbhead.l_update[1],dbhead.l_update[2],dbhead.l_update[0]);
-	printf("Number of recs: %ld\n",dbhead.count);
-	printf("Header length : %d\n",dbhead.header);
-	printf("Record length : %d\n",dbhead.lrecl);
+	printf("File version    : %d, %s\n",dbhead.version,info);
+	printf("Last update     : %02d/%02d/%2d\n", dbhead.l_update[1],dbhead.l_update[2],dbhead.l_update[0]+1900);
+	printf("Number of recs  : %ld\n",dbhead.count);
+	printf("Header length   : %d\n",dbhead.header);
+	printf("Record length   : %d\n",dbhead.lrecl);
+	printf("Exist index cdx : %s\n",cdx);
+	printf("Language ID     : %s\n",lang);
+	printf("Count fields    : %d\n\n",fields);
     }
 
     Buffer=malloc(dbhead.lrecl);
- 
-    fields=(dbhead.header-1)/32-1;
-    
+
     if (flags & DB_FL_DESCR) {
 	printf("Field Name\tType\tLength\tDecimal Pos\n");
     }
@@ -227,7 +275,7 @@
 char	delim;
 {
     int     bytes;
- 
+    lseek(dbfile,dbhead.header,SEEK_SET);
     while(cnt) {
         bytes=read(dbfile,Buffer,dbhead.lrecl);
         if(bytes!=dbhead.lrecl)
@@ -253,7 +301,6 @@
 char	delim;
 {
     FLD_LIST    *temp;
- 
     temp=db_fld_root;
     while (temp) {
         memcpy(buf_work,temp->data,temp->fld->length);
