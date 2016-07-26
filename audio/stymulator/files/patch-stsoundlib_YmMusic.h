--- stsoundlib/YmMusic.h.orig	2016-07-26 16:04:42 UTC
+++ stsoundlib/YmMusic.h
@@ -38,8 +38,6 @@
 #include "Ymload.h"
 #include "digidrum.h"
 
-#define	MAX_DIGIDRUM	128
-
 #define	YMTPREC		16
 #define	MAX_VOICE	8
 #define	PC_DAC_FREQ	44100
@@ -143,7 +141,7 @@ public:
 	int		getAttrib(void);
 	void	getMusicInfo(ymMusicInfo_t *pInfo);
 	void	setLoopMode(ymbool bLoop);
-	char	*getLastError(void);
+	const char	*getLastError(void);
 	int		 readYmRegister(ymint reg)		{ return ymChip.readRegister(reg); }
 
 //-------------------------------------------------------------
@@ -159,7 +157,7 @@ private:
 
 	void	setPlayerRate(int rate);
 	void	setAttrib(int _attrib);
-	void	setLastError(char *pError);
+	void	setLastError(const char *pError);
 	ymu8 *depackFile(void);
 	ymbool	deInterleave(void);
 	void	readYm6Effect(ymu8 *pReg,int code,int prediv,int count);
@@ -168,7 +166,7 @@ private:
 
 
 	CYm2149Ex	ymChip;
-	char	*pLastError;
+	const char	*pLastError;
 	ymFile_t	songType;
 	int		nbFrame;
 	int		loopFrame;
