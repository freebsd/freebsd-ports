--- spice3f5/common/src/bin/sconvert.c.orig	1994-01-29 19:12:56 UTC
+++ spice3f5/common/src/bin/sconvert.c
@@ -80,19 +80,19 @@ main(ac, av)
 
         case 1: printf("Input file: ");
             (void) fflush(stdout);
-            (void) gets(buf);
+            (void) fgets(buf,BSIZE_SP,stdin);
             sf = copy(buf);
             printf("Input type: ");
             (void) fflush(stdout);
-            (void) gets(buf);
+            (void) fgets(buf,BSIZE_SP,stdin);
             f = buf[0];
             printf("Output file: ");
             (void) fflush(stdout);
-            (void) gets(buf);
+            (void) fgets(buf,BSIZE_SP,stdin);
             af = copy(buf);
             printf("Output type: ");
             (void) fflush(stdout);
-            (void) gets(buf);
+            (void) fgets(buf,BSIZE_SP,stdin);
             t = buf[0];
             break;
         default:
