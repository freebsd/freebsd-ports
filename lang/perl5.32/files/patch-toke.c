--- toke.c.orig	2020-12-18 10:04:36 UTC
+++ toke.c
@@ -3140,8 +3140,8 @@ S_scan_const(pTHX_ char *start)
                  */
                 char * max_ptr;
                 char * min_ptr;
-                IV range_min;
-		IV range_max;	/* last character in range */
+                IVINT range_min;
+                IVINT range_max; /* last character in range */
                 STRLEN grow;
                 Size_t offset_to_min = 0;
                 Size_t extras = 0;
@@ -11455,7 +11455,7 @@ Perl_scan_num(pTHX_ const char *start, YYSTYPE* lvalp)
 	     when in octal mode.
 	   */
 	    NV n = 0.0;
-	    UV u = 0;
+	    UVINT u = 0;
 	    bool overflowed = FALSE;
 	    bool just_zero  = TRUE;	/* just plain 0 or binary number? */
             bool has_digs = FALSE;
@@ -11504,7 +11504,7 @@ Perl_scan_num(pTHX_ const char *start, YYSTYPE* lvalp)
 	    for (;;) {
 		/* x is used in the overflow test,
 		   b is the digit we're adding on. */
-		UV x, b;
+		UVINT x, b;
 
 		switch (*s) {
 
