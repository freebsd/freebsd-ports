--- ./stsoundlib/YmMusic.cpp.orig	2010-04-23 13:49:47.000000000 +0200
+++ ./stsoundlib/YmMusic.cpp	2010-04-23 13:50:07.000000000 +0200
@@ -167,12 +167,12 @@
 		return getAttrib()&A_TIMECONTROL;
 }
 
-void	CYmMusic::setLastError(char *pError)
+void	CYmMusic::setLastError(const char *pError)
 {
 		pLastError = pError;
 }
 
-char	*CYmMusic::getLastError(void)
+const char *CYmMusic::getLastError(void)
 {
 		return pLastError;
 }
@@ -364,11 +364,14 @@
 
 			if (ptr[12])
 			{
-				sampleFrq = (MFP_CLOCK / ptr[12]);
-				ymChip.drumStart(	2,							// Voice C
-									sampleAdress[sampleNum],
-									sampleLen[sampleNum],
-									sampleFrq);
+				if (sampleNum < MAX_DIGIDRUM)
+				{
+					sampleFrq = (MFP_CLOCK / ptr[12]);
+					ymChip.drumStart(	2,							// Voice C
+										sampleAdress[sampleNum],
+										sampleLen[sampleNum],
+										sampleFrq);
+				}
 			}
 		}
 	}
@@ -612,7 +615,6 @@
 	  	for (i=0;i<nbVoice;i++)
 		{
 			ymint n;
-			ymint freq = 
 			pVoice[i].sampleFreq = ((ymint)pLine->freqHigh<<8) | pLine->freqLow;
 			if (pVoice[i].sampleFreq)
 			{
@@ -677,7 +679,7 @@
 #ifdef _LINEAR_OVRS
 			ymint vb = va;
 			if (samplePos < (sampleEnd-(1<<YMTPREC)))
-				ymint vb = pVolumeTab[pSample[(samplePos>>YMTPREC)+1]];
+				vb = pVolumeTab[pSample[(samplePos>>YMTPREC)+1]];
 			ymint frac = samplePos & ((1<<YMTPREC)-1);
 			va += (((vb-va)*frac)>>YMTPREC);
 #endif
