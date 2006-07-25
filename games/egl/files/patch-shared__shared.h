--- shared/shared.h.orig	Mon Jul 24 15:01:39 2006
+++ shared/shared.h	Mon Jul 24 15:05:26 2006
@@ -742,12 +742,12 @@
 ==============================================================================
 */
 
-float		(*LittleFloat) (float f);
-int			(*LittleLong) (int l);
-int16		(*LittleShort) (int16 s);
-float		(*BigFloat) (float f);
-int			(*BigLong) (int l);
-int16		(*BigShort) (int16 s);
+float		LittleFloat (float f);
+int		LittleLong (int l);
+int16		LittleShort (int16 s);
+float		BigFloat (float f);
+int		BigLong (int l);
+int16		BigShort (int16 s);
 
 void		Swap_Init (void);
 
