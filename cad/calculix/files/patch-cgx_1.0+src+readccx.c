--- cgx_1.0/src/readccx.c.org	Wed Apr  9 00:32:46 2003
+++ cgx_1.0/src/readccx.c	Sun Jul 27 15:24:28 2003
@@ -357,7 +357,7 @@
     /* delete blanks */
     n=0; for(j=0;j<strlen(dat[i]); j++) if(dat[i][j]!=' ') { buffer[n]=dat[i][j]; n++; }
     buffer[n]=(unsigned char)NULL;
-    for(j=0;j<strlen(buffer); j++) dat[i][j]=_toupper(buffer[j]);
+    for(j=0;j<strlen(buffer); j++) dat[i][j]=toupper(buffer[j]);
     if(compare(dat[i],"NAME=",5)==5) { strcpy(set,&buffer[5]); } 
   }
   if(printFlag) printf("*SURFACE DEFINITION: %s\n",set);
@@ -479,7 +479,7 @@
 
 
   /* check if it is a node section */
-  for(j=0;j<strlen(rec_str); j++) { if(rec_str[j]==',') break; rec_str[j]=_toupper(rec_str[j]);}
+  for(j=0;j<strlen(rec_str); j++) { if(rec_str[j]==',') break; rec_str[j]=toupper(rec_str[j]);}
   if((compare(rec_str,"*NODE PRINT",11)==11)||
      (compare(rec_str,"*NODE FILE",10)==10))
   {
@@ -500,7 +500,7 @@
     /* delete blanks */
     n=0; for(j=0;j<strlen(dat[i]); j++) if(dat[i][j]!=' ') { buffer[n]=dat[i][j]; n++; }
     buffer[n]=(unsigned char)NULL;
-    for(j=0;j<strlen(buffer); j++) dat[i][j]=_toupper(buffer[j]);
+    for(j=0;j<strlen(buffer); j++) dat[i][j]=toupper(buffer[j]);
     if(compare(dat[i],"NSET=",5)==5) { setFlag=1; strcpy(set,&buffer[5]); } 
   }
   if(printFlag) printf("*NODE: NSET=%s\n", set);
@@ -815,7 +815,7 @@
     /* delete blanks */
     n=0; for(j=0;j<strlen(dat[i]); j++) if(dat[i][j]!=' ') { buffer[n]=dat[i][j]; n++; }
     buffer[n]=(unsigned char)NULL;
-    for(j=0;j<strlen(buffer); j++) dat[i][j]=_toupper(buffer[j]);
+    for(j=0;j<strlen(buffer); j++) dat[i][j]=toupper(buffer[j]);
     if(compare(dat[i],"TYPE=",5)==5) strcpy(elemtyp,&buffer[5]);
     if(compare(dat[i],"ELSET=",6)==6) { strcpy(set,&buffer[6]); setFlag=1; } 
   }
@@ -977,7 +977,7 @@
     /* delete blanks */
     n=0; for(j=0;j<strlen(dat[i]); j++) if(dat[i][j]!=' ') { buffer[n]=dat[i][j]; n++; }
     buffer[n]=(unsigned char)NULL;
-    for(j=0;j<strlen(buffer); j++) dat[i][j]=_toupper(buffer[j]);
+    for(j=0;j<strlen(buffer); j++) dat[i][j]=toupper(buffer[j]);
     if(compare(dat[i],"NAME=",5)==5) strcpy(mname,&buffer[5]);
   }
   if(printFlag) printf("*MATERIAL:%s\n", mname);
@@ -1021,7 +1021,7 @@
     /* delete blanks */
     n=0; for(j=0;j<strlen(dat[i]); j++) if(dat[i][j]!=' ') { buffer[n]=dat[i][j]; n++; }
     buffer[n]=(unsigned char)NULL;
-    for(j=0;j<strlen(buffer); j++) dat[i][j]=_toupper(buffer[j]);
+    for(j=0;j<strlen(buffer); j++) dat[i][j]=toupper(buffer[j]);
     if(compare(dat[i],"TYPE=",5)==5) strcpy(type,&buffer[5]);
   }
   if(printFlag) printf("*ELASTIC: TYPE:%s\n", type);
@@ -1073,7 +1073,7 @@
     /* delete blanks */
     n=0; for(j=0;j<strlen(dat[i]); j++) if(dat[i][j]!=' ') { buffer[n]=dat[i][j]; n++; }
     buffer[n]=(unsigned char)NULL;
-    for(j=0;j<strlen(buffer); j++) dat[i][j]=_toupper(buffer[j]);
+    for(j=0;j<strlen(buffer); j++) dat[i][j]=toupper(buffer[j]);
     if(compare(dat[i],"TYPE=",5)==5) strcpy(type,&buffer[5]);
   }
   if(printFlag) printf("*EXPANSION:TYPE:%s\n", type);
