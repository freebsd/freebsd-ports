--- src/ri/texmake.cpp.orig
+++ src/ri/texmake.cpp
@@ -455,7 +455,7 @@
 	RtFilterFunc	filter			=	filt;
 	float			filterWidth		=	fwidth;
 	float			filterHeight	=	fheight;
-	char			*outPath		=	NULL;
+	char			*outPath		=	(char*)NULL;
 	int				pyramidSize;
 	char			inputFileName[OS_MAX_PATH_LENGTH];
 	TIFF			*outHandle;
@@ -522,7 +522,7 @@
 	RtFilterFunc	filter			=	filt;
 	float			filterWidth		=	fwidth;
 	float			filterHeight	=	fheight;
-	char			*outPath		=	NULL;
+	char			*outPath		=	(char*)NULL;
 	int				pyramidSize;
 	char			inputFileName[OS_MAX_PATH_LENGTH];
 	TIFF			*outHandle;
@@ -618,7 +618,7 @@
 	RtFilterFunc	filter			=	filt;
 	float			filterWidth		=	fwidth;
 	float			filterHeight	=	fheight;
-	char			*outPath		=	NULL;
+	char			*outPath		=	(char*)NULL;
 	int				pyramidSize;
 	char			inputFileName[OS_MAX_PATH_LENGTH];
 	TIFF			*outHandle;
@@ -723,7 +723,7 @@
 	RtFilterFunc	filter			=	filt;
 	float			filterWidth		=	fwidth;
 	float			filterHeight	=	fheight;
-	char			*outPath		=	NULL;
+	char			*outPath		=	(char*)NULL;
 	int				pyramidSize;
 	char			inputFileName[OS_MAX_PATH_LENGTH];
 	TIFF			*outHandle;
@@ -793,7 +793,7 @@
 	RtFilterFunc	filter			=	filt;
 	float			filterWidth		=	fwidth;
 	float			filterHeight	=	fheight;
-	char			*outPath		=	NULL;
+	char			*outPath		=	(char*)NULL;
 	int				pyramidSize;
 	char			inputFileName[OS_MAX_PATH_LENGTH];
 	TIFF			*outHandle;
