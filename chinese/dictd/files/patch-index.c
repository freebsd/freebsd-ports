--- index.c.orig	Mon Apr 29 22:43:42 2002
+++ index.c	Fri Jul 19 05:23:01 2002
@@ -120,6 +120,15 @@
    
 				/* FIXME.  Optimize this inner loop. */
    while (*word && start < end && *start != '\t') {
+      if ((*start & 0x80) && start+1<end && start[1]!='\t') {
+        if(start[0]!=word[0]) 
+	  return ((unsigned)word[0]<(unsigned)start[0])?-2:1;
+        if(start[1]!=word[1]) 
+	  return ((unsigned)word[1]<(unsigned)start[1])?-2:1;
+        word+=2;
+        start+=2;
+        continue;
+      }
       if (!isspacealnum(*start)) {
 	 ++start;
 	 continue;
@@ -139,7 +148,11 @@
       ++start;
    }
    
-   while (*start != '\t' && !isspacealnum(*start)) ++start;
+   while (*start != '\t' && !isspacealnum(*start))
+     if((*start & 0x80) && start[1]!='\t')
+       break;
+     else
+       ++start;
 
    PRINTF(DBG_SEARCH,("   result = %d\n",
 		      *word ? 1 : ((*start != '\t') ? -1 : 0)));
@@ -315,7 +328,6 @@
    int        count = 0;
    dictWord   *datum;
    const char *previous = NULL;
-   
    while (pt && pt < database->index->end) {
       if (!compare( word, pt, database->index->end )) {
 	 if (!previous || altcompare(previous, pt, database->index->end)) {
@@ -643,6 +655,7 @@
    char       tmp;
    dictWord   *datum;
 
+   if(*word & 0x80) return count;
 #define CHECK                                         \
    if ((pt = dict_index_search(buf, database->index)) \
        && !compare(buf, pt, database->index->end)) {  \
@@ -724,6 +737,11 @@
       if (isspace( *(const unsigned char *)w )) {
          *pt++ = ' ';
       } else {
+         if((*w & 0x80) && *(w+1)) {
+            *pt++=*w++;
+            *pt++=*w;
+            continue;
+         }
          if (!isalnum( *(const unsigned char *)w )) continue;
          *pt++ = tolower(*w);
       }
@@ -790,6 +808,11 @@
 	 = binary_search( buf, i->start, i->end );
    }
    for (j = '0'; j <= '9'; j++) {
+      buf[0] = j;
+      buf[1] = '\0';
+      i->optStart[j] = binary_search( buf, i->start, i->end );
+   }
+   for (j = 0x80; j <= 255; j++) {
       buf[0] = j;
       buf[1] = '\0';
       i->optStart[j] = binary_search( buf, i->start, i->end );
