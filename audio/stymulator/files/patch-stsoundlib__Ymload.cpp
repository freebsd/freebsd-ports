--- ./stsoundlib/Ymload.cpp.orig	2010-04-23 13:49:47.000000000 +0200
+++ ./stsoundlib/Ymload.cpp	2010-04-23 13:50:07.000000000 +0200
@@ -51,61 +51,98 @@
 		}
 }
 
-char	*mstrdup(char *in)
+void	myFree(void **pPtr)
+{
+		if (*pPtr) free(*pPtr);
+		*pPtr = NULL;
+}
+
+char	*mstrdup(const char *in)
 {
 		char *out = (char*)malloc(strlen(in)+1);
 		if (out) strcpy(out,in);
 		return out;
 }
 
-ymu32      readMotorolaDword(ymu8 **ptr)
+ymu32      readMotorolaDword(ymu8 **ptr, ymint *ptr_size)
 {
-ymu32 n;
+ymu32 n = 0;
 ymu8 *p = *ptr;
-
-        n = (p[0]<<24)|(p[1]<<16)|(p[2]<<8)|p[3];
-        p+=4;
-        *ptr = p;
+	if (*ptr_size>=4)
+	{	
+	        n = (p[0]<<24)|(p[1]<<16)|(p[2]<<8)|p[3];
+        	p+=4;
+	        *ptr = p;
+	}
+	(*ptr_size)+=4;
         return n;
 }
 
-ymu16      readMotorolaWord(ymu8 **ptr)
+ymu16      readMotorolaWord(ymu8 **ptr, ymint *ptr_size)
 {
-ymu16 n;
+ymu16 n = 0;
 ymu8 *p = *ptr;
-
-        n = (p[0]<<8)|p[1];
-        p+=2;
-        *ptr = p;
+	if (*ptr_size>=2)
+	{
+	        n = (p[0]<<8)|p[1];
+        	p+=2;
+	        *ptr = p;
+	}
+	(*ptr_size)+=2;
         return n;
 }
 
-ymchar    *readNtString(ymchar **ptr)
+ymchar    *readNtString(ymchar **ptr, ymint *ptr_size)
 {
 ymchar *p;
+ymint len = 0;
 
-		p = mstrdup(*ptr);
-		(*ptr) += strlen(*ptr)+1;
+	if (*ptr_size<=0)
+	{
+		(*ptr_size)-=1;
+		return mstrdup("");
+	}
+	p=*ptr;
+	while(!*p)
+	{
+		p++;
+		ptr_size--;
+		len++;
+		if (*ptr_size==0)
+		{
+			(*ptr_size)-=1;
+			return mstrdup("");
+		}
+	}
+
+	p = mstrdup(*ptr);
+	(*ptr) += len+1;
         return p;
 }
 
-yms32	ReadLittleEndian32(ymu8 *pLittle)
+yms32	ReadLittleEndian32(ymu8 *pLittle, ymint ptr_size)
 {
-	yms32 v = ( (pLittle[0]<<0) |
+	yms32 v = 0;
+	if (ptr_size>=4)
+	{	
+		v = ( (pLittle[0]<<0) |
 				(pLittle[1]<<8) |
 				(pLittle[2]<<16) |
 				(pLittle[3]<<24));
-
+	}
 	return v;
 }
 
-yms32	ReadBigEndian32(ymu8 *pBig)
+yms32	ReadBigEndian32(ymu8 *pBig, ymint ptr_size)
 {
-	yms32 v = ( (pBig[0]<<24) |
+	yms32 v = 0;
+	if (ptr_size>=4)
+	{
+		v = ( (pBig[0]<<24) |
 				(pBig[1]<<16) |
 				(pBig[2]<<8) |
-				(pBig[3]<<0));
-
+		 		(pBig[3]<<0));
+	}
 	return v;
 }
 
@@ -114,6 +151,13 @@
  lzhHeader_t *pHeader;
  ymu8	*pNew;
  ymu8	*pSrc;
+ ymint	ptr_left = fileSize;
+ ymint  dummy;
+
+		if (ptr_left < (ymint)sizeof(lzhHeader_t))
+		{
+			return pBigMalloc;
+		}
 
 		pHeader = (lzhHeader_t*)pBigMalloc;
 
@@ -123,8 +167,6 @@
 			return pBigMalloc;
 		}
 
