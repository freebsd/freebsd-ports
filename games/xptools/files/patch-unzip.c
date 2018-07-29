--- src/Utils/unzip.c.orig	2018-07-04 22:41:04 UTC
+++ src/Utils/unzip.c
@@ -509,11 +509,18 @@ local int unzlocal_GetCurrentFileInfoInt
 
 	/* we check the magic */
 	if (err==UNZ_OK)
-		if (unzlocal_getLong(s->file,&uMagic) != UNZ_OK)
+	{
+		if (unzlocal_getLong(s->file,&uMagic) != UNZ_OK) {
 			err=UNZ_ERRNO;
-		else if (uMagic!=0x02014b50)
-			err=UNZ_BADZIPFILE;
-
+		}
+		else
+		{ 
+			if (uMagic!=0x02014b50)
+		{
+				err=UNZ_BADZIPFILE;
+			}
+		}
+	}
 	if (unzlocal_getShort(s->file,&file_info.version) != UNZ_OK)
 		err=UNZ_ERRNO;
 
@@ -584,24 +591,34 @@ local int unzlocal_GetCurrentFileInfoInt
 	{
 		uLong uSizeRead ;
 		if (file_info.size_file_extra<extraFieldBufferSize)
+		{
 			uSizeRead = file_info.size_file_extra;
+		}
 		else
+		{
 			uSizeRead = extraFieldBufferSize;
-
-		if (lSeek!=0)
-			if (fseek(s->file,lSeek,SEEK_CUR)==0)
+		}
+		if (lSeek!=0) 
+		{
+			if (fseek(s->file,lSeek,SEEK_CUR)==0) 
+			{
 				lSeek=0;
+			}
 			else
+			{
 				err=UNZ_ERRNO;
+			}
+		}
 		if ((file_info.size_file_extra>0) && (extraFieldBufferSize>0))
 			if (fread(extraField,(uInt)uSizeRead,1,s->file)!=1)
 				err=UNZ_ERRNO;
 		lSeek += file_info.size_file_extra - uSizeRead;
 	}
 	else
+	{
 		lSeek+=file_info.size_file_extra;
 
-
+	}
 	if ((err==UNZ_OK) && (szComment!=NULL))
 	{
 		uLong uSizeRead ;
@@ -611,17 +628,30 @@ local int unzlocal_GetCurrentFileInfoInt
 			uSizeRead = file_info.size_file_comment;
 		}
 		else
+		{
 			uSizeRead = commentBufferSize;
+		}
 
-		if (lSeek!=0)
-			if (fseek(s->file,lSeek,SEEK_CUR)==0)
+		if (lSeek!=0) 
+		{
+			if (fseek(s->file,lSeek,SEEK_CUR)==0) 
+			{
 				lSeek=0;
+			}
 			else
+			{
 				err=UNZ_ERRNO;
+			}
+		}
 		if ((file_info.size_file_comment>0) && (commentBufferSize>0))
-			if (fread(szComment,(uInt)uSizeRead,1,s->file)!=1)
+		{
+			if (fread(szComment,(uInt)uSizeRead,1,s->file)!=1) 
+			{
 				err=UNZ_ERRNO;
+			}
+		}
 		lSeek+=file_info.size_file_comment - uSizeRead;
+		
 	}
 	else
 		lSeek+=file_info.size_file_comment;
@@ -791,10 +821,16 @@ local int unzlocal_CheckCurrentFileCoher
 
 
 	if (err==UNZ_OK)
-		if (unzlocal_getLong(s->file,&uMagic) != UNZ_OK)
+	{
+		if (unzlocal_getLong(s->file,&uMagic) != UNZ_OK){
 			err=UNZ_ERRNO;
-		else if (uMagic!=0x04034b50)
+		}
+		else 
+		{
+			if (uMagic!=0x04034b50)
 			err=UNZ_BADZIPFILE;
+		}
+	}
 
 	if (unzlocal_getShort(s->file,&uData) != UNZ_OK)
 		err=UNZ_ERRNO;
@@ -977,7 +1013,7 @@ extern int ZEXPORT unzReadCurrentFile  (
 		return UNZ_PARAMERROR;
 
 
-	if ((pfile_in_zip_read_info->read_buffer == NULL))
+	if (pfile_in_zip_read_info->read_buffer == NULL)
 		return UNZ_END_OF_LIST_OF_FILE;
 	if (len==0)
 		return 0;
