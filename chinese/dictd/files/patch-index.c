--- index.c.orig	Mon Mar 10 01:06:16 2003
+++ index.c	Mon Oct 27 22:10:18 2003
@@ -103,6 +103,12 @@
 
    for (; *src; ++src) {
       c = * (const unsigned char *) src;
+      if((c & 0x80) && *(src+1)) {
+        *dest++ = c;
+        *dest++ = *(src+1);
+        src++;
+        continue;
+      }
 
       if (isspace( c )) {
          *dest++ = ' ';
@@ -184,7 +190,7 @@
 
    charcount = 0;
    for (i = 0; i <= UCHAR_MAX; i++){
-      if (islower (i) || (utf8_mode && i >= 0xC0))
+      if (islower (i) || (utf8_mode && i >= 0xC0) || (i>=0x80))
 	 chartab [charcount++] = i;
    }
 
@@ -293,6 +299,15 @@
 
    /* FIXME.  Optimize this inner loop. */
    while (*word && start < end && *start != '\t') {
+      if ((*start & 0x80) && start+1<end && start[1]!='\t') {
+        if(start[0]!=word[0])
+         return ((unsigned)word[0]<(unsigned)start[0])?-2:1;
+        if(start[1]!=word[1])
+         return ((unsigned)word[1]<(unsigned)start[1])?-2:1;
+        word+=2;
+        start+=2;
+        continue;
+      }
       if (!dbindex -> isspacealnum[* (const unsigned char *) start]) {
 	 ++start;
 	 continue;
@@ -340,6 +355,8 @@
        *start != '\t' &&
        !dbindex -> isspacealnum[* (const unsigned char *) start])
    {
+      if((*start & 0x80) && start[1]!='\t')
+        break;
       ++start;
    }
 
