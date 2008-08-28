--- include/IL/il.h.orig	Mon Jul 12 18:55:08 2004
+++ include/IL/il.h	Mon Sep 17 19:36:05 2007
@@ -125,7 +125,6 @@
 typedef float			ILclampf;
 typedef double			ILdouble;
 typedef double			ILclampd;
-typedef void			ILvoid;
 
 #ifdef _UNICODE
 	#ifndef _WIN32_WCE
@@ -460,7 +459,7 @@
 
 // Callback functions for file reading
 typedef void* ILHANDLE;
-typedef ILvoid		(ILAPIENTRY *fCloseRProc)(ILHANDLE);
+typedef void		(ILAPIENTRY *fCloseRProc)(ILHANDLE);
 typedef ILboolean	(ILAPIENTRY *fEofProc)   (ILHANDLE);
 typedef ILint		(ILAPIENTRY *fGetcProc)  (ILHANDLE);
 typedef ILHANDLE	(ILAPIENTRY *fOpenRProc) (const ILstring);
@@ -469,7 +468,7 @@
 typedef ILint		(ILAPIENTRY *fTellRProc) (ILHANDLE);
 
 // Callback functions for file writing
-typedef ILvoid		(ILAPIENTRY *fCloseWProc)(ILHANDLE);
+typedef void		(ILAPIENTRY *fCloseWProc)(ILHANDLE);
 typedef ILHANDLE	(ILAPIENTRY *fOpenWProc) (const ILstring);
 typedef ILint		(ILAPIENTRY *fPutcProc)  (ILubyte, ILHANDLE);
 typedef ILint		(ILAPIENTRY *fSeekWProc) (ILHANDLE, ILint, ILint);
@@ -477,8 +476,8 @@
 typedef ILint		(ILAPIENTRY *fWriteProc) (const void*, ILuint, ILuint, ILHANDLE);
 
 // Callback functions for allocation and deallocation
-typedef ILvoid*		(ILAPIENTRY *mAlloc)(ILuint);
-typedef ILvoid		(ILAPIENTRY *mFree) (ILvoid*);
+typedef void*		(ILAPIENTRY *mAlloc)(ILuint);
+typedef void		(ILAPIENTRY *mFree) (void*);
 
 // Registered format procedures
 typedef ILenum		(ILAPIENTRY *IL_LOADPROC)(const ILstring);
@@ -491,91 +490,91 @@
 ILAPI ILboolean		ILAPIENTRY ilActiveMipmap(ILuint Number);
 ILAPI ILboolean		ILAPIENTRY ilApplyPal(const ILstring FileName);
 ILAPI ILboolean		ILAPIENTRY ilApplyProfile(const ILstring InProfile, const ILstring OutProfile);
-ILAPI ILvoid		ILAPIENTRY ilBindImage(ILuint Image);
+ILAPI void		ILAPIENTRY ilBindImage(ILuint Image);
 ILAPI ILboolean		ILAPIENTRY ilBlit(ILuint Source, ILint DestX, ILint DestY, ILint DestZ, ILuint SrcX, ILuint SrcY, ILuint SrcZ, ILuint Width, ILuint Height, ILuint Depth);
-ILAPI ILvoid		ILAPIENTRY ilClearColour(ILclampf Red, ILclampf Green, ILclampf Blue, ILclampf Alpha);
-ILAPI ILboolean		ILAPIENTRY ilClearImage(ILvoid);
-ILAPI ILuint		ILAPIENTRY ilCloneCurImage(ILvoid);
+ILAPI void		ILAPIENTRY ilClearColour(ILclampf Red, ILclampf Green, ILclampf Blue, ILclampf Alpha);
+ILAPI ILboolean		ILAPIENTRY ilClearImage(void);
+ILAPI ILuint		ILAPIENTRY ilCloneCurImage(void);
 ILAPI ILboolean		ILAPIENTRY ilCompressFunc(ILenum Mode);
 ILAPI ILboolean		ILAPIENTRY ilConvertImage(ILenum DestFormat, ILenum DestType);
 ILAPI ILboolean		ILAPIENTRY ilConvertPal(ILenum DestFormat);
 ILAPI ILboolean		ILAPIENTRY ilCopyImage(ILuint Src);
