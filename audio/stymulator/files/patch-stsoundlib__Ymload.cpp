--- stsoundlib/Ymload.cpp.orig	2010-03-27 16:37:51.000000000 +0100
+++ stsoundlib/Ymload.cpp	2010-03-27 16:40:46.000000000 +0100
@@ -129,7 +129,7 @@
 		{ // Compression LH5, header !=0 : Error.
 			free(pBigMalloc);
 			pBigMalloc = NULL;
-			setLastError("LHARC Header must be 0 !");
+			setLastError(((char *)"LHARC Header must be 0 !"));
 			return NULL;
 		}
 
@@ -137,7 +137,7 @@
 		pNew = (ymu8*)malloc(fileSize);
 		if (!pNew)
 		{
-			setLastError("MALLOC Failed !");
+			setLastError(((char *)"MALLOC Failed !"));
 			free(pBigMalloc);
 			pBigMalloc = NULL;
 			return NULL;
@@ -159,7 +159,7 @@
 
 		if (!bRet)
 		{	// depacking error
-			setLastError("LH5 Depacking Error !");
+			setLastError(((char *)"LH5 Depacking Error !"));
 			free(pNew);
 			pNew = NULL;
 		}
@@ -197,7 +197,7 @@
 			tmpBuff = (ymu8*)malloc(nbFrame*streamInc);
 			if (!tmpBuff)
 			{
-				setLastError("Malloc error in deInterleave()\n");
+				setLastError(((char *)"Malloc error in deInterleave()\n"));
 				return YMFALSE;
 			}
 
@@ -249,11 +249,11 @@
 				streamInc = 14;
 				nbDrum = 0;
 				setAttrib(A_STREAMINTERLEAVED|A_TIMECONTROL);
-				pSongName = mstrdup("Unknown");
-				pSongAuthor = mstrdup("Unknown");
-				pSongComment = mstrdup("Converted by Leonard.");
-				pSongType = mstrdup("YM 2");
-				pSongPlayer = mstrdup("YM-Chip driver.");
+				pSongName = mstrdup(((char *)"Unknown"));
+				pSongAuthor = mstrdup(((char *)"Unknown"));
+				pSongComment = mstrdup(((char *)"Converted by Leonard."));
+				pSongType = mstrdup(((char *)"YM 2"));
+				pSongPlayer = mstrdup(((char *)"YM-Chip driver."));
 				break;
 
 			case 'YM3!':		// Standart YM-Atari format.
@@ -266,11 +266,11 @@
 				streamInc = 14;
 				nbDrum = 0;
 				setAttrib(A_STREAMINTERLEAVED|A_TIMECONTROL);
-				pSongName = mstrdup("Unknown");
-				pSongAuthor = mstrdup("Unknown");
-				pSongComment = mstrdup("");
-				pSongType = mstrdup("YM 3");
-				pSongPlayer = mstrdup("YM-Chip driver.");
+				pSongName = mstrdup(((char *)"Unknown"));
+				pSongAuthor = mstrdup(((char *)"Unknown"));
+				pSongComment = mstrdup(((char *)""));
+				pSongType = mstrdup(((char *)"YM 3"));
+				pSongPlayer = mstrdup(((char *)"YM-Chip driver."));
 				break;
 
 			case 'YM3b':		// Standart YM-Atari format + Loop info.
@@ -284,15 +284,15 @@
 				streamInc = 14;
 				nbDrum = 0;
 				setAttrib(A_STREAMINTERLEAVED|A_TIMECONTROL);
-				pSongName = mstrdup("Unknown");
-				pSongAuthor = mstrdup("Unknown");
-				pSongComment = mstrdup("");
-				pSongType = mstrdup("YM 3b (loop)");
-				pSongPlayer = mstrdup("YM-Chip driver.");
+				pSongName = mstrdup(((char *)"Unknown"));
+				pSongAuthor = mstrdup(((char *)"Unknown"));
+				pSongComment = mstrdup(((char *)""));
+				pSongType = mstrdup(((char *)"YM 3b (loop)"));
+				pSongPlayer = mstrdup(((char *)"YM-Chip driver."));
 				break;
 
 			case 'YM4!':		// Extended ATARI format.
-				setLastError("No more YM4! support. Use YM5! format.");
+				setLastError(((char *)"No more YM4! support. Use YM5! format."));
 				return YMFALSE;
 				break;
 
@@ -300,7 +300,7 @@
 			case 'YM6!':		// Extended YM2149 format, all machines.
 				if (strncmp((const char*)(pBigMalloc+4),"LeOnArD!",8))
 				{
-					setLastError("Not a valid YM format !");
+					setLastError(((char *)"Not a valid YM format !"));
 					return YMFALSE;
 				}
 				ptr = pBigMalloc+12;
@@ -347,23 +347,23 @@
 				if (id=='YM6!')
 				{
 					songType = YM_V6;
-					pSongType = mstrdup("YM 6");
+					pSongType = mstrdup(((char *)"YM 6"));
 				}
 				else
 				{
-					pSongType = mstrdup("YM 5");
+					pSongType = mstrdup(((char *)"YM 5"));
 				}
 				pDataStream = ptr;
 				streamInc = 16;
 				setAttrib(A_STREAMINTERLEAVED|A_TIMECONTROL);
-				pSongPlayer = mstrdup("YM-Chip driver.");
+				pSongPlayer = mstrdup(((char *)"YM-Chip driver."));
 				break;
 
 			case 'MIX1':		// ATARI Remix digit format.
 
 				if (strncmp((const char*)(pBigMalloc+4),"LeOnArD!",8))
 				{
-					setLastError("Not a valid YM format !");
+					setLastError(((char *)"Not a valid YM format !"));
 					return YMFALSE;
 				}
 				ptr = pBigMalloc+12;
@@ -395,8 +395,8 @@
 				}
 
 				mixPos = -1;		// numero du block info.
