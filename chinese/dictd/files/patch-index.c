--- index.c.orig	Sun Nov 24 01:24:10 2002
+++ index.c	Sun Nov 24 01:24:21 2002
@@ -91,6 +91,12 @@
 
    for (; *src; ++src) {
       c = * (const unsigned char *) src;
+      if((c & 0x80) && *(src+1)) {
+	 *dest++ = c;
+	 *dest++ = *(src+1);
+	 src++;
+	 continue;
+      }
 
       if (isspace( c )) {
          *dest++ = ' ';
@@ -150,7 +156,7 @@
     isspacealnumtab_allchars['\t'] = isspacealnumtab_allchars['\n'] = 0; /* special */
 
     for (i = 0; i <= UCHAR_MAX; i++){
-	if (islower (i) || (utf8_mode && i >= 0xC0))
+	if (islower (i) || (utf8_mode && i >= 0xC0) || (i>=0x80))
 	    chartab[charcount++] = i;
     }
 
@@ -317,6 +326,15 @@
 
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
       if (!dbindex -> isspacealnum[* (const unsigned char *) start]) {
 	 ++start;
 	 continue;
@@ -359,6 +377,8 @@
        *start != '\t' &&
        !dbindex -> isspacealnum[* (const unsigned char *) start])
    {
+      if((*start & 0x80) && start[1]!='\t')
+        break;
       ++start;
    }
 
