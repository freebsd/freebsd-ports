--- bwValues.c.orig	2023-12-28 21:21:29 UTC
+++ bwValues.c
@@ -6,7 +6,7 @@
 #include <zlib.h>
 #include <errno.h>
 
-static uint32_t roundup(uint32_t v) {
+static uint32_t bwRoundup(uint32_t v) {
     v--;
     v |= v >> 1;
     v |= v >> 2;
@@ -347,7 +347,7 @@ static bwOverlappingIntervals_t *pushIntervals(bwOverl
 //Returns NULL on error, in which case o has been free()d
 static bwOverlappingIntervals_t *pushIntervals(bwOverlappingIntervals_t *o, uint32_t start, uint32_t end, float value) {
     if(o->l+1 >= o->m) {
-        o->m = roundup(o->l+1);
+        o->m = bwRoundup(o->l+1);
         o->start = realloc(o->start, o->m * sizeof(uint32_t));
         if(!o->start) goto error;
         o->end = realloc(o->end, o->m * sizeof(uint32_t));
@@ -367,7 +367,7 @@ static bbOverlappingEntries_t *pushBBIntervals(bbOverl
 
 static bbOverlappingEntries_t *pushBBIntervals(bbOverlappingEntries_t *o, uint32_t start, uint32_t end, char *str, int withString) {
     if(o->l+1 >= o->m) {
-        o->m = roundup(o->l+1);
+        o->m = bwRoundup(o->l+1);
         o->start = realloc(o->start, o->m * sizeof(uint32_t));
         if(!o->start) goto error;
         o->end = realloc(o->end, o->m * sizeof(uint32_t));