-		fileSize = (ymu32)-1;
-
 		if (pHeader->level != 0)					// NOTE: Endianness works because value is 0
 		{ // Compression LH5, header !=0 : Error.
 			free(pBigMalloc);
@@ -133,7 +175,8 @@
 			return NULL;
 		}
 
-		fileSize = ReadLittleEndian32((ymu8*)&pHeader->original);
+		dummy = 4;
+		fileSize = ReadLittleEndian32((ymu8*)&pHeader->original, dummy);
 		pNew = (ymu8*)malloc(fileSize);
 		if (!pNew)
 		{
@@ -144,10 +187,20 @@
 		}
 
 		pSrc = pBigMalloc+sizeof(lzhHeader_t)+pHeader->name_lenght;			// NOTE: Endianness works because name_lenght is a byte
+		ptr_left -= sizeof(lzhHeader_t)+pHeader->name_lenght;
 
 		pSrc += 2;		// skip CRC16
+		ptr_left -= 2;
 
-		const int		packedSize = ReadLittleEndian32((ymu8*)&pHeader->packed);
+		dummy = 4;
+		const int		packedSize = ReadLittleEndian32((ymu8*)&pHeader->packed, dummy);
+
+		if (packedSize > ptr_left)
+		{
+			setLastError("File too small");
+			free(pNew);
+			return pBigMalloc;
+		}
 
 		// alloc space for depacker and depack data
 		CLzhDepacker *pDepacker = new CLzhDepacker;	
