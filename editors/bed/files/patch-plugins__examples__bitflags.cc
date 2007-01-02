--- plugins/examples/bitflags.cc.orig	Thu Apr 17 09:16:56 2003
+++ plugins/examples/bitflags.cc	Mon Jan  1 23:58:08 2007
@@ -76,8 +76,8 @@
 			else
 				betweenflags=NULL;
 	
-			table=new (char*)[maxtable];
-			lens=new (char)[maxtable];
+			table=new char*[maxtable];
+			lens=new char[maxtable];
 			
 			memcpy(lens,fl.lens,insidetable*sizeof(char));
 			for(int i=0;i<insidetable;i++) {
@@ -97,8 +97,8 @@
 	noflag('-'), 
 
 	maxtable(1) {
-		table=new (char *)[maxtable];
-		lens=new (char)[maxtable];
+		table=new char *[maxtable];
+		lens=new char[maxtable];
 		insidetable=0;
 		half=maxres;
 		recalc();
@@ -227,8 +227,8 @@
 		return -1;
 	char *convptr=convstr,*end;
 	int bitten=datbytes()*8;
-	char **newtable=new (char *)[bitten];
-	char *newlens=new (char )[bitten];
+	char **newtable=new char *[bitten];
+	char *newlens=new char [bitten];
 	for(nrtable=0;nrtable<bitten&&convptr<afterflags;nrtable++) {	
 		end=(char *)memchr(convptr,',',afterflags-convptr);
 		if(!end||end>afterflags)
@@ -369,7 +369,7 @@
 		bytes=bitflags->datbytes();
 		created=0;
 		 maxtable=bitflags->maxtable;
-		newtable= new (char *)[maxtable];
+		newtable= new char *[maxtable];
 		lens = new char[maxtable];
 		insidetable=bitflags->insidetable;
 		memmove(lens,bitflags->lens,sizeof(char)*insidetable);
@@ -551,8 +551,8 @@
 				if(bit<bitten) {
 					char **oldtable=newtable;
 					char *oldlens=lens;
-					newtable=new (char*)[bitten];
-					lens=new (char)[bitten];
+					newtable=new char*[bitten];
+					lens=new char[bitten];
 					if(insidetable>0) {
 						memcpy(newtable,oldtable,insidetable*sizeof(char *));
 						memcpy(lens,oldlens,insidetable*sizeof(char ));
