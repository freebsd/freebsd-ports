--- 9e.c.orig	Thu Jun 15 13:40:52 2000
+++ 9e.c	Fri Jun 23 04:16:00 2000
@@ -139,17 +139,16 @@
     }
 
     if(Hdrs) {
-      fprintf(stderr, "%s %lo %s %s %ld %ld\n", namebuf, mode,
+      fprintf(stderr, "%s %lo %s %s %ld %ld\n", name, mode,
 	      owner, group, mtime, size);
       fout = NULL;
     } else {
       if (Verbose)
-	fprintf(stderr, "%s %d\n", namebuf, size);
+	fprintf(stderr, "%s\n", name);
       if(mode & CHDIR) {
         assert(size == 0);
 	/* Give ourselves read, write, and execute permission */
-        if(mkdir(name, (mode & ~CHDIR) | 0700) < 0)
-	  warn("mkdir(2) failed for", name);
+        mkdir(name, (mode & ~CHDIR) | 0700);
         continue;
       }
       if((fout=fopen(name, "w+b")) == NULL)
