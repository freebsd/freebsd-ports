--- include/IL/ilu.h.orig	2007-09-17 17:42:11.000000000 +0200
+++ include/IL/ilu.h	2007-09-17 17:43:47.000000000 +0200
@@ -132,40 +132,40 @@
 
 
 // ImageLib Utility Functions
-ILAPI ILboolean			ILAPIENTRY iluAlienify(ILvoid);
+ILAPI ILboolean			ILAPIENTRY iluAlienify(void);
 ILAPI ILboolean			ILAPIENTRY iluBlurAvg(ILuint Iter);
 ILAPI ILboolean			ILAPIENTRY iluBlurGaussian(ILuint Iter);
-ILAPI ILboolean			ILAPIENTRY iluBuildMipmaps(ILvoid);
-ILAPI ILuint			ILAPIENTRY iluColoursUsed(ILvoid);
+ILAPI ILboolean			ILAPIENTRY iluBuildMipmaps(void);
+ILAPI ILuint			ILAPIENTRY iluColoursUsed(void);
 ILAPI ILboolean			ILAPIENTRY iluCompareImage(ILuint Comp);
 ILAPI ILboolean			ILAPIENTRY iluContrast(ILfloat Contrast);
 ILAPI ILboolean			ILAPIENTRY iluCrop(ILuint XOff, ILuint YOff, ILuint ZOff, ILuint Width, ILuint Height, ILuint Depth);
-ILAPI ILvoid			ILAPIENTRY iluDeleteImage(ILuint Id);
-ILAPI ILboolean			ILAPIENTRY iluEdgeDetectE(ILvoid);
-ILAPI ILboolean			ILAPIENTRY iluEdgeDetectP(ILvoid);
-ILAPI ILboolean			ILAPIENTRY iluEdgeDetectS(ILvoid);
-ILAPI ILboolean			ILAPIENTRY iluEmboss(ILvoid);
+ILAPI void			ILAPIENTRY iluDeleteImage(ILuint Id);
+ILAPI ILboolean			ILAPIENTRY iluEdgeDetectE(void);
+ILAPI ILboolean			ILAPIENTRY iluEdgeDetectP(void);
+ILAPI ILboolean			ILAPIENTRY iluEdgeDetectS(void);
+ILAPI ILboolean			ILAPIENTRY iluEmboss(void);
 ILAPI ILboolean			ILAPIENTRY iluEnlargeCanvas(ILuint Width, ILuint Height, ILuint Depth);
 ILAPI ILboolean			ILAPIENTRY iluEnlargeImage(ILfloat XDim, ILfloat YDim, ILfloat ZDim);
-ILAPI ILboolean			ILAPIENTRY iluEqualize(ILvoid);
+ILAPI ILboolean			ILAPIENTRY iluEqualize(void);
 ILAPI const ILstring	ILAPIENTRY iluErrorString(ILenum Error);
-ILAPI ILboolean			ILAPIENTRY iluFlipImage(ILvoid);
+ILAPI ILboolean			ILAPIENTRY iluFlipImage(void);
 ILAPI ILboolean			ILAPIENTRY iluGammaCorrect(ILfloat Gamma);
-ILAPI ILuint			ILAPIENTRY iluGenImage(ILvoid);
-ILAPI ILvoid			ILAPIENTRY iluGetImageInfo(ILinfo *Info);
+ILAPI ILuint			ILAPIENTRY iluGenImage(void);
+ILAPI void			ILAPIENTRY iluGetImageInfo(ILinfo *Info);
 ILAPI ILint				ILAPIENTRY iluGetInteger(ILenum Mode);
-ILAPI ILvoid			ILAPIENTRY iluGetIntegerv(ILenum Mode, ILint *Param);
+ILAPI void			ILAPIENTRY iluGetIntegerv(ILenum Mode, ILint *Param);
 ILAPI const ILstring	ILAPIENTRY iluGetString(ILenum StringName);
-ILAPI ILvoid			ILAPIENTRY iluImageParameter(ILenum PName, ILenum Param);
-ILAPI ILvoid			ILAPIENTRY iluInit(ILvoid);
-ILAPI ILboolean			ILAPIENTRY iluInvertAlpha(ILvoid);
+ILAPI void			ILAPIENTRY iluImageParameter(ILenum PName, ILenum Param);
+ILAPI void			ILAPIENTRY iluInit(void);
+ILAPI ILboolean			ILAPIENTRY iluInvertAlpha(void);
 ILAPI ILuint			ILAPIENTRY iluLoadImage(const ILstring FileName);
-ILAPI ILboolean			ILAPIENTRY iluMirror(ILvoid);
-ILAPI ILboolean			ILAPIENTRY iluNegative(ILvoid);
+ILAPI ILboolean			ILAPIENTRY iluMirror(void);
+ILAPI ILboolean			ILAPIENTRY iluNegative(void);
 ILAPI ILboolean			ILAPIENTRY iluNoisify(ILclampf Tolerance);
 ILAPI ILboolean			ILAPIENTRY iluPixelize(ILuint PixSize);
-ILAPI ILvoid			ILAPIENTRY iluRegionfv(ILpointf *Points, ILuint n);
-ILAPI ILvoid			ILAPIENTRY iluRegioniv(ILpointi *Points, ILuint n);
+ILAPI void			ILAPIENTRY iluRegionfv(ILpointf *Points, ILuint n);
+ILAPI void			ILAPIENTRY iluRegioniv(ILpointi *Points, ILuint n);
 ILAPI ILboolean			ILAPIENTRY iluReplaceColour(ILubyte Red, ILubyte Green, ILubyte Blue, ILfloat Tolerance);
 ILAPI ILboolean			ILAPIENTRY iluRotate(ILfloat Angle);
 ILAPI ILboolean			ILAPIENTRY iluRotate3D(ILfloat x, ILfloat y, ILfloat z, ILfloat Angle);
@@ -174,7 +174,7 @@
 ILAPI ILboolean			ILAPIENTRY iluScale(ILuint Width, ILuint Height, ILuint Depth);
 ILAPI ILboolean			ILAPIENTRY iluScaleColours(ILfloat r, ILfloat g, ILfloat b);
 ILAPI ILboolean			ILAPIENTRY iluSharpen(ILfloat Factor, ILuint Iter);
-ILAPI ILboolean			ILAPIENTRY iluSwapColours(ILvoid);
+ILAPI ILboolean			ILAPIENTRY iluSwapColours(void);
 ILAPI ILboolean			ILAPIENTRY iluWave(ILfloat Angle);
 
 #define iluColorsUsed	iluColoursUsed
