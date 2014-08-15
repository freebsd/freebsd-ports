--- unzip.c.orig	2009-04-16 18:26:52 UTC
+++ unzip.c
@@ -664,7 +664,8 @@ modifiers:\n\
   -j  junk paths (do not make directories)   -aa treat ALL files as text\n\
   -U  use escapes for all non-ASCII Unicode  -UU ignore any Unicode fields\n\
   -C  match filenames case-insensitively     -L  make (some) names \
-lowercase\n %-42s  -V  retain VMS version numbers\n%s";
+lowercase\n %-42s  -V  retain VMS version numbers\n\
+                                             -.  don't translate filenames\n%s";
 #else /* !VMS */
 static ZCONST char Far UnzipUsageLine4[] = "\
 modifiers:\n\
@@ -1829,6 +1830,12 @@ int uz_opts(__G__ pargc, pargv)
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
