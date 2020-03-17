--- help.c.orig	2014-11-04 10:25:00 UTC
+++ help.c
@@ -583,7 +583,10 @@ void write_from_msg_file(int *line, int msg_no, 
 char s[512];
 char chr;
 int i,j,k;
-msg_file=fopen(msg_filename, "r");
+char *fn;
+asprintf(&fn, "%s/%s", "%%LOCALBASE%%share/linrad/", msg_filename);
+msg_file=fopen(fn, "r");
+free(fn);
 if(msg_file == NULL)
   {
   sprintf(s,"Could not find %s",msg_filename);