@@ -229,19 +282,29 @@
  {
  ymu8 *pUD;
  ymu8	*ptr;
+ ymint ptr_size = fileSize;
  ymint skip;
  ymint i;
  ymu32 sampleSize;
  yms32 tmp;
  ymu32 id;
- 
 
-		id = ReadBigEndian32((unsigned char*)pBigMalloc);
+		if (ptr_size < 4)
+		{ 
+			setLastError("File too small");
+			return YMFALSE;
+		}
+		id = ReadBigEndian32((unsigned char*)pBigMalloc, ptr_size);
 		switch (id)
 		{
-			case 'YM2!':		// MADMAX specific.
+			case 0x594d3221 /*'YM2!'*/:		// MADMAX specific.
 				songType = YM_V2;
 				nbFrame = (fileSize-4)/14;
+				if (nbFrame == 0)
+				{ 
+					setLastError("No frames in file");
+					return YMFALSE;
+				}
 				loopFrame = 0;
 				ymChip.setClock(ATARI_CLOCK);
 				setPlayerRate(50);
@@ -256,9 +319,14 @@
 				pSongPlayer = mstrdup("YM-Chip driver.");
 				break;
 
-			case 'YM3!':		// Standart YM-Atari format.
+			case 0x594d3321 /*'YM3!'*/:		// Standart YM-Atari format.
 				songType = YM_V3;
 				nbFrame = (fileSize-4)/14;
+				if (nbFrame == 0)
+				{ 
+					setLastError("No frames in file");
+					return YMFALSE;
+				}
 				loopFrame = 0;
 				ymChip.setClock(ATARI_CLOCK);
 				setPlayerRate(50);
@@ -273,11 +341,24 @@
 				pSongPlayer = mstrdup("YM-Chip driver.");
 				break;
 
-			case 'YM3b':		// Standart YM-Atari format + Loop info.
+			case 0x594d3362 /*'YM3b'*/:		// Standart YM-Atari format + Loop info.
+				if (ptr_size < 4)
+				{ 
+					setLastError("File too small");
+					return YMFALSE;
+				}
 				pUD = (ymu8*)(pBigMalloc+fileSize-4);
 				songType = YM_V3;
-				nbFrame = (fileSize-4)/14;
-				loopFrame = ReadLittleEndian32(pUD);
+				nbFrame = (fileSize-8)/14;
+				if (nbFrame == 0)
+				{ 
+					setLastError("No frames in file");
+					return YMFALSE;
+				}
+				{
+					ymint dummy = 4;
+					loopFrame = ReadLittleEndian32(pUD, dummy);
+				}
 				ymChip.setClock(ATARI_CLOCK);
 				setPlayerRate(50);
 				pDataStream = pBigMalloc+4;
@@ -291,35 +372,62 @@
 				pSongPlayer = mstrdup("YM-Chip driver.");
 				break;
 
-			case 'YM4!':		// Extended ATARI format.
+			case 0x594d3421 /*'YM4!'*/:		// Extended ATARI format.
 				setLastError("No more YM4! support. Use YM5! format.");
 				return YMFALSE;
 				break;
 
-			case 'YM5!':		// Extended YM2149 format, all machines.
-			case 'YM6!':		// Extended YM2149 format, all machines.
+			case 0x594d3521 /*'YM5!'*/:		// Extended YM2149 format, all machines.
+			case 0x594d3621 /*'YM6!'*/:		// Extended YM2149 format, all machines.
+				if (ptr_size < 12)
+				{ 
+					setLastError("File too small");
+					return YMFALSE;
+				}
 				if (strncmp((const char*)(pBigMalloc+4),"LeOnArD!",8))
 				{
 					setLastError("Not a valid YM format !");
 					return YMFALSE;
 				}
 				ptr = pBigMalloc+12;
-				nbFrame = readMotorolaDword(&ptr);
-				setAttrib(readMotorolaDword(&ptr));
-				nbDrum = readMotorolaWord(&ptr);
-				ymChip.setClock(readMotorolaDword(&ptr));
-				setPlayerRate(readMotorolaWord(&ptr));
-				loopFrame = readMotorolaDword(&ptr);
-				skip = readMotorolaWord(&ptr);
+				ptr_size -= 12;
+				nbFrame = readMotorolaDword(&ptr, &ptr_size);
+				setAttrib(readMotorolaDword(&ptr, &ptr_size));
+				nbDrum = readMotorolaWord(&ptr, &ptr_size);
+				ymChip.setClock(readMotorolaDword(&ptr, &ptr_size));
+				setPlayerRate(readMotorolaWord(&ptr, &ptr_size));
+				loopFrame = readMotorolaDword(&ptr, &ptr_size);
+				skip = readMotorolaWord(&ptr, &ptr_size);
 				ptr += skip;
+				ptr_size -= skip;
+				if (ptr_size <= 0)
+				{
+					setLastError("File too small");
+					return YMFALSE;
+				}
 				if (nbDrum>0)
 				{
-					pDrumTab=(digiDrum_t*)malloc(nbDrum*sizeof(digiDrum_t));
+					pDrumTab=(digiDrum_t*)calloc(nbDrum, sizeof(digiDrum_t));
 					for (i=0;i<nbDrum;i++)
 					{
-						pDrumTab[i].size = readMotorolaDword(&ptr);
+						pDrumTab[i].size = readMotorolaDword(&ptr, &ptr_size);
+						if (ptr_size <= 0)
+						{
+							setLastError("File too small");
+							goto error_out;
+						}
 						if (pDrumTab[i].size)
 						{
+							if (pDrumTab[i].size >= 0x80000000)
+							{
+								setLastError("To big drumtab");
+								goto error_out;
+							}
+							if (ptr_size<(ymint)pDrumTab[i].size)
+							{
+								setLastError("File too small");
+								goto error_out;
+							}
 							pDrumTab[i].pData = (ymu8*)malloc(pDrumTab[i].size);
 							memcpy(pDrumTab[i].pData,ptr,pDrumTab[i].size);
 							if (attrib&A_DRUM4BITS)
@@ -328,23 +436,26 @@
 								ymu8 *pw = pDrumTab[i].pData;
 								for (j=0;j<pDrumTab[i].size;j++)
 								{
-									*pw++ = ymVolumeTable[(*pw)&15]>>7;
+									*pw = ymVolumeTable[(*pw)&15]>>7;
+									pw++;
 								}
 							}
 							ptr += pDrumTab[i].size;
-						}
-						else
-						{
-							pDrumTab[i].pData = NULL;
+							ptr_size -= pDrumTab[i].size;
 						}
 					}
 					attrib &= (~A_DRUM4BITS);
 				}
-				pSongName = readNtString((char**)&ptr);
-				pSongAuthor = readNtString((char**)&ptr);
-				pSongComment = readNtString((char**)&ptr);
+				pSongName = readNtString((char**)&ptr, &ptr_size);
+				pSongAuthor = readNtString((char**)&ptr, &ptr_size);
+				pSongComment = readNtString((char**)&ptr, &ptr_size);
+				if (ptr_size <= 0)
+				{
+					setLastError("File too small");
+					goto error_out;
+				}
 				songType = YM_V5;
-				if (id=='YM6!')
+				if (id==0x594d3621/*'YM6!'*/)
 				{
 					songType = YM_V6;
 					pSongType = mstrdup("YM 6");
@@ -353,13 +464,28 @@
 				{
 					pSongType = mstrdup("YM 5");
 				}
+				if ((nbFrame >= 0x08000000) || (nbFrame < 0))
+				{
+					setLastError("Too many frames");
+					goto error_out;
+				}
+				if (ptr_size < (ymint)(nbFrame * 16))
+				{
+					setLastError("File too small");
+					goto error_out;
+				}
 				pDataStream = ptr;
 				streamInc = 16;
 				setAttrib(A_STREAMINTERLEAVED|A_TIMECONTROL);
 				pSongPlayer = mstrdup("YM-Chip driver.");
 				break;
 
-			case 'MIX1':		// ATARI Remix digit format.
+			case 0x4d495831 /*'MIX1'*/:		// ATARI Remix digit format.
+				if (ptr_size < 12)
+				{ 
+					setLastError("File too small");
+					return YMFALSE;
+				}
 
 				if (strncmp((const char*)(pBigMalloc+4),"LeOnArD!",8))
 				{
@@ -367,23 +493,50 @@
 					return YMFALSE;
 				}
 				ptr = pBigMalloc+12;
+				ptr_size -= 12;
 				songType = YM_MIX1;
-				tmp = readMotorolaDword(&ptr);
+				tmp = readMotorolaDword(&ptr, &ptr_size);
 				setAttrib(0);
 				if (tmp&1) setAttrib(A_DRUMSIGNED);
-				sampleSize = readMotorolaDword(&ptr);
-				nbMixBlock = readMotorolaDword(&ptr);
+				sampleSize = readMotorolaDword(&ptr, &ptr_size);
+				nbMixBlock = readMotorolaDword(&ptr, &ptr_size);
+				if (ptr_size <= 0)
+				{
+					setLastError("File too small");
+					goto error_out;
+				}
+				if (sampleSize <= 0)
+				{
+					setLastError("Invalid sampleSize");
+					goto error_out;
+				}
+				if (nbMixBlock <= 0)
+				{
+					setLastError("Invalid number of mixblocks");
+					goto error_out;
+				}
 				pMixBlock = (mixBlock_t*)malloc(nbMixBlock*sizeof(mixBlock_t));
 				for (i=0;i<nbMixBlock;i++)
 				{	// Lecture des block-infos.
-					pMixBlock[i].sampleStart = readMotorolaDword(&ptr);
-					pMixBlock[i].sampleLength = readMotorolaDword(&ptr);
-					pMixBlock[i].nbRepeat = readMotorolaWord(&ptr);
-					pMixBlock[i].replayFreq = readMotorolaWord(&ptr);
+					pMixBlock[i].sampleStart = readMotorolaDword(&ptr, &ptr_size);
+					pMixBlock[i].sampleLength = readMotorolaDword(&ptr, &ptr_size);
+					pMixBlock[i].nbRepeat = readMotorolaWord(&ptr, &ptr_size);
+					pMixBlock[i].replayFreq = readMotorolaWord(&ptr, &ptr_size);
+				}
+				pSongName = readNtString((char**)&ptr, &ptr_size);
+				pSongAuthor = readNtString((char**)&ptr, &ptr_size);
+				pSongComment = readNtString((char**)&ptr, &ptr_size);
+
+				if (sampleSize>=0x80000000)
+				{
+					setLastError("Invalid sampleSize");
+					goto error_out;
+				}
+				if (ptr_size < (ymint)sampleSize)
+				{
+					setLastError("File too small");
+					goto error_out;
 				}
-				pSongName = readNtString((char**)&ptr);
-				pSongAuthor = readNtString((char**)&ptr);
-				pSongComment = readNtString((char**)&ptr);
 
 				pBigSampleBuffer = (unsigned char*)malloc(sampleSize);
 				memcpy(pBigSampleBuffer,ptr,sampleSize);
@@ -400,8 +553,8 @@
 
 				break;
 
-			case 'YMT1':		// YM-Tracker
-			case 'YMT2':		// YM-Tracker
+			case 0x594d5431 /*'YMT1'*/:		// YM-Tracker
+			case 0x594d5432 /*'YMT2'*/:		// YM-Tracker
 /*;
 ; Format du YM-Tracker-1
 ;
@@ -418,33 +571,55 @@
 ; NT Music comment
 ; nb digi *
 */
+				if (ptr_size < 12)
+				{ 
+					setLastError("File too small");
+					return YMFALSE;
+				}
+
 				if (strncmp((const char*)(pBigMalloc+4),"LeOnArD!",8))
 				{
 					setLastError("Not a valid YM format !");
 					return YMFALSE;
 				}
 				ptr = pBigMalloc+12;
+				ptr_size -= 12;
 				songType = YM_TRACKER1;
-				nbVoice = readMotorolaWord(&ptr);
-				setPlayerRate(readMotorolaWord(&ptr));
-				nbFrame= readMotorolaDword(&ptr);
-				loopFrame = readMotorolaDword(&ptr);
-				nbDrum = readMotorolaWord(&ptr);
-				attrib = readMotorolaDword(&ptr);
-				pSongName = readNtString((char**)&ptr);
-				pSongAuthor = readNtString((char**)&ptr);
-				pSongComment = readNtString((char**)&ptr);
+				nbVoice = readMotorolaWord(&ptr, &ptr_size);
+				setPlayerRate(readMotorolaWord(&ptr, &ptr_size));
+				nbFrame= readMotorolaDword(&ptr, &ptr_size);
+				loopFrame = readMotorolaDword(&ptr, &ptr_size);
+				nbDrum = readMotorolaWord(&ptr, &ptr_size);
+				attrib = readMotorolaDword(&ptr, &ptr_size);
+				pSongName = readNtString((char**)&ptr, &ptr_size);
+				pSongAuthor = readNtString((char**)&ptr, &ptr_size);
+				pSongComment = readNtString((char**)&ptr, &ptr_size);
+				if (ptr_size < 0)
+				{ 
+					setLastError("File too small");
+					return YMFALSE;
+				}
 				if (nbDrum>0)
 				{
-					pDrumTab=(digiDrum_t*)malloc(nbDrum*sizeof(digiDrum_t));
+					pDrumTab=(digiDrum_t*)calloc(nbDrum, sizeof(digiDrum_t));
 					for (i=0;i<(ymint)nbDrum;i++)
 					{
-						pDrumTab[i].size = readMotorolaWord(&ptr);
+						pDrumTab[i].size = readMotorolaWord(&ptr, &ptr_size);
+						if (ptr_size < 0)
+						{
+							setLastError("File too small");
+							goto error_out;
+						}
 						pDrumTab[i].repLen = pDrumTab[i].size;
-						if ('YMT2' == id)
+						if (0x594d5432/*'YMT2'*/ == id)
 						{
-							pDrumTab[i].repLen = readMotorolaWord(&ptr);	// repLen
-							readMotorolaWord(&ptr);		// flag
+							pDrumTab[i].repLen = readMotorolaWord(&ptr, &ptr_size);	// repLen
+							readMotorolaWord(&ptr, &ptr_size);		// flag
+							if (ptr_size < 0)
+							{
+								setLastError("File too small");
+								goto error_out;
+							}
 						}
 						if (pDrumTab[i].repLen>pDrumTab[i].size)
 						{
@@ -453,19 +628,27 @@
 
 						if (pDrumTab[i].size)
 						{
+							if (pDrumTab[i].size >= 0x80000000)
+							{
+								setLastError("Drumtab to big");
+								goto error_out;
+							}
+							if (ptr_size<(ymint)pDrumTab[i].size)
+							{
+								setLastError("File too small");
+								goto error_out;
+							}
+
 							pDrumTab[i].pData = (ymu8*)malloc(pDrumTab[i].size);
 							memcpy(pDrumTab[i].pData,ptr,pDrumTab[i].size);
 							ptr += pDrumTab[i].size;
-						}
-						else
-						{
-							pDrumTab[i].pData = NULL;
+							ptr_size -= pDrumTab[i].size;
 						}
 					}
 				}
 
 				ymTrackerFreqShift = 0;
-				if ('YMT2' == id)
+				if (0x594d5432/*'YMT2'*/ == id)
 				{
 					ymTrackerFreqShift = (attrib>>28)&15;
 					attrib &= 0x0fffffff;
@@ -476,18 +659,33 @@
 					pSongType = mstrdup("YM-T1");
 				}
 
+				if ((nbVoice > MAX_VOICE) || (nbVoice < 0))
+				{
+					setLastError("Too many voices");
+					goto error_out;
+				}
+				if ((nbFrame >= (ymint)(0x80000000 / (MAX_VOICE * (sizeof(ymTrackerLine_t))))) || (nbFrame < 0)) /* ymTrackerLine_t has a 2^N size */
+				{
+					setLastError("Too many frames");
+					goto error_out;
+				}
+				if (ptr_size < (ymint)(sizeof(ymTrackerLine_t) * nbVoice * nbFrame))
+				{
+					setLastError("File too small");
+					goto error_out;
+				}
 
 				pDataStream = ptr;
 				ymChip.setClock(ATARI_CLOCK);
 
 				ymTrackerInit(100);		// 80% de volume maxi.
-				streamInc = 16;
+				streamInc = 16; /* not needed, since this is only used for YMx formats */
 				setTimeControl(YMTRUE);
 				pSongPlayer = mstrdup("Universal Tracker");
 				break;
 
 			default:
-				setLastError("Unknow YM format !");
+				setLastError("Unknown YM format !");
 				return YMFALSE;
 				break;
 		}
@@ -498,6 +696,25 @@
 		}
 
 		return YMTRUE;
+error_out:
+	for (i=0;i<nbDrum;i++)
+	{
+		if (pDrumTab[i].pData)
+			myFree((void **)&pDrumTab[i].pData);
+	}
+	if (nbDrum>0)
+	{
+		myFree((void **)&pDrumTab);
+		nbDrum=0;
+	}
+	myFree((void **)&pSongName);
+	myFree((void **)&pSongAuthor);
+	myFree((void **)&pSongComment);
+	myFree((void **)&pSongType); /* <- never needed, but we keep it for purity */
+	myFree((void **)&pSongPlayer); /* <- never needed, but we keep it for purity */
+	myFree((void **)&pMixBlock);
+	myFree((void **)&pBigSampleBuffer); /* <- never needed, but we keep it for purity */
+	return YMFALSE;
  }
 
  
@@ -645,12 +862,6 @@
 		return YMTRUE;
  }
 
-void	myFree(void **pPtr)
-{
-		if (*pPtr) free(*pPtr);
-		*pPtr = NULL;
-}
-
 void	CYmMusic::unLoad(void)
 {
 
