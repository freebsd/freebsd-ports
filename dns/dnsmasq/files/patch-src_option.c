--- src/option.c.orig	2015-07-30 19:59:07 UTC
+++ src/option.c
@@ -1501,10 +1501,16 @@ static int one_opt(int option, char *arg
 		li = opt_malloc(sizeof(struct list));
 		if (*arg == '*')
 		  {
-		    li->next = match_suffix;
-		    match_suffix = li;
-		    /* Have to copy: buffer is overwritten */
-		    li->suffix = opt_string_alloc(arg+1);
+		    /* "*" with no suffix is a no-op */
+		    if (arg[1] == 0)
+		      free(li);
+		    else
+		      {
+			li->next = match_suffix;
+			match_suffix = li;
+			/* Have to copy: buffer is overwritten */
+			li->suffix = opt_string_alloc(arg+1);
+		      }
 		  }
 		else
 		  {
