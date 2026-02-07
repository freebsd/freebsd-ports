--- ./g_svcmds.c.orig	Sat Dec 30 19:09:03 2006
+++ ./g_svcmds.c	Sat Dec 30 19:09:23 2006
@@ -310,8 +310,8 @@
 	}
 
 	//‚Æ‚è‚ ‚¦‚¸CTF‚¾‚ß
-	if(ctf->value) 	sprintf(name,".\\%s\\chctf\\%s.chf",gamepath->string,level.mapname);
-	else 	sprintf(name,".\\%s\\chdtm\\%s.chn",gamepath->string,level.mapname);
+	if(ctf->value) 	sprintf(name,"%s/chctf/%s.chf",gamepath->string,level.mapname);
+	else 	sprintf(name,"%s/chdtm/%s.chn",gamepath->string,level.mapname);
 
 	fpout = fopen(name,"wb");
 	if(fpout == NULL) gi.cprintf(NULL,PRINT_HIGH,"Can't open %s\n",name);
