--- src/misc/load.c~
+++ src/misc/load.c
@@ -99,8 +99,11 @@ static int decrunch(struct xmp_context *
 	cmd = "unzip -pqqC \"%s\" -x readme *.diz *.nfo *.txt *.exe *.com "
 		"README *.DIZ *.NFO *.TXT *.EXE *.COM " REDIR_STDERR;
 #else
-	cmd = "unzip -pqqC \"%s\" -x readme '*.diz' '*.nfo' '*.txt' '*.exe' "
-		"'*.com' README '*.DIZ' '*.NFO' '*.TXT' '*.EXE' '*.COM' "
+	cmd = "bsdtar xOf \"%s\" --exclude readme --exclude '*.diz' "
+		"--exclude '*.nfo' --exclude '*.txt' --exclude '*.exe' "
+		"--exclude '*.com' --exclude  README --exclude '*.DIZ' "
+		"--exclude '*.NFO' --exclude '*.TXT' --exclude '*.EXE' "
+		"--exclude '*.COM' "
 		REDIR_STDERR;
 #endif
     } else if (b[2] == '-' && b[3] == 'l' && b[4] == 'h') {
