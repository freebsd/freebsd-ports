Index: pcre_compile.c
===================================================================
--- pcre_compile.c	(revision 660)
+++ pcre_compile.c	(revision 661)
@@ -2295,9 +2295,14 @@
 A user pointed out that PCRE was rejecting [:a[:digit:]] whereas Perl was not.
 It seems that the appearance of a nested POSIX class supersedes an apparent
 external class. For example, [:a[:digit:]b:] matches "a", "b", ":", or
-a digit. Also, unescaped square brackets may also appear as part of class
-names. For example, [:a[:abc]b:] gives unknown class "[:abc]b:]"in Perl.
+a digit. 
 
+In Perl, unescaped square brackets may also appear as part of class names. For
+example, [:a[:abc]b:] gives unknown POSIX class "[:abc]b:]". However, for
+[:a[:abc]b][b:] it gives unknown POSIX class "[:abc]b][b:]", which does not
+seem right at all. PCRE does not allow closing square brackets in POSIX class 
+names.
+
 Arguments:
   ptr      pointer to the initial [
   endptr   where to return the end pointer
@@ -2314,6 +2319,7 @@
   {
   if (*ptr == CHAR_BACKSLASH && ptr[1] == CHAR_RIGHT_SQUARE_BRACKET)
     ptr++;
+  else if (*ptr == CHAR_RIGHT_SQUARE_BRACKET) return FALSE;   
   else
     {
     if (*ptr == terminator && ptr[1] == CHAR_RIGHT_SQUARE_BRACKET)
