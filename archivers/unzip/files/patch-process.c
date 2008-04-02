--- unzip-5.52.orig/process.c
+++ process.c
@@ -74,20 +74,20 @@
    /* do_seekable() strings */
 # ifdef UNIX
    static ZCONST char Far CannotFindZipfileDirMsg[] =
-     "%s:  cannot find zipfile directory in one of %s or\n\
-        %s%s.zip, and cannot find %s, period.\n";
+     "%s:  cannot find zipfile directory in one of %.512s or\n\
+        %s%.512s.zip, and cannot find %.512s, period.\n";
    static ZCONST char Far CannotFindEitherZipfile[] =
-     "%s:  cannot find or open %s, %s.zip or %s.\n";
+     "%s:  cannot find or open %.512s, %.512s.zip or %.512s.\n";
 # else /* !UNIX */
 # ifndef AMIGA
    static ZCONST char Far CannotFindWildcardMatch[] =
-     "%s:  cannot find any matches for wildcard specification \"%s\".\n";
+     "%s:  cannot find any matches for wildcard specification \"%.512s\".\n";
 # endif /* !AMIGA */
    static ZCONST char Far CannotFindZipfileDirMsg[] =
-     "%s:  cannot find zipfile directory in %s,\n\
-        %sand cannot find %s, period.\n";
+     "%s:  cannot find zipfile directory in %.512s,\n\
+        %sand cannot find %.512s, period.\n";
    static ZCONST char Far CannotFindEitherZipfile[] =
-     "%s:  cannot find either %s or %s.\n";
+     "%s:  cannot find either %.512s or %.512s.\n";
 # endif /* ?UNIX */
    extern ZCONST char Far Zipnfo[];       /* in unzip.c */
 #ifndef WINDLL
