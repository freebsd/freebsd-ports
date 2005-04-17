--- formats.c	Sat May 31 14:47:58 1997
+++ formats.c	Wed Apr 13 00:21:47 2005
@@ -27,7 +27,7 @@
 int len,fs,i;
 
 	len=ftell(out_file)-44;
-	fs=t_sampling_frequency[header->ID][header->sampling_frequency];
+	fs=t_sampling_frequency[header->IDex][header->ID][header->sampling_frequency];
 	rewind(out_file);
 	fwrite(ispred,1,20,out_file);
 
