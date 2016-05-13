--- main.c.orig	2005-01-24 17:05:01 UTC
+++ main.c
@@ -87,7 +87,7 @@ int main(int argc,char **argv)
     wcol= 0;
     for (;;)
     {
-	if (getline(bf[sw], bf[!sw], &wcol, prompt))
+	if (get_line(bf[sw], bf[!sw], &wcol, prompt))
 	{
 	    putchar('\n');
 	    done(RET_ENTER);
