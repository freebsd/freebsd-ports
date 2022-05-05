--- magick/pixel-accessor.h.orig	2022-05-05 04:22:46 UTC
+++ magick/pixel-accessor.h
@@ -103,12 +103,12 @@ extern "C" {
 #define SetPixelYellow(pixel,value) ((pixel)->blue=(Quantum) (value))
 #define SetPixelY(pixel,value) ((pixel)->red=(Quantum) (value))
 
-static inline const MagickRealType AbsolutePixelValue(const MagickRealType x)
+static inline MagickRealType AbsolutePixelValue(const MagickRealType x)
 {
   return(x < 0.0f ? -x : x);
 }
 
-static inline const Quantum ClampPixel(const MagickRealType value)
+static inline Quantum ClampPixel(const MagickRealType value)
 { 
   if (value < 0.0f)
     return((Quantum) 0); 
@@ -121,7 +121,7 @@ static inline const Quantum ClampPixel(const MagickRea
 #endif
 }
 
-static inline const double PerceptibleReciprocal(const double x)
+static inline double PerceptibleReciprocal(const double x)
 { 
   double
     sign;
@@ -135,7 +135,7 @@ static inline const double PerceptibleReciprocal(const
   return(sign/MagickEpsilon);
 }   
 
-static inline const MagickRealType GetPixelLuma(
+static inline MagickRealType GetPixelLuma(
   const Image *magick_restrict image,const PixelPacket *magick_restrict pixel)
 {
   MagickRealType
@@ -147,7 +147,7 @@ static inline const MagickRealType GetPixelLuma(
   return(intensity);
 }
 
-static inline const MagickRealType GetPixelLuminance(
+static inline MagickRealType GetPixelLuminance(
   const Image *magick_restrict image,const PixelPacket *magick_restrict pixel)
 {
   MagickRealType
@@ -165,7 +165,7 @@ static inline const MagickRealType GetPixelLuminance(
   return(intensity);
 }
 
-static inline const MagickBooleanType IsPixelAtDepth(const Quantum pixel,
+static inline MagickBooleanType IsPixelAtDepth(const Quantum pixel,
   const QuantumAny range)
 {
   Quantum
@@ -183,7 +183,7 @@ static inline const MagickBooleanType IsPixelAtDepth(c
   return(pixel == quantum ? MagickTrue : MagickFalse);
 }
 
-static inline const MagickBooleanType IsPixelGray(const PixelPacket *pixel)
+static inline MagickBooleanType IsPixelGray(const PixelPacket *pixel)
 {
   MagickRealType
     green_blue,
@@ -197,7 +197,7 @@ static inline const MagickBooleanType IsPixelGray(cons
   return(MagickFalse);
 }
 
-static inline const MagickBooleanType IsPixelMonochrome(
+static inline MagickBooleanType IsPixelMonochrome(
   const PixelPacket *pixel)
 {
   MagickRealType
@@ -217,7 +217,7 @@ static inline const MagickBooleanType IsPixelMonochrom
   return(MagickFalse);
 }
 
-static inline const Quantum PixelPacketIntensity(const PixelPacket *pixel)
+static inline Quantum PixelPacketIntensity(const PixelPacket *pixel)
 {
   MagickRealType
     intensity;
