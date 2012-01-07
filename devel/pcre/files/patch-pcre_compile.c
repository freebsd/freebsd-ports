--- pcre_compile.c	2011/12/15 11:57:39	806
+++ pcre_compile.c	2011/12/18 10:03:38	807
@@ -1655,7 +1655,8 @@
     case OP_ASSERTBACK:
     case OP_ASSERTBACK_NOT:
     do cc += GET(cc, 1); while (*cc == OP_ALT);
-    /* Fall through */
+    cc += _pcre_OP_lengths[*cc];
+    break;
 
     /* Skip over things that don't match chars */
 
@@ -6450,10 +6451,10 @@
 
         if (ptr[1] != CHAR_PLUS && ptr[1] != CHAR_MINUS)
           {
-          BOOL isnumber = TRUE;
+          BOOL is_a_number = TRUE;
           for (p = ptr + 1; *p != 0 && *p != terminator; p++)
             {
-            if ((cd->ctypes[*p] & ctype_digit) == 0) isnumber = FALSE;
+            if ((cd->ctypes[*p] & ctype_digit) == 0) is_a_number = FALSE;
             if ((cd->ctypes[*p] & ctype_word) == 0) break;
             }
           if (*p != terminator)
@@ -6461,7 +6462,7 @@
             *errorcodeptr = ERR57;
             break;
             }
-          if (isnumber)
+          if (is_a_number)
             {
             ptr++;
             goto HANDLE_NUMERICAL_RECURSION;
