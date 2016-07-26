--- formats.c.orig	1997-05-31 17:47:58 UTC
+++ formats.c
@@ -27,7 +27,7 @@ unsigned char iza[8]={0x64 ,0x61 ,0x74 ,
 int len,fs,i;
 
 	len=ftell(out_file)-44;
-	fs=t_sampling_frequency[header->ID][header->sampling_frequency];
+	fs=t_sampling_frequency[header->IDex][header->ID][header->sampling_frequency];
 	rewind(out_file);
 	fwrite(ispred,1,20,out_file);
 