-ILAPI ILuint		ILAPIENTRY ilCopyPixels(ILuint XOff, ILuint YOff, ILuint ZOff, ILuint Width, ILuint Height, ILuint Depth, ILenum Format, ILenum Type, ILvoid *Data);
+ILAPI ILuint		ILAPIENTRY ilCopyPixels(ILuint XOff, ILuint YOff, ILuint ZOff, ILuint Width, ILuint Height, ILuint Depth, ILenum Format, ILenum Type, void *Data);
 ILAPI ILuint		ILAPIENTRY ilCreateSubImage(ILenum Type, ILuint Num);
-ILAPI ILboolean		ILAPIENTRY ilDefaultImage(ILvoid);
-ILAPI ILvoid		ILAPIENTRY ilDeleteImages(ILsizei Num, const ILuint *Images);
+ILAPI ILboolean		ILAPIENTRY ilDefaultImage(void);
+ILAPI void		ILAPIENTRY ilDeleteImages(ILsizei Num, const ILuint *Images);
 ILAPI ILboolean		ILAPIENTRY ilDisable(ILenum Mode);
 ILAPI ILboolean		ILAPIENTRY ilEnable(ILenum Mode);
 ILAPI ILboolean		ILAPIENTRY ilFormatFunc(ILenum Mode);
-ILAPI ILvoid		ILAPIENTRY ilGenImages(ILsizei Num, ILuint *Images);
+ILAPI void		ILAPIENTRY ilGenImages(ILsizei Num, ILuint *Images);
 ILAPI ILubyte*		ILAPIENTRY ilGetAlpha(ILenum Type);
-ILAPI ILvoid            ILAPIENTRY ilModAlpha( ILdouble AlphaValue );
-ILAPI ILvoid            ILAPIENTRY ilSetAlpha( ILdouble AlphaValue );
+ILAPI void            ILAPIENTRY ilModAlpha( ILdouble AlphaValue );
+ILAPI void            ILAPIENTRY ilSetAlpha( ILdouble AlphaValue );
 ILAPI ILboolean		ILAPIENTRY ilGetBoolean(ILenum Mode);
-ILAPI ILvoid		ILAPIENTRY ilGetBooleanv(ILenum Mode, ILboolean *Param);
-ILAPI ILubyte*		ILAPIENTRY ilGetData(ILvoid);
-ILAPI ILuint		ILAPIENTRY ilGetDXTCData(ILvoid *Buffer, ILuint BufferSize, ILenum DXTCFormat);
-ILAPI ILenum		ILAPIENTRY ilGetError(ILvoid);
+ILAPI void		ILAPIENTRY ilGetBooleanv(ILenum Mode, ILboolean *Param);
+ILAPI ILubyte*		ILAPIENTRY ilGetData(void);
+ILAPI ILuint		ILAPIENTRY ilGetDXTCData(void *Buffer, ILuint BufferSize, ILenum DXTCFormat);
+ILAPI ILenum		ILAPIENTRY ilGetError(void);
 ILAPI ILint             ILAPIENTRY ilGetInteger(ILenum Mode);
-ILAPI ILvoid		ILAPIENTRY ilGetIntegerv(ILenum Mode, ILint *Param);
-ILAPI ILuint		ILAPIENTRY ilGetLumpPos(ILvoid);
-ILAPI ILubyte*		ILAPIENTRY ilGetPalette(ILvoid);
+ILAPI void		ILAPIENTRY ilGetIntegerv(ILenum Mode, ILint *Param);
+ILAPI ILuint		ILAPIENTRY ilGetLumpPos(void);
+ILAPI ILubyte*		ILAPIENTRY ilGetPalette(void);
 ILAPI const ILstring    ILAPIENTRY ilGetString(ILenum StringName);
-ILAPI ILvoid		ILAPIENTRY ilHint(ILenum Target, ILenum Mode);
-ILAPI ILvoid		ILAPIENTRY ilInit(ILvoid);
+ILAPI void		ILAPIENTRY ilHint(ILenum Target, ILenum Mode);
+ILAPI void		ILAPIENTRY ilInit(void);
 ILAPI ILboolean		ILAPIENTRY ilIsDisabled(ILenum Mode);
 ILAPI ILboolean		ILAPIENTRY ilIsEnabled(ILenum Mode);
 ILAPI ILboolean		ILAPIENTRY ilIsImage(ILuint Image);
 ILAPI ILboolean		ILAPIENTRY ilIsValid(ILenum Type, const ILstring FileName);
 ILAPI ILboolean		ILAPIENTRY ilIsValidF(ILenum Type, ILHANDLE File);
