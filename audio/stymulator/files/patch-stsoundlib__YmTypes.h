--- ./stsoundlib/YmTypes.h.orig	2010-04-23 13:49:47.000000000 +0200
+++ ./stsoundlib/YmTypes.h	2010-04-23 13:49:47.000000000 +0200
@@ -44,45 +44,44 @@
 // These settings are ok for Windows 32bits platform.
 
 #ifdef YM_INTEGER_ONLY
-typedef		__int64				yms64;
+typedef		__int64        yms64;
 #else
-typedef		float				ymfloat;
+typedef		float          ymfloat;
 #endif
 
-typedef		signed char			yms8;			//  8 bits signed integer
-typedef		signed short		yms16;			// 16 bits signed integer
-typedef		signed long			yms32;			// 32 bits signed integer
+typedef		signed char    yms8;    /*  8 bits signed integer */
+typedef		signed short   yms16;   /* 16 bits signed integer */
+typedef		signed long    yms32;   /* 32 bits signed integer */
 
-typedef		unsigned char		ymu8;			//  8 bits unsigned integer
-typedef		unsigned short		ymu16;			// 16 bits unsigned integer
-typedef		unsigned long		ymu32;			// 32 bits unsigned integer
+typedef		unsigned char  ymu8;    /*  8 bits unsigned integer */
+typedef		unsigned short ymu16;   /* 16 bits unsigned integer */
+typedef		unsigned long  ymu32;   /* 32 bits unsigned integer */
 
-typedef		int					ymint;			// Native "int" for speed purpose. StSound suppose int is signed and at least 32bits. If not, change it to match to yms32
+typedef		int            ymint;   /* Native "int" for speed purpose. StSound suppose int is signed and at least 32bits. If not, change it to match to yms32 */
 
-typedef		char				ymchar;			// 8 bits char character (used for null terminated strings)
+typedef		char           ymchar;  /* 8 bits char character (used for null terminated strings) */
 
-#else // These settings are O.K. for GNU/Linux 32/64bit platforms (done by Grzegorz Tomasz Stanczyk)
+#else
+
+#include <stdint.h>
 
 #ifdef YM_INTEGER_ONLY
-typedef		long long int	yms64;
+typedef		int64_t  yms64;
 #else
-typedef		float		ymfloat;
+typedef		float    ymfloat;
 #endif
-typedef		signed char	yms8;			//  8 bits signed integer
-typedef		signed short	yms16;			// 16 bits signed integer
-//changed for 64bit GNU/Linux compatibility by Grzegorz Stanczyk (2007.03.06)
-//typedef		signed long	yms32;			// 32 bits signed integer
-typedef		signed int	yms32;			// 32 bits signed integer
-
-typedef		unsigned char	ymu8;			//  8 bits unsigned integer
-typedef		unsigned short	ymu16;			// 16 bits unsigned integer
-//changed for 64bit GNU/Linux compatibility by Grzegorz Stanczyk (2007.03.06)
-//typedef		unsigned long	ymu32;			// 32 bits unsigned integer
-typedef		unsigned int	ymu32;			// 32 bits unsigned integer
+typedef		int8_t   yms8;          /*  8 bits signed integer */
+typedef		int16_t  yms16;         /* 16 bits signed integer */
+typedef		int32_t  yms32;         /* 32 bits signed integer */
 
-typedef		int		ymint;			// Native "int" for speed purpose. StSound suppose int is signed and at least 32bits. If not, change it to match to yms32
+typedef		uint8_t  ymu8;          /*  8 bits unsigned integer */
+typedef		uint16_t ymu16;         /* 16 bits unsigned integer */
+typedef		uint32_t ymu32;         /* 32 bits unsigned integer */
 
-typedef		char		ymchar;			// 8 bits char character (used for null terminated strings)
+/* Native "int" for speed purpose. StSound suppose int is signed and at least 32bits. If not, change it to match to yms32 */
+/*typedef		int32_t  ymint; */
+typedef		int      ymint;
+typedef		char     ymchar;        /* 8 bits char character (used for null terminated strings) */
 
 #endif
 
@@ -93,8 +92,8 @@
 //-----------------------------------------------------------
 // Multi-platform
 //-----------------------------------------------------------
-typedef		int					ymbool;			// boolean ( theorically nothing is assumed for its size in StSound,so keep using int)
-typedef		yms16				ymsample;		// StSound emulator render mono 16bits signed PCM samples
+typedef		int      ymbool;        /*  boolean ( theorically nothing is assumed for its size in StSound,so keep using int) */
+typedef		yms16    ymsample;      /* StSound emulator render mono 16bits signed PCM samples */
 
 #define		YMFALSE				(0)
 #define		YMTRUE				(!YMFALSE)
