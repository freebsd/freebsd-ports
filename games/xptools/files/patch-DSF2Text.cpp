--- src/DSFTools/DSF2Text.cpp.orig	2018-07-15 03:25:39 UTC
+++ src/DSFTools/DSF2Text.cpp
@@ -379,7 +379,7 @@ static bool Text2DSFWithWriterAny(const 
 {
 	bool is_pipe = strcmp(inFileName, "-") == 0;
 	FILE * fi = (!is_pipe) ? fopen(inFileName, "r") : stdin;
-	if (!fi) return NULL;
+	if (!fi) return false;
 
 	int divisions = 8;
 	float west = 999.0, south = 999.0, north = 999.0, east = 999.0;
