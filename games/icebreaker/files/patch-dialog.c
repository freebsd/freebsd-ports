--- ./dialog.c.orig	2002-06-02 16:25:51.000000000 +0200
+++ ./dialog.c	2013-12-24 13:42:35.000000000 +0100
@@ -287,10 +287,10 @@
 
 	for (i=0;i<HISCORENUM;i++)
 	{
-		snprintf(buf,4,"%d.",i+1);
+		snprintf(buf,sizeof(buf),"%d.",i+1);
 		puttext(scorelistrect.x+BLOCKWIDTH,scorelistrect.y+45+i*(CHARHEIGHT*2+5),2,color.normaltext,buf);		
 		puttext(scorelistrect.x+BLOCKWIDTH*4,scorelistrect.y+45+i*(CHARHEIGHT*2+5),2,color.normaltext,hiscorename[i]);		
-		snprintf(buf,30,"%ld",hiscoreval[i]);		
+		snprintf(buf,sizeof(buf),"%ld",hiscoreval[i]);		
 		puttext(scorelistrect.x+scorelistrect.w-(BLOCKWIDTH*5),scorelistrect.y+45+i*(CHARHEIGHT*2+5),2,color.normaltext,buf);
 	}
 	
@@ -372,7 +372,7 @@
 	{
 		puttext(helprect.x+BLOCKWIDTH/2,helprect.y+BLOCKHEIGHT/2+i*(CHARHEIGHT*2+4),2,color.normaltext,helptext[i]);		
 	}
-	snprintf(buf,80,"v%d.%d.%d   %s",VERMAJOR,VERMINOR,VERSUB,"Copyright (c) 2000-2002 Matthew Miller. Released under the GPL.");
+	snprintf(buf,sizeof(buf),"v%d.%d.%d   %s",VERMAJOR,VERMINOR,VERSUB,"Copyright (c) 2000-2002 Matthew Miller. Released under the GPL.");
 	puttext(helprect.x+BLOCKWIDTH/2,helprect.y+helprect.h-CHARHEIGHT*3,1,color.copyrighttext,buf);		
 	puttext(helprect.x+BLOCKWIDTH/2,helprect.y+helprect.h-CHARHEIGHT*1-3,1,color.copyrighttext,"Thanks to my wonderful wife Karen for inspiration (and for patience)!");		
 	
