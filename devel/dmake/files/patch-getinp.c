--- getinp.c.orig	Thu Apr 20 22:38:09 2006
+++ getinp.c	Thu Apr 20 22:39:39 2006
@@ -497,7 +497,7 @@
    static short	action[MAX_COND_DEPTH];
    static char		ifcntl[MAX_COND_DEPTH];
    char			*lhs, *expr, *expr_end;
-   char			*lop;
+   const char		*lop;
    int			result;
 
    DB_ENTER( "_handle_conditional" );
