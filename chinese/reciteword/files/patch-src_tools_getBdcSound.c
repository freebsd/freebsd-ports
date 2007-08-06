--- src/tools/getBdcSound.c.orig	2003-03-06 19:03:19.000000000 +0800
+++ src/tools/getBdcSound.c	2007-07-30 16:38:45.000000000 +0800
@@ -16,8 +16,8 @@
 	static unsigned char c2[21],b1[21];
 	int i,j,len;	
 	
-	strcpy(b1,str);
-	len = strlen(b1);
+	strcpy((char *)b1,(char *)str);
+	len = strlen((char *)b1);
 
 	if (len==1)
     {
@@ -262,7 +262,7 @@
         wav[57]= (((wavweight) & 0xff000000)>>24);		
 		fseek(wordwavFile,wavbegin,0);
 		fread(&wav[0x3a], wavweight,1,wordwavFile);
-		str = get_word_str(idxbuf);
+		str = (char *)get_word_str(idxbuf);
 		dirchar = tolower(str[0]);	
 		sprintf(wavfilename,"BdcSound/%c/%s.wav",dirchar,str);
 		if (!stat(wavfilename, &st))
