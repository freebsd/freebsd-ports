--- ./hiscore.c.orig	2002-06-02 16:28:35.000000000 +0200
+++ ./hiscore.c	2013-12-24 13:42:35.000000000 +0100
@@ -72,7 +72,7 @@
 	// make sure all entries are zeroed out to start.
 	for (i=0;i<HISCORENUM;i++)
 	{
-		snprintf(temphiscorename[i],7,"Nobody");
+		strcpy(temphiscorename[i],"Nobody");
 		temphiscoreval[i]=100; //100 is better than 0. :)
 	}
 
@@ -103,7 +103,7 @@
 	// ok, so now, we can copy things over in the proper sorted order
 	for (i=0;i<HISCORENUM;i++)
 	{
-		snprintf(hiscorename[i],50,temphiscorename[arrayindex[i]]);
+		snprintf(hiscorename[i],50,"%s",temphiscorename[arrayindex[i]]);
 		hiscoreval[i]=temphiscoreval[arrayindex[i]];
 	}
 
@@ -201,7 +201,7 @@
 	// make sure the temp array contains the right data
 	for (i=0;i<HISCORENUM;i++)
 	{
-		snprintf(temphiscorename[i],50,hiname[i]);
+		snprintf(temphiscorename[i],50,"%s",hiname[i]);
 		temphiscoreval[i]=hival[i];
 	}
 	
@@ -221,7 +221,7 @@
 	// and take the top ones back.
 	for (i=0;i<HISCORENUM;i++)
 	{
-		snprintf(hiname[i],50,temphiscorename[arrayindex[i]]); 
+		snprintf(hiname[i],50,"%s",temphiscorename[arrayindex[i]]);
 		hival[i]=temphiscoreval[arrayindex[i]];
 	}
 }
