--- src/tools/olddic2newdic.c.orig	Sat May  3 18:48:30 2003
+++ src/tools/olddic2newdic.c	Mon May  5 04:05:05 2003
@@ -52,28 +52,54 @@
 void convert(char *filename,char *idxheadfilename)
 {
 	struct stat stats;
+	FILE *idxheadfile;
+	gchar *buffer;
+	FILE *idxfile,*dicfile;
+	gchar str[256],basename[256];
+	long wordcount_offset;
+	glong tmpglong=0;
+	gboolean sametypesequence = FALSE;
+	int fd;
+    struct stat stStat;
+	int iFileSize;
+    unsigned int iCapacity,iStyle;
+    unsigned char cIndex, cWord, cMeaning, cMark;
+	caddr_t pFileMem;
+    caddr_t p=pFileMem;
+    caddr_t pMeaning, pMark;
+	gchar *utf8_str;
+	gsize write_size;
+	long tmp_long,wordcount=0;
+	int word_len, meaning_len,mark_len=0;
+	int iLength=0;
+	GArray *array;
+    struct _worditem worditem;
+	glong old_size;
+	long offset_old=0;
+	int i;
+	gchar *previous_word = g_strdup(""); //there should have no word equal this.
+	glong previous_datasize = 0;
+	gchar *previous_data = g_strdup("");
+	struct _worditem *pworditem;
+
+	
 	if (stat (idxheadfilename, &stats) == -1)
 	{
 		printf("idxhead file not exist!\n");
 		return;
 	}
 
-	FILE *idxheadfile;
 	idxheadfile = fopen(idxheadfilename,"r");
-	gchar *buffer;
 	buffer = (gchar *)g_malloc (stats.st_size + 1);
 	fread (buffer, 1, stats.st_size, idxheadfile);
 	fclose (idxheadfile);
 	buffer[stats.st_size] = '\0';
-	gboolean sametypesequence = FALSE;
 	if (strstr(buffer,"sametypesequence="))
 		sametypesequence = TRUE;
 	
 	//in the next code we will always treat sametypesequence to be TRUE.
 	//as now all old stardict dictionaries use these two feature.	
 	
-	FILE *idxfile,*dicfile;
-	gchar str[256],basename[256];
 	
 	strcpy(basename,idxheadfilename);
 	basename[strlen(idxheadfilename)-8]='\0';
@@ -86,11 +112,10 @@
 	fwrite(buffer, 1, stats.st_size, idxfile);
 	g_free(buffer);
 	
-	long wordcount_offset = ftell(idxfile);
-	glong tmpglong=0;
+	wordcount_offset = ftell(idxfile);
 	fwrite(&(tmpglong),sizeof(glong),1,idxfile);
 
-	int fd=open(filename,O_RDONLY);
+	fd=open(filename,O_RDONLY);
     if(fd==-1)
     {
 		g_print("open fail\n");
@@ -98,17 +123,15 @@
     }
 
     // get length of dicfile.
-    struct stat stStat;
     if(fstat(fd,&stStat)!=0)
     {
         g_print("stat fail\n");
         return;
     }
-    int iFileSize=stStat.st_size;
+    iFileSize=stStat.st_size;
     
     // get item count
     lseek(fd,0-sizeof(int)*2,SEEK_END);
-    unsigned int iCapacity,iStyle;
     read(fd,&iCapacity,sizeof(int));
     read(fd,&iStyle,sizeof(int));
 	//disable the next two line when the convert file is from the same arch machine.
@@ -117,14 +140,14 @@
     vConvertEndian(&iStyle);
 #endif
 
-    unsigned char cIndex=(unsigned char)(iStyle>>24);
-    unsigned char cWord=(unsigned char)(iStyle>>16);
-    unsigned char cMeaning=(unsigned char)(iStyle>>8);
-    unsigned char cMark=(unsigned char)iStyle;
+    cIndex=(unsigned char)(iStyle>>24);
+    cWord=(unsigned char)(iStyle>>16);
+    cMeaning=(unsigned char)(iStyle>>8);
+    cMark=(unsigned char)iStyle;
 	g_print("flag: %c %c %c\n",cIndex,cWord,cMeaning);
 
     // mmap the file to memory
-    caddr_t pFileMem=(caddr_t)mmap( (caddr_t)0,iFileSize-sizeof(int)*2,
+    pFileMem=(caddr_t)mmap( (caddr_t)0,iFileSize-sizeof(int)*2,
                             PROT_READ,MAP_SHARED|MAP_NORESERVE,fd,0 );
     if(pFileMem==MAP_FAILED)
     {
@@ -133,9 +156,7 @@
     }
 
     // begin to read items.
-    caddr_t p=pFileMem;
-    caddr_t pMeaning, pMark;
-	gchar *utf8_str;
+    p=pFileMem;
 #ifndef DISABLE_CONVERT_LOCALE
 	gchar *locale_str;
 	gsize locale_write_size;
@@ -157,14 +178,7 @@
 	return;*/
 
 #endif
-	gsize write_size;
-	long tmp_long,wordcount=0;
-	int word_len, meaning_len,mark_len=0;
-	int iLength=0;
-		
-	GArray *array = g_array_sized_new(FALSE,FALSE, sizeof(struct _worditem),iCapacity);
-    struct _worditem worditem;
-	glong old_size;
+	array = g_array_sized_new(FALSE,FALSE, sizeof(struct _worditem),iCapacity);
 	
 	while(p<pFileMem+iFileSize-sizeof(int)*2 && iLength<iCapacity)
     {
@@ -303,14 +317,6 @@
 	//g_qsort_with_data(parray->pdata,parray->len,sizeof(gpointer),comparefunc,NULL);
 	g_array_sort(array,comparefunc);
 	
-	long offset_old=0;
-	
-	int i;
-	
-	gchar *previous_word = g_strdup(""); //there should have no word equal this.
-	glong previous_datasize = 0;
-	gchar *previous_data = g_strdup("");
-	struct _worditem *pworditem;
 	for (i=0;i<array->len;i++)
 	{
 		pworditem = &g_array_index(array, struct _worditem, i);