@@ -1480,7 +1480,7 @@
     /* delete blanks */
     n=0; for(j=0;j<strlen(dat[i]); j++) if(dat[i][j]!=' ') { buffer[n]=dat[i][j]; n++; }
     buffer[n]=(unsigned char)NULL;
-    for(j=0;j<strlen(buffer); j++) dat[i][j]=_toupper(buffer[j]);
+    for(j=0;j<strlen(buffer); j++) dat[i][j]=toupper(buffer[j]);
     if(compare(dat[i],"ELSET=",6)==6) strcpy(set,&buffer[6]);
     if(compare(dat[i],"GENERATE",5)==5) generate=1;
   }
@@ -1537,7 +1537,7 @@
     /* delete blanks */
     n=0; for(j=0;j<strlen(dat[i]); j++) if(dat[i][j]!=' ') { buffer[n]=dat[i][j]; n++; }
     buffer[n]=(unsigned char)NULL;
-    for(j=0;j<strlen(buffer); j++) dat[i][j]=_toupper(buffer[j]);
+    for(j=0;j<strlen(buffer); j++) dat[i][j]=toupper(buffer[j]);
     if(compare(dat[i],"NSET=",5)==5) strcpy(set,&buffer[5]);
     if(compare(dat[i],"GENERATE",5)==5) generate=1;
   }
@@ -1605,7 +1605,7 @@
     /* delete blanks */
     n=0; for(j=0;j<strlen(dat[i]); j++) if(dat[i][j]!=' ') { buffer[n]=dat[i][j]; n++; }
     buffer[n]=(unsigned char)NULL;
-    for(j=0;j<strlen(buffer); j++) dat[i][j]=_toupper(buffer[j]);
+    for(j=0;j<strlen(buffer); j++) dat[i][j]=toupper(buffer[j]);
     if(compare(dat[i],"ELSET=",6)==6) strcpy(elset,&buffer[6]);
     if(compare(dat[i],"MATERIAL=",9)==9) strcpy(material,&buffer[9]);
     if((compare(buffer,"NODAL",5)==5)||
@@ -1672,7 +1672,7 @@
     /* delete blanks */
     n=0; for(j=0;j<strlen(dat[i]); j++) if(dat[i][j]!=' ') { buffer[n]=dat[i][j]; n++; }
     buffer[n]=(unsigned char)NULL;
-    for(j=0;j<strlen(buffer); j++) dat[i][j]=_toupper(buffer[j]);
+    for(j=0;j<strlen(buffer); j++) dat[i][j]=toupper(buffer[j]);
     if(compare(dat[i],"ELSET=",6)==6) strcpy(elset,&buffer[6]);
     if(compare(dat[i],"MATERIAL=",9)==9) strcpy(material,&buffer[9]);
     if((compare(buffer,"COMPOS",5)==5)||
@@ -1726,14 +1726,14 @@
     /* delete blanks */
     n=0; for(j=0;j<strlen(dat[i]); j++) if(dat[i][j]!=' ') { buffer[n]=dat[i][j]; n++; }
     buffer[n]=(unsigned char)NULL;
-    for(j=0;j<strlen(buffer); j++) dat[i][j]=_toupper(buffer[j]);
+    for(j=0;j<strlen(buffer); j++) dat[i][j]=toupper(buffer[j]);
     if(compare(dat[i],"TYPE=",5)==5)
     {
       strcpy(dat[i],&buffer[5]);
       /* delete blanks */
       n=0; for(j=0;j<strlen(dat[i]); j++) if(dat[i][j]!=' ') { buffer[n]=dat[i][j]; n++; }
       buffer[n]=(unsigned char)NULL;
-      for(j=0;j<strlen(buffer); j++) dat[i][j]=_toupper(buffer[j]);
+      for(j=0;j<strlen(buffer); j++) dat[i][j]=toupper(buffer[j]);
       if(compare(dat[i],"TEMPERATURE",6)==6)
       {
         if(printFlag) printf("*INITIAL CONDITIONS: TYPE:%s \n", buffer);
@@ -1914,7 +1914,7 @@
     args=crecord(rec_str, dat);
 
     /* get the arguments of the string */
-    i=0; while(dat[0][i]!=(unsigned char)NULL) { dat[0][i]=_toupper(dat[0][i]); i++; }
+    i=0; while(dat[0][i]!=(unsigned char)NULL) { dat[0][i]=toupper(dat[0][i]); i++; }
 
     /* get the nodes */
     if (compare(dat[0], "*NODE",5)==5) { length=getNodes(rec_str); goto checknextstr; }