-				pSongType = mstrdup("MIX1");
-				pSongPlayer = mstrdup("Digi-Mix driver.");
+				pSongType = mstrdup(((char *)"MIX1"));
+				pSongPlayer = mstrdup(((char *)"Digi-Mix driver."));
 
 				break;
 
@@ -420,7 +420,7 @@
 */
 				if (strncmp((const char*)(pBigMalloc+4),"LeOnArD!",8))
 				{
-					setLastError("Not a valid YM format !");
+					setLastError(((char *)"Not a valid YM format !"));
 					return YMFALSE;
 				}
 				ptr = pBigMalloc+12;
@@ -469,11 +469,11 @@
 				{
 					ymTrackerFreqShift = (attrib>>28)&15;
 					attrib &= 0x0fffffff;
-					pSongType = mstrdup("YM-T2");
+					pSongType = mstrdup(((char *)"YM-T2"));
 				}
 				else
 				{
-					pSongType = mstrdup("YM-T1");
+					pSongType = mstrdup(((char *)"YM-T1"));
 				}
 
 
@@ -483,11 +483,11 @@
 				ymTrackerInit(100);		// 80% de volume maxi.
 				streamInc = 16;
 				setTimeControl(YMTRUE);
-				pSongPlayer = mstrdup("Universal Tracker");
+				pSongPlayer = mstrdup(((char *)"Universal Tracker"));
 				break;
 
 			default:
-				setLastError("Unknow YM format !");
+				setLastError(((char *)"Unknow YM format !"));
 				return YMFALSE;
 				break;
 		}
@@ -503,7 +503,7 @@
  
 ymbool	CYmMusic::checkCompilerTypes()
 {
-	setLastError("Basic types size are not correct (check ymTypes.h)");
+	setLastError(((char *)"Basic types size are not correct (check ymTypes.h)"));
 
 	if (1 != sizeof(ymu8)) return YMFALSE;
 	if (1 != sizeof(yms8)) return YMFALSE;
@@ -522,7 +522,7 @@
 
 	if (sizeof(ymint) < 4) return YMFALSE;		// ymint should be at least 32bits
 
-	setLastError("");
+	setLastError(((char *)""));
 	return YMTRUE;
 }
 
@@ -541,7 +541,7 @@
 		in = fopen(fileName,"rb");
 		if (!in)
 		{
-			setLastError("File not Found");
+			setLastError(((char *)"File not Found"));
 			return YMFALSE;
 		}
 
@@ -552,7 +552,7 @@
 		pBigMalloc = (unsigned char*)malloc(fileSize);
 		if (!pBigMalloc)
 		{
-			setLastError("MALLOC Error");
+			setLastError(((char *)"MALLOC Error"));
 			fclose(in);
 			return YMFALSE;
 		}
@@ -563,7 +563,7 @@
 		if (fread(pBigMalloc,1,fileSize,in)!=(size_t)fileSize)
 		{
 			free(pBigMalloc);
-			setLastError("File is corrupted.");
+			setLastError(((char *)"File is corrupted."));
 			fclose(in);
 			return YMFALSE;
 		}
@@ -611,7 +611,7 @@
 		pBigMalloc = (unsigned char*)malloc(fileSize);
 		if (!pBigMalloc)
 		{
-			setLastError("MALLOC Error");
+			setLastError(((char *)"MALLOC Error"));
 			return YMFALSE;
 		}
 
