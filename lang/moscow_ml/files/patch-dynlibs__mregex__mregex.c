--- dynlibs/mregex/mregex.c.orig	Fri Feb  6 13:35:06 2004
+++ dynlibs/mregex/mregex.c	Fri Feb  6 13:45:45 2004
@@ -7,7 +7,7 @@
 
 #include <stdlib.h>
 #include <sys/types.h>
-#include "regex-0.12/regex.h"
+#include <regex.h>
 
 /* Moscow ML specific includes: */
 
@@ -17,10 +17,6 @@
 #include <str.h>		/* For string_length                       */
 #include <fail.h>		/* For failwith                            */
 
-/* Special version of regexec, defined at the end of this file */
-
-int mosml_regexec();
-
 #ifdef WIN32
 #define EXTERNML __declspec(dllexport)
 #else
@@ -135,8 +131,7 @@
 value regmatch_sus(regex_t* preg, int nmatch, regmatch_t pmatch[], 
 		   int eflags, value susval) {
   char* str = susaddr_susval(susval);
-  int len = len_susval(susval);
-  int matcherror = mosml_regexec(preg, str, len, nmatch, pmatch, eflags);
+  int matcherror = regexec(preg, str, nmatch, pmatch, eflags);
   if (matcherror == 0) {
     /* Find actual number of named substrings */
     value res;
@@ -208,8 +203,7 @@
 
 value regmatch_bool(regex_t* preg, int eflags, value susval) {
   char* str = susaddr_susval(susval);
-  int len = len_susval(susval);
-  int matcherror = mosml_regexec(preg, str, len, 0, NULL, eflags | REG_NOSUB);
+  int matcherror = regexec(preg, str, 0, NULL, eflags);
   return Val_bool(matcherror == 0);
 }
 
@@ -278,86 +272,4 @@
   }
   /* Unreachable: */
   return Val_false;
-}
-
-/* This is copied from GNU regex-0.12 file regex.c, and renamed from
-   regexec to mosml_regexec.  The only change is that mosml_regexec
-   receives the (sub)string's length as an argument, and so avoids
-   calling strlen.  This dramatically speeds up the replace,
-   substitute, tokens, and fields functions in the Regex ML structure:
-   the asymptotic execution time changes from quadratic to linear.
-
-   It is pretty silly to have to copy the entire function just to
-   achieve this.  Superficially, the fault is with POSIX 1003.2 for
-   not accommodating searches in substrings of long strings.  More
-   fundamentally, C's notion of null-terminated string is lame: taking
-   time O(n) to determine the length of a string is damn poor.
-   
-   sestoft@dina.kvl.dk 
-*/
-
-typedef char boolean;
-#define false 0
-#define true 1
-#define TALLOC(n, t) ((t *) malloc ((n) * sizeof (t)))
-
-int
-mosml_regexec (preg, string, len /* NEW */, nmatch, pmatch, eflags)
-    const regex_t *preg;
-    const char *string; 
-    int len;			/* NEW */
-    size_t nmatch; 
-    regmatch_t pmatch[]; 
-    int eflags;
-{
-  int ret;
-  struct re_registers regs;
-  regex_t private_preg;
-  boolean want_reg_info = !preg->no_sub && nmatch > 0;
-
-  private_preg = *preg;
-  
-  private_preg.not_bol = !!(eflags & REG_NOTBOL);
-  private_preg.not_eol = !!(eflags & REG_NOTEOL);
-  
-  /* The user has told us exactly how many registers to return
-     information about, via `nmatch'.  We have to pass that on to the
-     matching routines.  */
-  private_preg.regs_allocated = REGS_FIXED;
-  
-  if (want_reg_info)
-    {
-      regs.num_regs = nmatch;
-      regs.start = TALLOC (nmatch, regoff_t);
-      regs.end = TALLOC (nmatch, regoff_t);
-      if (regs.start == NULL || regs.end == NULL)
-        return (int) REG_NOMATCH;
-    }
-
-  /* Perform the searching operation.  */
-  ret = re_search (&private_preg, string, len,
-                   /* start: */ 0, /* range: */ len,
-                   want_reg_info ? &regs : (struct re_registers *) 0);
-  
-  /* Copy the register information to the POSIX structure.  */
-  if (want_reg_info)
-    {
-      if (ret >= 0)
-        {
-          unsigned r;
-
-          for (r = 0; r < nmatch; r++)
-            {
-              pmatch[r].rm_so = regs.start[r];
-              pmatch[r].rm_eo = regs.end[r];
-            }
-        }
-
-      /* If we needed the temporary register info, free the space now.  */
-      free (regs.start);
-      free (regs.end);
-    }
-
-  /* We want zero return to mean success, unlike `re_search'.  */
-  return ret >= 0 ? (int) REG_NOERROR : (int) REG_NOMATCH;
 }
