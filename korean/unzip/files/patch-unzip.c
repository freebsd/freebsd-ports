--- unzip.c.orig	Sun Jan 27 11:26:16 2002
+++ unzip.c	Wed May 21 03:42:30 2003
@@ -595,7 +595,8 @@
   -o  overwrite files WITHOUT prompting      -aa treat ALL files as text\n \
  -j  junk paths (do not make directories)   -v  be verbose/print version info\n\
  %c-C%c match filenames case-insensitively    %c-L%c make (some) names \
-lowercase\n %-42s %c-V%c retain VMS version numbers\n%s";
+lowercase\n %-42s %c-V%c retain VMS version numbers\n\
+                                             -.  don't translate filenames\n%s";
 
 static ZCONST char Far UnzipUsageLine5[] = "\
 Examples (see unzip.txt for more info):\n\
@@ -1476,6 +1477,12 @@
                         ++uO.ddotflag;
                     break;
 #endif /* !RISCOS && !CMS_MVS && !TANDEM */
+ 		case ('.'):
+                     if (negative)
+                         uO.dotflag = FALSE, negative = 0;
+                     else
+                         uO.dotflag = TRUE;
+                     break;
                 default:
                     error = TRUE;
                     break;
