--- bdb.c.orig	Wed May 14 04:49:59 1997
+++ bdb.c	Fri Feb  2 04:22:00 2001
@@ -325,8 +325,8 @@
    char names[10][100],text[100];
    int ch,scores[10],i;
                                 /* If not there, create one */
-   if( (fff=fopen("hiscore.sea","r+"))==NULL ){
-        if ( (fff=fopen("hiscore.sea","a+"))!=NULL) {
+   if( (fff=fopen(DATADIR "/hiscore.sea","r+"))==NULL ){
+        if ( (fff=fopen(DATADIR "/hiscore.sea","a+"))!=NULL) {
 	   fprintf(fff,"Vince\n50\nMarie\n55\nJohn\n56\n");
 	   fprintf(fff,"Gus\n57\nLizann\n58\nKevin\n59\n");
 	   fprintf(fff,"Hal\n60\nHairold\n61\nChipper\n62\nBob\n63\n");
@@ -335,7 +335,7 @@
    }
    else fclose(fff);
    
-   if ( (fff=fopen("hiscore.sea","r"))!=NULL) {
+   if ( (fff=fopen(DATADIR "/hiscore.sea","r"))!=NULL) {
    for(i=0;i<10;i++)
      fscanf(fff,"%s%i",names[i],&scores[i]);
      fclose(fff);
@@ -355,7 +355,7 @@
      set_color(C_WHITE,C_BOLD); 
      sprintf(text,"%s got a new High Score, #%i",name,i+1);
      printxy(20,1,text);
-     if ( (fff=fopen("hiscore.sea","w+"))!=NULL) {
+     if ( (fff=fopen(DATADIR "/hiscore.sea","w+"))!=NULL) {
        for(i=0;i<10;i++) fprintf(fff,"%s\n%i",names[i],scores[i]);
        fclose(fff);
      }
