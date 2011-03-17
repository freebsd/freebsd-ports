--- unzip.c.orig	2009-04-17 03:26:52.000000000 +0900
+++ unzip.c	2011-02-15 11:25:36.000000000 +0900
@@ -664,7 +664,8 @@
   -j  junk paths (do not make directories)   -aa treat ALL files as text\n\
   -U  use escapes for all non-ASCII Unicode  -UU ignore any Unicode fields\n\
   -C  match filenames case-insensitively     -L  make (some) names \
-lowercase\n %-42s  -V  retain VMS version numbers\n%s";
+lowercase\n %-42s  -V  retain VMS version numbers\n\
+                                             -.  don't translate filenames\n%s";
 #else /* !VMS */
 static ZCONST char Far UnzipUsageLine4[] = "\
 modifiers:\n\
@@ -1829,6 +1830,12 @@
                         ++uO.cflxflag;
                     break;
 #endif /* UNIX */
+                case ('.'):
+                    if (negative)
+                        uO.dotflag = FALSE, negative = 0;
+                    else
+                        uO.dotflag = TRUE;
+                    break;
                 default:
                     error = TRUE;
                     break;
