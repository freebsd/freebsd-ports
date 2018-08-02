main.cc:378:31: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
        fprintf(stderr, "Spellathon "VERSION" (svn%s)    (c)"COPYRIGHT"\n\n"
                                     ^

--- src/cl/main.cc.orig	2018-08-02 06:21:54 UTC
+++ src/cl/main.cc
@@ -375,7 +375,7 @@ static void	
 help(void)
 {
 	const char* svn_version(void);
-	fprintf(stderr, "Spellathon "VERSION" (svn%s)    (c)"COPYRIGHT"\n\n"
+	fprintf(stderr, "Spellathon " VERSION " (svn%s)    (c)" COPYRIGHT "\n\n"
 		"usage: spellathon <option> [sub-options ...]\n\n"
 		"Options:\n"
 		"  -i             -- Game instructions.\n"
