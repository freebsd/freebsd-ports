--- src/main.h~	Sat Jun  2 12:15:39 2001
+++ src/main.h	Tue Apr 23 21:16:13 2002
@@ -30,7 +30,7 @@
 
 typedef struct _WaveInfo {
 	char id_riff[4];
-	int riff_size;
+	guint32 riff_size;
 	char type_riff[4];
 	char id_fmt[4];
 	int fmt_size;
@@ -41,7 +41,7 @@
 	short int size_per_sample;
 	short int bits_per_sample;
 	char id_data[4];
-	int data_size;
+	guint32 data_size;
 } WaveInfo;
 
 typedef struct _Buttons {
