--- epi/image_hq2x.cc.orig	2009-10-18 12:33:23.000000000 +0200
+++ epi/image_hq2x.cc	2016-04-12 22:06:00.628879000 +0200
@@ -169,15 +169,20 @@ void Interp10(u8_t * dest, u32_t c1, u32
 #define PIXEL11_90    Interp9(dest+BpL+4, c[5], c[6], c[8]);
 #define PIXEL11_100   Interp10(dest+BpL+4, c[5], c[6], c[8]);
 
+static inline u32_t UDiff(u32_t u1, u32_t u2)
+{
+	return (u1 >= u2) ? u1 - u2 : u2 - u1;
+}
+
 inline bool Diff(const u8_t p1, const u8_t p2)
 {
 	u32_t YUV1 = PixelYUV[p1];
 	u32_t YUV2 = PixelYUV[p2];
 
 	return (YUV1 & Amask) != (YUV2 & Amask) ||
-		   (u32_t)abs((YUV1 & Ymask) - (YUV2 & Ymask)) > trY ||
-		   (u32_t)abs((YUV1 & Umask) - (YUV2 & Umask)) > trU ||
-		   (u32_t)abs((YUV1 & Vmask) - (YUV2 & Vmask)) > trV;
+		   UDiff((YUV1 & Ymask), (YUV2 & Ymask)) > trY ||
+		   UDiff((YUV1 & Umask), (YUV2 & Umask)) > trU ||
+		   UDiff((YUV1 & Vmask), (YUV2 & Vmask)) > trV;
 }
 
 void Setup(const u8_t *palette, int trans_pixel)
