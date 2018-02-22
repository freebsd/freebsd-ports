--- rts/Linker.c.orig	2017-08-12 09:22:13 UTC
+++ rts/Linker.c
@@ -797,7 +797,7 @@ initLinker_ (int retain_cafs)
 #   endif /* RTLD_DEFAULT */
 
     compileResult = regcomp(&re_invalid,
-           "(([^ \t()])+\\.so([^ \t:()])*):([ \t])*(invalid ELF header|file too short)",
+           "(([^ \t()])+\\.so([^ \t:()])*):([ \t])*(invalid ELF header|file too short|invalid file format)",
            REG_EXTENDED);
     if (compileResult != 0) {
         barf("Compiling re_invalid failed");