-ILAPI ILboolean		ILAPIENTRY ilIsValidL(ILenum Type, ILvoid *Lump, ILuint Size);
-ILAPI ILvoid		ILAPIENTRY ilKeyColour(ILclampf Red, ILclampf Green, ILclampf Blue, ILclampf Alpha);
+ILAPI ILboolean		ILAPIENTRY ilIsValidL(ILenum Type, void *Lump, ILuint Size);
+ILAPI void		ILAPIENTRY ilKeyColour(ILclampf Red, ILclampf Green, ILclampf Blue, ILclampf Alpha);
 ILAPI ILboolean		ILAPIENTRY ilLoad(ILenum Type, const ILstring FileName);
 ILAPI ILboolean		ILAPIENTRY ilLoadF(ILenum Type, ILHANDLE File);
 ILAPI ILboolean		ILAPIENTRY ilLoadImage(const ILstring FileName);
-ILAPI ILboolean		ILAPIENTRY ilLoadL(ILenum Type, ILvoid *Lump, ILuint Size);
+ILAPI ILboolean		ILAPIENTRY ilLoadL(ILenum Type, void *Lump, ILuint Size);
 ILAPI ILboolean		ILAPIENTRY ilLoadPal(const ILstring FileName);
 ILAPI ILboolean		ILAPIENTRY ilOriginFunc(ILenum Mode);
 ILAPI ILboolean		ILAPIENTRY ilOverlayImage(ILuint Source, ILint XCoord, ILint YCoord, ILint ZCoord);
-ILAPI ILvoid		ILAPIENTRY ilPopAttrib(ILvoid);
-ILAPI ILvoid		ILAPIENTRY ilPushAttrib(ILuint Bits);
-ILAPI ILvoid		ILAPIENTRY ilRegisterFormat(ILenum Format);
+ILAPI void		ILAPIENTRY ilPopAttrib(void);
+ILAPI void		ILAPIENTRY ilPushAttrib(ILuint Bits);
+ILAPI void		ILAPIENTRY ilRegisterFormat(ILenum Format);
 ILAPI ILboolean		ILAPIENTRY ilRegisterLoad(const ILstring Ext, IL_LOADPROC Load);
 ILAPI ILboolean		ILAPIENTRY ilRegisterMipNum(ILuint Num);
 ILAPI ILboolean		ILAPIENTRY ilRegisterNumImages(ILuint Num);
-ILAPI ILvoid		ILAPIENTRY ilRegisterOrigin(ILenum Origin);
-ILAPI ILvoid		ILAPIENTRY ilRegisterPal(ILvoid *Pal, ILuint Size, ILenum Type);
+ILAPI void		ILAPIENTRY ilRegisterOrigin(ILenum Origin);
+ILAPI void		ILAPIENTRY ilRegisterPal(void *Pal, ILuint Size, ILenum Type);
 ILAPI ILboolean		ILAPIENTRY ilRegisterSave(const ILstring Ext, IL_SAVEPROC Save);
-ILAPI ILvoid		ILAPIENTRY ilRegisterType(ILenum Type);
+ILAPI void		ILAPIENTRY ilRegisterType(ILenum Type);
 ILAPI ILboolean		ILAPIENTRY ilRemoveLoad(const ILstring Ext);
 ILAPI ILboolean		ILAPIENTRY ilRemoveSave(const ILstring Ext);
-ILAPI ILvoid		ILAPIENTRY ilResetMemory(ILvoid);
-ILAPI ILvoid		ILAPIENTRY ilResetRead(ILvoid);
-ILAPI ILvoid		ILAPIENTRY ilResetWrite(ILvoid);
+ILAPI void		ILAPIENTRY ilResetMemory(void);
+ILAPI void		ILAPIENTRY ilResetRead(void);
+ILAPI void		ILAPIENTRY ilResetWrite(void);
 ILAPI ILboolean		ILAPIENTRY ilSave(ILenum Type, const ILstring FileName);
 ILAPI ILuint		ILAPIENTRY ilSaveF(ILenum Type, ILHANDLE File);
 ILAPI ILboolean		ILAPIENTRY ilSaveImage(const ILstring FileName);
-ILAPI ILuint		ILAPIENTRY ilSaveL(ILenum Type, ILvoid *Lump, ILuint Size);
+ILAPI ILuint		ILAPIENTRY ilSaveL(ILenum Type, void *Lump, ILuint Size);
 ILAPI ILboolean		ILAPIENTRY ilSavePal(const ILstring FileName);
