--- map.c.orig	2016-06-14 16:25:53 UTC
+++ map.c
@@ -24,6 +24,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <machine/endian.h>
 #include "allegro.h"
 #include "map.h"
 #include "timer.h"
@@ -64,7 +65,41 @@ Tmap *create_map(int w, int h) {
 
 	return m;
 }
-	
+
+static void mem_to_int(int *dest, unsigned char *mem)
+{
+#if __BYTE_ORDER == __LITTLE_ENDIAN
+	memcpy(dest, mem, 4);
+#else
+	*dest = mem[0] | (((int)mem[1]) << 8) | (((int)mem[2]) << 16) |
+		(((int)mem[3]) << 24);
+#endif
+}
+
+static void fread_int(int *dest, FILE *fp)
+{
+#if __BYTE_ORDER == __LITTLE_ENDIAN
+	fread(dest, 4, 1, fp);
+#else
+	unsigned char buf[4];
+	fread(buf, 1, 4, fp);
+	mem_to_int(dest, buf);
+#endif
+}
+
+static void fwrite_int(const int *src, FILE *fp)
+{
+#if __BYTE_ORDER == __LITTLE_ENDIAN
+	fwrite(src, 4, 1, fp);
+#else
+	unsigned char buf[4];
+	buf[0] = *src;
+	buf[1] = *src >> 8;
+	buf[2] = *src >> 16;
+	buf[3] = *src >> 24;
+	fwrite(buf, 1, 4, fp);
+#endif
+}
 
 // loads one splendind map from disk
 Tmap *load_map(char *fname) {
@@ -93,7 +128,19 @@ Tmap *load_map(char *fname) {
 	}
 	
 	// read datastruct
-	fread(m, sizeof(Tmap), 1, fp);
+	// a mapfile contain a raw dump of the Tmap struct made on an i386
+	// the code below reads these struct dumps in an arch neutral manner
+	// Note this dumps contains pointers, these are not used because these
+	// ofcourse point to some no longer valid address.
+	fread(m, 64, 1, fp);             // first 64 bytes data
+	fread_int(&(m->width), fp);
+	fread_int(&(m->height), fp);
+	fread(header, 4, 1, fp);         // skip the first pointer
+	fread_int(&(m->offset_x), fp);
+	fread_int(&(m->offset_y), fp);
+	fread(header, 4, 1, fp);         // skip the second pointer
+	fread_int(&(m->start_x), fp);
+	fread_int(&(m->start_y), fp);
 
 	// read map data
 	m->dat = malloc(m->width * m->height * sizeof(Tmappos));
@@ -116,8 +163,8 @@ Tmap *load_map(char *fname) {
 // loads one splendind map from memory
 Tmap *load_map_from_memory(void *mem) {
 	Tmap *m;
-	char header[6];
-    char *c = (char *)mem;
+	unsigned char header[6];
+	unsigned char *c = (unsigned char *)mem;
 
 	
 	// does the header match?
@@ -137,9 +184,19 @@ Tmap *load_map_from_memory(void *mem) {
 	}
 	
 	// read datastruct
-	// fread(m, sizeof(Tmap), 1, fp);
-	memcpy(m, c, sizeof(Tmap));
-    c += sizeof(Tmap);
+	// a mapfile contain a raw dump of the Tmap struct made on an i386
+	// the code below reads these struct dumps in an arch neutral manner
+	// Note this dumps contains pointers, these are not used because these
+	// ofcourse point to some no longer valid address.
+	memcpy(m, c, 64); c += 64;             // first 64 bytes data
+	mem_to_int(&(m->width), c);  c += 4;
+	mem_to_int(&(m->height), c); c += 4;
+	c += 4;	                               // skip the first pointer
+	mem_to_int(&(m->offset_x), c); c += 4;
+	mem_to_int(&(m->offset_y), c); c += 4;
+	c += 4;                                // skip the second pointer
+	mem_to_int(&(m->start_x), c); c+= 4;
+	mem_to_int(&(m->start_y), c); c+= 4;
 
 	// read map data
 	m->dat = malloc(m->width * m->height * sizeof(Tmappos));
@@ -174,7 +231,18 @@ int save_map(Tmap *m, char *fname) {
 	fwrite(header, 6, 1, fp);
 
 	// write datastruct
-	fwrite(m, sizeof(Tmap), 1, fp);
+	// a mapfile should contain a raw dump of the Tmap struct as made on an
+	// i386 the code below writes a struct dump as an i386 in an arch
+	// neutral manner
+	fwrite(m, 64, 1, fp);             // first 64 bytes data
+	fwrite_int(&(m->width), fp);
+	fwrite_int(&(m->height), fp);
+	fwrite(header, 4, 1, fp);         // skip the first pointer
+	fwrite_int(&(m->offset_x), fp);
+	fwrite_int(&(m->offset_y), fp);
+	fwrite(header, 4, 1, fp);         // skip the second pointer
+	fwrite_int(&(m->start_x), fp);
+	fwrite_int(&(m->start_y), fp);
 
 	// write map data
 	fwrite(m->dat, sizeof(Tmappos), m->width * m->height, fp);
@@ -409,7 +477,7 @@ int is_ground(Tmap *sm , int x, int y) {
 	}
 
 	if (mask == 5 && oy > 31 - ox) return mask; // 45 degree slope / 
-	if (mask == 6 && oy > ox) return mask;		// 45 degree slope \
+	if (mask == 6 && oy > ox) return mask;		// 45 degree slope \ .
 
 	// the not so simple ones
 	if (mask == 3 && oy > 31 - ox / 2) return mask;	// 22 degree slope / (low)