-ILAPI ILboolean		ILAPIENTRY ilSetData(ILvoid *Data);
+ILAPI ILboolean		ILAPIENTRY ilSetData(void *Data);
 ILAPI ILboolean		ILAPIENTRY ilSetDuration(ILuint Duration);
-ILAPI ILvoid		ILAPIENTRY ilSetInteger(ILenum Mode, ILint Param);
-ILAPI ILvoid		ILAPIENTRY ilSetMemory(mAlloc, mFree);
-ILAPI ILvoid		ILAPIENTRY ilSetPixels(ILint XOff, ILint YOff, ILint ZOff, ILuint Width, ILuint Height, ILuint Depth, ILenum Format, ILenum Type, ILvoid *Data);
-ILAPI ILvoid		ILAPIENTRY ilSetRead(fOpenRProc, fCloseRProc, fEofProc, fGetcProc, fReadProc, fSeekRProc, fTellRProc);
-ILAPI ILvoid		ILAPIENTRY ilSetString(ILenum Mode, const char *String);
-ILAPI ILvoid		ILAPIENTRY ilSetWrite(fOpenWProc, fCloseWProc, fPutcProc, fSeekWProc, fTellWProc, fWriteProc);
-ILAPI ILvoid		ILAPIENTRY ilShutDown(ILvoid);
-ILAPI ILboolean		ILAPIENTRY ilTexImage(ILuint Width, ILuint Height, ILuint Depth, ILubyte Bpp, ILenum Format, ILenum Type, ILvoid *Data);
+ILAPI void		ILAPIENTRY ilSetInteger(ILenum Mode, ILint Param);
+ILAPI void		ILAPIENTRY ilSetMemory(mAlloc, mFree);
+ILAPI void		ILAPIENTRY ilSetPixels(ILint XOff, ILint YOff, ILint ZOff, ILuint Width, ILuint Height, ILuint Depth, ILenum Format, ILenum Type, void *Data);
+ILAPI void		ILAPIENTRY ilSetRead(fOpenRProc, fCloseRProc, fEofProc, fGetcProc, fReadProc, fSeekRProc, fTellRProc);
+ILAPI void		ILAPIENTRY ilSetString(ILenum Mode, const char *String);
+ILAPI void		ILAPIENTRY ilSetWrite(fOpenWProc, fCloseWProc, fPutcProc, fSeekWProc, fTellWProc, fWriteProc);
+ILAPI void		ILAPIENTRY ilShutDown(void);
+ILAPI ILboolean		ILAPIENTRY ilTexImage(ILuint Width, ILuint Height, ILuint Depth, ILubyte Bpp, ILenum Format, ILenum Type, void *Data);
 ILAPI ILboolean		ILAPIENTRY ilTypeFunc(ILenum Mode);
 
 ILAPI ILboolean		ILAPIENTRY ilLoadData(const ILstring FileName, ILuint Width, ILuint Height, ILuint Depth, ILubyte Bpp);
 ILAPI ILboolean		ILAPIENTRY ilLoadDataF(ILHANDLE File, ILuint Width, ILuint Height, ILuint Depth, ILubyte Bpp);
-ILAPI ILboolean		ILAPIENTRY ilLoadDataL(ILvoid *Lump, ILuint Size, ILuint Width, ILuint Height, ILuint Depth, ILubyte Bpp);
+ILAPI ILboolean		ILAPIENTRY ilLoadDataL(void *Lump, ILuint Size, ILuint Width, ILuint Height, ILuint Depth, ILubyte Bpp);
 ILAPI ILboolean		ILAPIENTRY ilSaveData(const ILstring FileName);
 
-ILAPI ILboolean		ILAPIENTRY ilLoadFromJpegStruct(ILvoid* JpegDecompressorPtr);
-ILAPI ILboolean		ILAPIENTRY ilSaveFromJpegStruct(ILvoid* JpegCompressorPtr);
+ILAPI ILboolean		ILAPIENTRY ilLoadFromJpegStruct(void* JpegDecompressorPtr);
+ILAPI ILboolean		ILAPIENTRY ilSaveFromJpegStruct(void* JpegCompressorPtr);
 
 // For all those weirdos that spell "colour" without the 'u'.
 #define ilClearColor	ilClearColour
